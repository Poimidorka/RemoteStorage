cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Connection/Connection.cpp Connection/Connection.h Storages/StorageInterface.h Storages/ByteStorage.cpp Storages/ByteStorage.h)
