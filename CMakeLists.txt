PROJECT(EmscriptenTest)

ADD_SUBDIRECTORY(MorseCodeConverter)

OPTION (BUILD_FOR_EMSCRIPTEN ON CACHE BOOL "Build to support Emscripten configuration (VS2010)")
IF (NOT BUILD_FOR_EMSCRIPTEN)
  ADD_SUBDIRECTORY(TestConversion)
ENDIF (NOT BUILD_FOR_EMSCRIPTEN)
