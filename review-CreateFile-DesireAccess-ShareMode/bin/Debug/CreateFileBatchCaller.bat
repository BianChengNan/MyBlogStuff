@echo off
cd /d %~dp0

setlocal enabledelayedexpansion

set AccessParams=%1%
set AccessParams=%AccessParams:read=Read%
set AccessParams=%AccessParams:write=Write%
set AccessParams=%AccessParams:none=None%

For /f "tokens=1-4 delims=-/. " %%i In ("%AccessParams%") do (
	set Access1=%%i
	set SharedAccess1=%%j
	set Access2=%%k
	set SharedAccess2=%%l
)

start CreateFile -f test.txt -a %Access1% -s %SharedAccess1%

:: will this success?
timeout /T 1
start CreateFile -f test.txt -a %Access2% -s %SharedAccess2%
