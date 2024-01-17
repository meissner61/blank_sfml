title %cd%

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"

::INCLUDE DIRECTORIES
set SFML="C:\libs\SFML-2.5.1-windows-vc15-32-bit\SFML-2.5.1\include"

::LIBRARY DIRECTORIES
set SFML_lib="C:\libs\SFML-2.5.1-windows-vc15-32-bit\SFML-2.5.1\lib"



call cl ../src/*.cpp /std:c++17 /EHsc -W4 -I%SFML% -link -LIBPATH:%SFML_lib% sfml-graphics.lib sfml-audio.lib sfml-network.lib sfml-window.lib sfml-system.lib user32.lib shell32.lib /SUBSYSTEM:CONSOLE /out:../bin/main.exe

