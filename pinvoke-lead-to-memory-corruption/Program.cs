using System;
using System.Runtime.InteropServices;
namespace ConsoleApplication1
{
    class Program
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct MemoryStatus
        {
            [MarshalAs(UnmanagedType.U4)]
            public uint dwLength;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwMemoryLoad;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwTotalPhys;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwAvailPhys;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwTotalPageFile;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwAvailPageFile;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwTotalVirtual;
            [MarshalAs(UnmanagedType.U4)]
            public uint dwAvailVirtual;
        }

        [DllImport("kernel32.dll")]
        public static extern void GlobalMemoryStatus(ref MemoryStatus memoryStatus);
        class CMyClass
        {
            public int n1 = 0;
        }
        struct CMyStruct
        {
            public CMyClass data;
        }
        static void Main(string[] args)
        {
            CMyStruct myObj = new CMyStruct(); myObj.data = new CMyClass();
            MemoryStatus memoryStatus = new MemoryStatus();
            // this line will corrupt the stack if we run in x64.
            // because memoryStatus is defined on the stack.
            GlobalMemoryStatus(ref memoryStatus);
            // myObj.data is corrupted
            System.Console.WriteLine("{0}", myObj.data);
        }
    }
}