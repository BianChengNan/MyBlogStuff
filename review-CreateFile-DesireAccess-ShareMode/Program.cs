using System;
using System.Collections.Generic;
using System.CommandLine;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreateFile
{
    class Program
    {
        // ref https://learn.microsoft.com/en-us/dotnet/standard/commandline/define-commands
        static Command SetupCommandHandler()
        {
            var filePathOption = new Option<string>(name: "--path", getDefaultValue: () => "test.txt", description: "file path");
            filePathOption.AddAlias("-f");
            filePathOption.AddAlias("-p");

            var fileModeOption = new Option<string>(name: "--mode", getDefaultValue: () => "Open", description: "file mode")
                .FromAmong("CreateNew", "Create", "Open", "OpenOrCreate", "Truncate", "Append");
            fileModeOption.AddAlias("-m");

            var fileShareOption = new Option<string>("--share", "file share") { IsRequired = true }
                .FromAmong("None", "Read", "Write", "ReadWrite", "Delete", "Inheritable");
            fileShareOption.AddAlias("-s");

            var fileAccessOption = new Option<string>("--access", "file access") { IsRequired = true }
                .FromAmong("Read", "Write", "ReadWrite");
            fileAccessOption.AddAlias("-a");

            var autoQuitOption = new Option<bool>(name: "--autoquit", getDefaultValue: () => false, description: "auto quit");
            autoQuitOption.AddAlias("-q");

            var command = new RootCommand();
            command.Add(filePathOption);
            command.Add(fileModeOption);
            command.Add(fileShareOption);
            command.Add(fileAccessOption);
            command.Add(autoQuitOption);

            command.SetHandler((filePath, fileMode, fileShare, fileAccess, autoQuit) =>
            {
                OpenFileAndWait(filePath, fileMode, fileShare, fileAccess, autoQuit);
            }, filePathOption, fileModeOption, fileShareOption, fileAccessOption, autoQuitOption);

            return command;
        }

        static void Main(string[] args)
        {
            var command = SetupCommandHandler();
            command.Invoke(args);
        }

        static void OpenFileAndWait(string strFilePath, string strFileMode, string strFileShare, string strFileAccess, bool autoQuit)
        {
            FileStream stream = null;
            try
            {
                var fileMode = (FileMode)System.Enum.Parse(typeof(FileMode), strFileMode);
                var fileShare = (FileShare)System.Enum.Parse(typeof(FileShare), strFileShare);
                var fileAccess = (FileAccess)System.Enum.Parse(typeof(FileAccess), strFileAccess);

                System.Console.WriteLine(string.Format("[{0}] file:{1}, mode: {2}, access: {3}, share: {4}!"
                  , System.DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"), strFilePath, strFileMode, strFileAccess, strFileShare));

                stream = File.Open(strFilePath, fileMode, fileAccess, fileShare);
            }
            catch (Exception ex)
            {
                System.Console.WriteLine(string.Format("opening file [{0}] failed with {1}!", strFilePath, ex));
            }

            if (!autoQuit)
            {
                System.Console.WriteLine("press any key to continue...");
                System.Console.ReadKey();
            }

            if (stream != null)
            {
                stream.Dispose();
            }
        }
    }
}
