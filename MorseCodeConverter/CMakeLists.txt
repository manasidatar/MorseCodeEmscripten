ADD_DEFINITIONS(-DMORSECODECONVERTER_EXPORTS)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# Dll for Morse code conversion
SET(MorseCodeConverter_SRC
  MorseCodeConverter.h
  MorseCodeConverter.cpp
  # MorseCodeConverterAPI.h
  # MorseCodeConverterAPI.cpp
  )
  
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
ADD_LIBRARY(MorseCodeConverter SHARED ${MorseCodeConverter_SRC})
