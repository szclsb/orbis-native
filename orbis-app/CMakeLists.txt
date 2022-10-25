set(APP ${PROJECT_NAME}_app)
set(SOURCE_FILES
        main.cpp
        )

find_library(${PROJECT_NAME} PUBLIC)

add_executable(${APP} ${SOURCE_FILES})
target_include_directories(${APP} PUBLIC include ../orbis/include)
target_link_libraries(${APP} PUBLIC ${PROJECT_NAME})