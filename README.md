# MorseCodeEmscripten
simple Morse code converter to experiment with Emscripten and C++

Use the CMake flag "BUILD_FOR_EMSCRIPTEN" to switch between JS and EXE targets.
Build EXE using CMake and your favorite compiler.
Build JS target using the following Emscripten command:
<code>emcc --bind -o MorseCodeConverter.js MorseCodeConverter/MorseCodeConverter.cpp</code>
