cmake_minimum_required(VERSION 3.10)
project(Chess-Interface)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 
  COMPONENTS 
    system window graphics network audio REQUIRED)

set(SOURCES
        board.h
        board.cpp
        chessGame.h
        chessGame.cpp
        piece.h
        piece.cpp
        pieceTexture.h
        pieceTexture.cpp
        Source.cpp
        subprocess/subproc_lib.h
        subprocess/Subprocess.h
)

add_executable(Chess-Interface ${SOURCES})

target_link_libraries(Chess-Interface sfml-graphics)

