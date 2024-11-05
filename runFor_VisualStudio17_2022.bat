mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release --target Graphics
xcopy /y "../SFML-2.3.2/lib/win/bin" "./Release"
cd Release
Graphics.exe
