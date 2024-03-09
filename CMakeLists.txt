cmake_minimum_required(VERSION 3.28)
project(LogicLang)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(src DIR_SRCS)
add_executable(lgcc ${DIR_SRCS})