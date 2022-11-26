set(SOURCE_FILES
        orbis.cpp
        )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include ../../GLFW/include ${PROJECT_BINARY_DIR}/GLAD/include)
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32 GLFW/src/glfw3 GLAD/glad)