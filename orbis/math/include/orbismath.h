#pragma once

#include <Eigen>

#ifdef ORBIS_EXPORTS
#define ORBIS_API  __declspec(dllexport)   // export DLL information
#else
#define ORBIS_API  __declspec(dllimport)   // import DLL information
#endif

namespace orbis::math {
    typedef Eigen::Vector2f Vec2f;
    typedef Eigen::Vector3f Vec3f;
    typedef Eigen::Vector4f Vec4f;

    typedef Eigen::Matrix2f Mat2f;
    typedef Eigen::Matrix3f Mat3f;
    typedef Eigen::Matrix4f Mat4f;

    ORBIS_API void vec2fSet(Vec2f*A, float x, float y);

    ORBIS_API void vec2fAdd(const Vec2f *A, const Vec2f *B, Vec2f *R);

    ORBIS_API void vec2fSub(const Vec2f *A, const Vec2f *B, Vec2f *R);

    ORBIS_API void vec2fScale(const Vec2f *A, const float *s, Vec2f *R);

    ORBIS_API void vec2fDot(const Vec2f *A, const Vec2f *B, float *r);
//    ORBIS_API void vec2fCross(const Vec2f* A, const Vec2f* B, Vec2f* R);
    ORBIS_API void vec2fNorm(const Vec2f *A, float *r);

    ORBIS_API void vec2fNormSquared(const Vec2f *A, float *r);

    ORBIS_API void vec3fSet(Vec3f* A, float x, float y, float z);

    ORBIS_API void vec3fAdd(const Vec3f *A, const Vec3f *B, Vec3f *R);

    ORBIS_API void vec3fSub(const Vec3f *A, const Vec3f *B, Vec3f *R);

    ORBIS_API void vec3fScale(const Vec3f *A, const float *s, Vec3f *R);

    ORBIS_API void vec3fDot(const Vec3f *A, const Vec3f *B, float *r);

    ORBIS_API void vec3fCross(const Vec3f *A, const Vec3f *B, Vec3f *R);

    ORBIS_API void vec3fNorm(const Vec3f *A, float *r);

    ORBIS_API void vec3fNormSquared(const Vec3f *A, float *r);

    ORBIS_API void vec4fSet(Vec4f* A, float x, float y, float z, float w);

    ORBIS_API void vec4fAdd(const Vec4f *A, const Vec4f *B, Vec4f *R);

    ORBIS_API void vec4fSub(const Vec4f *A, const Vec4f *B, Vec4f *R);

    ORBIS_API void vec4fScale(const Vec4f *A, const float *s, Vec4f *R);

    ORBIS_API void vec4fDot(const Vec4f *A, const Vec4f *B, float *r);
//    ORBIS_API void vec4fCross(const float* A, const float* B, float* R);
    ORBIS_API void vec4fNorm(const Vec4f *A, float *r);

    ORBIS_API void vec4fNormSquared(const Vec4f *A, float *r);


    ORBIS_API void mat2fSet(Mat2f *A,
                               float m11, float m12,
                               float m21, float m22);

    ORBIS_API void mat2fAdd(const Mat2f *A, const Mat2f *B, Mat2f *R);

    ORBIS_API void mat2fSub(const Mat2f *A, const Mat2f *B, Mat2f *R);

    ORBIS_API void mat2fScale(const Mat2f *A, const float *s, Mat2f *R);

    ORBIS_API void mat2fMultiply(const Mat2f *A, const Mat2f *B, Mat2f *R);

    ORBIS_API void mat2fMultiplyV(const Mat2f *A, const Vec2f *B, Vec2f *R);

    ORBIS_API void mat2fPower(const Mat2f *A, const int *exp, Mat2f *R);

    ORBIS_API void mat2fDeterminant(const Mat2f *A, float *det);

    ORBIS_API void mat2fTranspose(const Mat2f *A, Mat2f *R);

    ORBIS_API void mat2fInverse(const Mat2f *A, Mat2f *R);

    ORBIS_API void mat3Set(Mat3f *A,
                                 float m11, float m12, float m13,
                                 float m21, float m22, float m23,
                                 float m31, float m32, float m33);

    ORBIS_API void mat3fAdd(const Mat3f *A, const Mat3f *B, Mat3f *R);

    ORBIS_API void mat3fSub(const Mat3f *A, const Mat3f *B, Mat3f *R);

    ORBIS_API void mat3fScale(const Mat3f *A, const float *s, Mat3f *R);

    ORBIS_API void mat3fMultiply(const Mat3f *A, const Mat3f *B, Mat3f *R);

    ORBIS_API void mat3fMultiplyV(const Mat3f *A, const Vec3f *B, Vec3f *R);

    ORBIS_API void mat3fPower(const Mat3f *A, const int *exp, Mat3f *R);

    ORBIS_API void mat3fDeterminant(const Mat3f *A, float *det);

    ORBIS_API void mat3fTranspose(const Mat3f *A, Mat3f *R);

    ORBIS_API void mat3fInverse(const Mat3f *A, Mat3f *R);

    ORBIS_API void mat4fSet(Mat4f *A,
                            float m11, float m12, float m13, float m14,
                            float m21, float m22, float m23, float m24,
                            float m31, float m32, float m33, float m34,
                            float m41, float m42, float m43, float m44);

    ORBIS_API void mat4fAdd(const Mat4f *A, const Mat4f *B, Mat4f *R);

    ORBIS_API void mat4fSub(const Mat4f *A, const Mat4f *B, Mat4f *R);

    ORBIS_API void mat4fScale(const Mat4f *A, const float *s, Mat4f *R);

    ORBIS_API void mat4fMultiply(const Mat4f *A, const Mat4f *B, Mat4f *R);

    ORBIS_API void mat4fMultiplyV(const Mat4f *A, const Vec4f *B, Vec4f *R);

    ORBIS_API void mat4fPower(const Mat4f *A, const int *exp, Mat4f *R);

    ORBIS_API void mat4fDeterminant(const Mat4f *A, float *det);

    ORBIS_API void mat4fTranspose(const Mat4f *A, Mat4f *R);

    ORBIS_API void mat4fInverse(const Mat4f *A, Mat4f *R);
}