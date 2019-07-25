@echo OFF

call %0\..\SetupVSEnvironment.bat

if not defined ATOMIC_CMAKE_GENERATOR (
  @echo Problem setting up Visual Studio compilation environment
  exit
)

@echo OFF

echo VS Environment setup finished !
echo %1
echo %2
echo %3

set ATOMIC_ROOT=%~1
set ATOMIC_SOLUTION_PATH=%~2
set ATOMIC_CMAKE_FLAGS="%3"

%ATOMIC_CMAKE% -E make_directory "%ATOMIC_SOLUTION_PATH%"
%ATOMIC_CMAKE% -E chdir "%ATOMIC_SOLUTION_PATH%" %ATOMIC_CMAKE% "%ATOMIC_ROOT% " %ATOMIC_CMAKE_FLAGS% -G %ATOMIC_CMAKE_GENERATOR% -A x64
