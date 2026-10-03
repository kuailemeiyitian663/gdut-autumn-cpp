@echo off
rem ---- GDUT C++ exam demos: compile & run all 8 files ----
where g++ >nul 2>nul
if errorlevel 1 (
  echo [X] g++ not found in PATH.
  echo     Install a free compiler first, then re-run this file.
  echo     See README.md section "How to compile" for 3 free options.
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
  g++ -std=c++11 -Wall -o "%OUT_DIR%\%%~nf.exe" "%%f"
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
