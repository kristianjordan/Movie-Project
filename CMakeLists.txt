CMAKE_MINIMUM_REQUIRED(VERSION 2.0)

SET(CMAKE_CSS_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(mock_main
	./mock_files/mock_main.cpp
)

ADD_EXECUTABLE(test
	unit_test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
