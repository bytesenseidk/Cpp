cmake_minimum_required(VERSION 3.20)
project(EnhancedUserSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(UserSystem ../src/Source/main.cpp ../src/Source/Encryption.cpp ../src/Header/Encryption.h ../src/Source/UserPage.cpp ../src/Header/UserPage.h ../src/Source/ProfileData.cpp ../src/Header/ProfileData.h)
