rem Build solution and run Lunar.exe using MSBuild
call vsdevcmd
call msbuild Solar.sln
call .\Lunar\bin\x64\Debug\Lunar.exe