#include "include/orbismath.h"
#include <cmath>

void orbis::math::vec2fSet(Vec2f *A, float x, float y) {
    *A << x, y;
}

void orbis::math::vec2fAdd(const Vec2f *A, const Vec2f *B, Vec2f *R) {
    *R = *A + *B;
}

void orbis::math::vec2fSub(const Vec2f *A, const Vec2f *B, Vec2f *R) {
    *R = *A - *B;
}

void orbis::math::vec2fScale(const Vec2f *A, const float *s, Vec2f *R) {
    *R = *A * *s;
}

void orbis::math::vec2fDot(const Vec2f *A, const Vec2f *B, float *r) {
    *r = A->dot(*B);
}

void orbis::math::vec2fNorm(const Vec2f *A, float *r) {
    *r = A->norm();
}

void orbis::math::vec2fNormSquared(const Vec2f *A, float *r) {
    *r = A->squaredNorm();
}

void orbis::math::vec3fSet(Vec3f *A, float x, float y, float z) {
    *A << x, y, z;
}

void orbis::math::vec3fAdd(const Vec3f *A, const Vec3f *B, Vec3f *R) {
    *R = *A + *B;
}

void orbis::math::vec3fSub(const Vec3f *A, const Vec3f *B, Vec3f *R) {
    *R = *A - *B;
}

void orbis::math::vec3fScale(const Vec3f *A, const float *s, Vec3f *R) {
    *R = *A * *s;
}

void orbis::math::vec3fDot(const Vec3f *A, const Vec3f *B, float *r) {
    *r = A->dot(*B);
}

void orbis::math::vec3fCross(const Vec3f *A, const Vec3f *B, Vec3f *R) {
    *R = A->cross(*B);
}

void orbis::math::vec3fNorm(const Vec3f *A, float *r) {
    *r = A->norm();
}

void orbis::math::vec3fNormSquared(const Vec3f *A, float *r) {
    *r = A->squaredNorm();
}

void orbis::math::vec4fSet(Vec4f *A, float x, float y, float z, float w) {
    *A << x, y, z, w;
}

void orbis::math::vec4fAdd(const Vec4f *A, const Vec4f *B, Vec4f *R) {
    *R = *A + *B;
}

void orbis::math::vec4fSub(const Vec4f *A, const Vec4f *B, Vec4f *R) {
    *R = *A - *B;
}

void orbis::math::vec4fScale(const Vec4f *A, const float *s, Vec4f *R) {
    *R = *A * *s;
}

void orbis::math::vec4fDot(const Vec4f *A, const Vec4f *B, float *r) {
    *r = A->dot(*B);
}

void orbis::math::vec4fNorm(const Vec4f *A, float *r) {
    *r = A->norm();
}

void orbis::math::vec4fNormSquared(const Vec4f *A, float *r) {
    *r = A->squaredNorm();
}


void orbis::math::mat2fSet(Mat2f *A,
                           float m11, float m12,
                           float m21, float m22) {
    *A << m11, m12,
            m21, m22;
}

void orbis::math::mat2fAdd(const Mat2f *A, const Mat2f *B, Mat2f *R) {
    *R = *A + *B;
}

void orbis::math::mat2fSub(const Mat2f *A, const Mat2f *B, Mat2f *R) {
    *R = *A - *B;
}

void orbis::math::mat2fScale(const Mat2f *A, const float *s, Mat2f *R) {
    *R = *A * *s;
}

void orbis::math::mat2fMultiply(const Mat2f *A, const Mat2f *B, Mat2f *R) {
    *R = *A * *B;
}

void orbis::math::mat2fMultiplyV(const Mat2f *A, const Vec2f *B, Vec2f *R) {
    *R = *A * *B;
}

void orbis::math::mat2fPower(const Mat2f *A, const int *exp, Mat2f *R) {
    //fixme
}

void orbis::math::mat2fDeterminant(const Mat2f *A, float *r) {
    *r = A->determinant();
}

void orbis::math::mat2fTranspose(const Mat2f *A, Mat2f *R) {
    *R = A->transpose();
}

void orbis::math::mat2fInverse(const Mat2f *A, Mat2f *R) {
    *R = A->inverse();
}

void orbis::math::mat3Set(Mat3f *A,
                          float m11, float m12, float m13,
                          float m21, float m22, float m23,
                          float m31, float m32, float m33) {
    *A << m11, m12, m13,
            m21, m22, m23,
            m31, m32, m33;
}
void orbis::math::mat3fAdd(const Mat3f *A, const Mat3f *B, Mat3f *R) {
    *R = *A + *B;
}

void orbis::math::mat3fSub(const Mat3f *A, const Mat3f *B, Mat3f *R) {
    *R = *A - *B;
}

void orbis::math::mat3fScale(const Mat3f *A, const float* s, Mat3f *R) {
    *R = *A * *s;
}

void orbis::math::mat3fMultiply(const Mat3f *A, const Mat3f *B, Mat3f *R) {
    *R = *A * *B;
}

void orbis::math::mat3fMultiplyV(const Mat3f *A, const Vec3f *B, Vec3f *R) {
    *R = *A * *B;
}

void orbis::math::mat3fPower(const Mat3f *A, const int *exp, Mat3f *R) {
    //fixme
}

void orbis::math::mat3fDeterminant(const Mat3f *A, float *det) {
    *det = A->determinant();
}

void orbis::math::mat3fTranspose(const Mat3f *A, Mat3f *R) {
    *R = A->transpose();
}

void orbis::math::mat3fInverse(const Mat3f *A, Mat3f *R) {
    *R = A->inverse();
}

void orbis::math::mat4fSet(Mat4f *A,
                           float m11, float m12, float m13, float m14,
                           float m21, float m22, float m23, float m24,
                           float m31, float m32, float m33, float m34,
                           float m41, float m42, float m43, float m44) {
    *A << m11, m12, m13, m14,
            m21, m22, m23, m24,
            m31, m32, m33, m34,
            m41, m42, m43, m44;
}

void orbis::math::mat4fAdd(const Mat4f *A, const Mat4f *B, Mat4f *R) {
    *R = *A + *B;
}

void orbis::math::mat4fSub(const Mat4f *A, const Mat4f *B, Mat4f *R) {
    *R = *A - *B;
}

void orbis::math::mat4fScale(const Mat4f *A, const float *s, Mat4f *R) {
    *R = *A * *s;
}

void orbis::math::mat4fMultiply(const Mat4f *A, const Mat4f *B, Mat4f *R) {
    *R = *A * *B;
}

void orbis::math::mat4fMultiplyV(const Mat4f *A, const Vec4f *B, Vec4f *R) {
    *R = *A * *B;
}

void orbis::math::mat4fPower(const Mat4f *A, const int *exp, Mat4f *R) {
//    matrixPower(DIM4, A, exp, R);  fixme
}

void orbis::math::mat4fDeterminant(const Mat4f *A, float *det) {
    *det = A->determinant();
}

void orbis::math::mat4fTranspose(const Mat4f *A, Mat4f *R) {
    *R = A->transpose();
}

void orbis::math::mat4fInverse(const Mat4f *A, Mat4f *R) {
    *R = A->inverse();
}
