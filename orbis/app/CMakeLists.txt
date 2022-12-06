set(APP ${PROJECT_NAME}_app)
set(SOURCE_FILES
        main.cpp
        )

add_executable(${APP} ${SOURCE_FILES})
target_include_directories(${APP} PUBLIC include ../graphic/include ../math/include)
target_link_libraries(${APP} PUBLIC ${PROJECT_NAME}_graphic ${PROJECT_NAME}_math)