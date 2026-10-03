@echo off
rem ---- GDUT C++ exam demos: compile & run all 8 files ----
rem 本机已装 TDM-GCC：D:\TDM-GCC\bin\g++.exe (gcc 10.3.0)
rem 双击本文件时若 PATH 里没有 g++（比如用的是资源管理器直接双击），自动回落到安装目录。
set GXX=g++
where g++ >nul 2>nul
if errorlevel 1 if exist "D:\TDM-GCC\bin\g++.exe" set GXX=D:\TDM-GCC\bin\g++.exe
where "%GXX%" >nul 2>nul
if errorlevel 1 (
  echo [X] g++ not found.
  echo     Install a free compiler first, then re-run this file.
  echo     See README.md section "How to compile" for free options.
  echo     If you already installed TDM-GCC, edit the line above to point at it.
  pause
  exit /b 1
)

set SRC_DIR=%~dp0
set OUT_DIR=%SRC_DIR%build
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

for /r "%SRC_DIR%" %%f in (*.cpp) do (
  echo ============================================================
  echo  COMPILING: %%~nxf
  echo ============================================================
  "%GXX%" -std=c++11 -Wall -o "%OUT_DIR%\%%~nf.exe" "%%f"
  if errorlevel 1 (
    echo [X] Compile FAILED: %%~nxf
  ) else (
    echo ---- RUN OUTPUT ----
    "%OUT_DIR%\%%~nf.exe"
    echo ---- EXIT CODE %errorlevel% ----
  )
  echo.
)

echo All done. Output saved in: %OUT_DIR%
pause
