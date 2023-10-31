add_executable(human-detector-tracker main.cpp post_process.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(human-detector-tracker PUBLIC ${OpenCV_LIBS})