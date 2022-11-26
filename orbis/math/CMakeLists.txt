set(MATH ${PROJECT_NAME}_math)
set(SOURCE_FILES_MATH
        orbismath.cpp
        )

add_library(${MATH} SHARED ${SOURCE_FILES_MATH})
target_include_directories(${MATH} PUBLIC include)