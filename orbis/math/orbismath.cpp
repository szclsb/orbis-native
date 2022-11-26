#include "include/orbismath.h"
#include <cmath>

#define DIM2 2
#define DIM3 3
#define DIM4 4
#define SDIM2 4
#define SDIM3 9
#define SDIM4 16

// todo use SIMD or Eigen

void add(const size_t size, const float* A, const float* B, float* R) {
    for(auto i = 0; i < size; i++) {
        *(R+i) = *(A+i) + *(B+i);
    }
}
void addScalar(const size_t size, const float* A, const float* s, float* R) {
    for(auto i = 0; i < size; i++) {
        *(R+i) = *(A+i) + *s;
    }
}
void sub(const size_t size, const float* A, const float* B, float* R) {
    for(auto i = 0; i < size; i++) {
        *(R+i) = *(A+i) - *(B+i);
    }
}
void subScalar(const size_t size, const float* A, const float* s, float* R) {
    for(auto i = 0; i < size; i++) {
        *(R+i) = *(A+i) + *s;
    }
}
void scale(const size_t size, const float* A, const float* s, float* R) {
    for(auto i = 0; i < size; i++) {
        *(R+i) = *(A+i) * *s;
    }
}
void dot(const size_t size, const float* A, const float* B, float* r) {
    for(auto i = 0; i < size; i++) {
        *r += *(A+i) * *(B+i);
    }
}
void normSquared(const size_t size, const float* A, float* r) {
    for(auto i = 0; i < size; i++) {
        *r += *(A+i) * *(A+i);
    }
}
void norm(const size_t size, const float* A, float* r) {
    for(auto i = 0; i < size; i++) {
        *r += *(A+i) * *(A+i);
    }
    *r = sqrtf(*r);
}
void matrixMultiplication(const size_t dim, const float* A, const float* B, float* R) {
    // todo
}
void matrixVectorMultiplication(const size_t dim, const float* A, const float* B, float* R) {
    // todo
}
void matrixPower(const size_t dim, const float* A, const int* exp, float* R) {
    // todo
}
void matrixDeterminant(const size_t dim, const float* A, float* r) {
    // todo
}
void matrixTranspose(const size_t dim, const float* A, float* R) {
    // todo
}
void matrixInverse(const size_t dim, const float* A, float* R) {
    // todo
}

void orbis::math::vec2fAdd(const float* A, const float* B, float* R) {
    add(DIM2, A, B, R);
}
void orbis::math::vec2fAddScalar(const float* A, const float* s, float* R) {
    addScalar(DIM2, A, s, R);
}
void orbis::math::vec2fSub(const float* A, const float* B, float* R) {
    sub(DIM2, A, B, R);
}
void orbis::math::vec2fSubScalar(const float* A, const float* s, float* R) {
    subScalar(DIM2, A, s, R);
}
void orbis::math::vec2fScale(const float* A, const float* s, float* R) {
    scale(DIM2, A, s, R);
}
void orbis::math::vec2fDot(const float* A, const float* B, float* r) {
    dot(DIM2, A, B, r);
}
void orbis::math::vec2fCross(const float* A, const float* B, float* R) {
    //todo
}
void orbis::math::vec2fNorm(const float* A, float* r) {
    norm(DIM2, A, r);
}
void orbis::math::vec2fNormSquared(const float* A, float* r) {
    normSquared(DIM2, A, r);
}

void orbis::math::vec3fAdd(const float* A, const float* B, float* R) {
    add(DIM3, A, B, R);
}
void orbis::math::vec3fAddScalar(const float* A, const float* s, float* R) {
    addScalar(DIM3, A, s, R);
}
void orbis::math::vec3fSub(const float* A, const float* B, float* R) {
    sub(DIM3, A, B, R);
}
void orbis::math::vec3fSubScalar(const float* A, const float* s, float* R) {
    subScalar(DIM3, A, s, R);
}
void orbis::math::vec3fScale(const float* A, const float* s, float* R) {
    scale(DIM3, A, s, R);
}
void orbis::math::vec3fDot(const float* A, const float* B, float* r) {
    dot(DIM3, A, B, r);
}
void orbis::math::vec3fCross(const float* A, const float* B, float* R) {
    //todo
}
void orbis::math::vec3fNorm(const float* A, float* r) {
    norm(DIM3, A, r);
}
void orbis::math::vec3fNormSquared(const float* A, float* r) {
    normSquared(DIM3, A, r);
}

void orbis::math::vec4fAdd(const float* A, const float* B, float* R) {
    add(DIM4, A, B, R);
}
void orbis::math::vec4fAddScalar(const float* A, const float* s, float* R) {
    addScalar(DIM4, A, s, R);
}
void orbis::math::vec4fSub(const float* A, const float* B, float* R) {
    sub(DIM4, A, B, R);
}
void orbis::math::vec4fSubScalar(const float* A, const float* s, float* R) {
    subScalar(DIM4, A, s, R);
}
void orbis::math::vec4fScale(const float* A, const float* s, float* R) {
    scale(DIM4, A, s, R);
}
void orbis::math::vec4fDot(const float* A, const float* B, float* r) {
    dot(DIM4, A, B, r);
}
//void vec4fCross(const float* A, const float* B, float* R);
void orbis::math::vec4fNorm(const float* A, float* r) {
    norm(DIM4, A, r);
}
void orbis::math::vec4fNormSquared(const float* A, float* r) {
    normSquared(DIM4, A, r);
}



void orbis::math::mat2fAdd(const float* A, const float* B, float* R) {
    add(SDIM2, A, B, R);
}
void orbis::math::mat2fAddScalar(const float* A, const float* s, float* R) {
    addScalar(SDIM2, A, s, R);
}
void orbis::math::mat2fSub(const float* A, const float* B, float* R) {
    sub(SDIM2, A, B, R);
}
void orbis::math::mat2fSubScalar(const float* A, const float* s, float* R) {
    subScalar(SDIM2, A, s, R);
}
void orbis::math::mat2fScale(const float* A, const float* s, float* R) {
    scale(SDIM2, A, s, R);
}
void orbis::math::mat2fMultiply(const float* A, const float* B, float* R) {
    matrixMultiplication(DIM2, A, B, R);
}
void orbis::math::mat2fMultiplyV(const float* A, const float* B, float* R) {
    matrixVectorMultiplication(DIM2, A, B, R);
}
void orbis::math::mat2fPower(const float* A, const int* exp, float* R) {
    matrixPower(DIM2, A, exp, R);
}
void orbis::math::mat2fDeterminant(const float* A, float* r) {
    matrixDeterminant(DIM2, A, r);
}
void orbis::math::mat2fTranspose(const float* A, float* R) {
    matrixTranspose(DIM2, A, R);
}
void orbis::math::mat2fInverse(const float* A, float* R) {
    matrixInverse(DIM2, A, R);
}

void orbis::math::mat3fAdd(const float* A, const float* B, float* R) {
    add(SDIM3, A, B, R);
}
void orbis::math::mat3fAddScalar(const float* A, const float* s, float* R) {
    addScalar(SDIM3, A, s, R);
}
void orbis::math::mat3fSub(const float* A, const float* B, float* R) {
    sub(SDIM3, A, B, R);
}
void orbis::math::mat3fSubScalar(const float* A, const float* s, float* R) {
    subScalar(SDIM3, A, s, R);
}
void orbis::math::mat3fScale(const float* A, const float* s, float* R) {
    scale(SDIM3, A, s, R);
}
void orbis::math::mat3fMultiply(const float* A, const float* B, float* R) {
    matrixMultiplication(DIM3, A, B, R);
}
void orbis::math::mat3fMultiplyV(const float* A, const float* B, float* R) {
    matrixVectorMultiplication(DIM3, A, B, R);
}
void orbis::math::mat3fPower(const float* A, const int* exp, float* R) {
    matrixPower(DIM3, A, exp, R);
}
void orbis::math::mat3fDeterminant(const float* A, float* r) {
    matrixDeterminant(DIM3, A, r);
}
void orbis::math::mat3fTranspose(const float* A, float* R) {
    matrixTranspose(DIM3, A, R);
}
void orbis::math::mat3fInverse(const float* A, float* R) {
    matrixInverse(DIM3, A, R);
}

void orbis::math::mat4fAdd(const float* A, const float* B, float* R) {
    add(SDIM4, A, B, R);
}
void orbis::math::mat4fAddScalar(const float* A, const float* s, float* R) {
    addScalar(SDIM4, A, s, R);
}
void orbis::math::mat4fSub(const float* A, const float* B, float* R) {
    sub(SDIM4, A, B, R);
}
void orbis::math::mat4fSubScalar(const float* A, const float* s, float* R) {
    subScalar(SDIM4, A, s, R);
}
void orbis::math::mat4fScale(const float* A, const float* s, float* R) {
    scale(SDIM4, A, s, R);
}
void orbis::math::mat4fMultiply(const float* A, const float* B, float* R) {
    matrixMultiplication(DIM4, A, B, R);
}
void orbis::math::mat4fMultiplyV(const float* A, const float* B, float* R) {
    matrixVectorMultiplication(DIM4, A, B, R);
}
void orbis::math::mat4fPower(const float* A, const int* exp, float* R) {
    matrixPower(DIM4, A, exp, R);
}
void orbis::math::mat4fDeterminant(const float* A, float* r) {
    matrixDeterminant(DIM4, A, r);
}
void orbis::math::mat4fTranspose(const float* A, float* R) {
    matrixTranspose(DIM4, A, R);
}

void orbis::math::mat4fInverse(const float* A, float* R) {
    matrixInverse(DIM4, A, R);
}
