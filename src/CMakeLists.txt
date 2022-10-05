set(SOURCE_FILES
        main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ../include ../GLFW/include)
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32 GLFW/src/glfw3)
