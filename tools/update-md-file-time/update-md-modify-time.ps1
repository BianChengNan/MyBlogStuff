###############################################################################
#
# all *.md file contains meta data with following format 
#
# ---
# title: xxx
# tags: [xxx]
# categories: [xxx]
# series: xxx
# date: 2023-12-2 15:44:22
# ---
#
# this script will update .md file time by `date:` keyword.
# so that the .md file will be in the right order in explorer 
#
###############################################################################

$curPath = Split-Path -Parent $MyInvocation.MyCommand.Definition
Set-Location $curPath

$result = ""

$allMdFiles = Get-ChildItem -Filter "*.md"
foreach($mdFile in $allMdFiles) {
    
    $fileName = $mdFile.Name

    $strDate = ""
    $contents = Get-Content $mdFile -Encoding UTF8 
    foreach ($line in $contents) {
        if ($line -match "date:\s*(\d{4}-\d{1,2}-\d{1,2}\s+\d{1,2}:\d{1,2}:\d{1,2})")
        {
            $strDate = $Matches[1]
            $result += "`r`n" + $fileName + ',' + $strDate
            break
        }
    }

    if ($strDate -eq "")
    {
        write-host $fileName " no date meta data!!!"
        Read-Host "press any key to continue..."
    }
    else
    {
        $date = Get-Date $strDate -Format "yyyy-MM-dd HH:mm:ss"
        (Get-Item $fileName).LastWriteTime = $date
        (Get-Item $fileName).LastAccessTime = $date
        (Get-Item $fileName).CreationTime = $date
    }
}

# $result | Out-File -FilePath "file_time_result.txt" -Encoding utf8