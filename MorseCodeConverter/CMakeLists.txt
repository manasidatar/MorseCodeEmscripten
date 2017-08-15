INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# Dll for Morse code conversion
ADD_DEFINITIONS(-DMORSECODECONVERTER_EXPORTS)

SET(MorseCodeConverter_SRC
  MorseCodeConverter.h
  MorseCodeConverter.cpp
)
  
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_LIBRARY(MorseCodeConverter SHARED ${MorseCodeConverter_SRC})
