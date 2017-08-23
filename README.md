# MorseCodeEmscripten
simple Morse code converter to experiment with Emscripten and C++

Use the CMake flag "BUILD_FOR_EMSCRIPTEN" to switch between JS and EXE targets.
<ul>
  <li>
    Build EXE using CMake and your favorite compiler.
  </li>
  <li>
    Build JS target using the following Emscripten command:<br>
    <code>emcc --bind -o MorseCodeConverter.js MorseCodeConverter/MorseCodeConverter.cpp</code>
  </li>
</ul>  
