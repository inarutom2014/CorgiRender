@echo off

set CURRENT_DIR=%~dp0
set PROJECT_NAME=build

echo %CURRENT_DIR%%PROJECT_NAME%
if not exist %CURRENT_DIR%%PROJECT_NAME% (
    mkdir %CURRENT_DIR%%PROJECT_NAME%
)

cd %CURRENT_DIR%%PROJECT_NAME%

rem Generate vs2019 project
cmake -G "Visual Studio 16 2019" ..
REM cmake --build . --target Viewer --config Release
pause