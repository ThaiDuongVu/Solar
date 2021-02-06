rem Build solution and run Lunar.exe using MSBuild
call vsdevcmd
call msbuild Solar.sln
call .\Pong\bin\x64\Debug\Pong.exe