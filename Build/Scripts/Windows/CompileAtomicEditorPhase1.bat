@echo OFF

call %0\..\SetupVSEnvironment.bat

if not defined ATOMIC_CMAKE_GENERATOR (
  @echo Problem setting up Visual Studio compilation environment
  exit /b 1
)

set ATOMIC_CMAKE_FLAGS=%2
set ATOMIC_CMAKE_FLAGS=%ATOMIC_CMAKE_FLAGS:\=%
set ATOMIC_CMAKE_FLAGS=%ATOMIC_CMAKE_FLAGS:"=%

%ATOMIC_CMAKE% %0\..\..\..\..\ %ATOMIC_CMAKE_FLAGS% -G %ATOMIC_CMAKE_GENERATOR% -A x64

echo ---------- Atomic Build Phase 1 STARTING ----------

:: Note, we're building LibCpuId as it uses masm as getting XamlFactory load errors if delayed
:: msbuild /m Atomic.sln /t:LibCpuId /t:AtomicNETNative /p:Configuration=%1 /p:Platform=x64
msbuild /m Atomic.sln /t:LibCpuId /p:Configuration=%1 /p:Platform=x64
