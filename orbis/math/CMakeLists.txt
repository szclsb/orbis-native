set(MATH ${PROJECT_NAME}_math)
set(SOURCE_FILES_MATH
        orbismath.cpp
        )

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(${MATH} SHARED ${SOURCE_FILES_MATH})
target_include_directories(${MATH} PUBLIC include ../../Eigen/Eigen)
target_link_libraries(${MATH} PUBLIC Eigen3::Eigen)