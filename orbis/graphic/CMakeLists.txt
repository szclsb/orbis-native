set(GRAPHIC ${PROJECT_NAME}_graphic)
set(SOURCE_FILES
        orbis.cpp
        )

add_library(${GRAPHIC} SHARED ${SOURCE_FILES})
target_include_directories(${GRAPHIC} PUBLIC include ../../GLFW/include ${PROJECT_BINARY_DIR}/GLAD/include)
target_link_libraries(${GRAPHIC} PUBLIC opengl32 GLFW/src/glfw3 GLAD/glad)