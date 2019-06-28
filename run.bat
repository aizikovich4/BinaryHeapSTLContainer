mkdir build
cd build
if errorlevel 1 pause
cmake -G "Visual Studio 15 Win64" .. -DCMAKE_BUILD_TYPE=Debug
if errorlevel 1 pause
cmake --build . --config Debug -- /m:4
if errorlevel 1 pause
cd Debug
BinaryHeapSTLContainer.exe
