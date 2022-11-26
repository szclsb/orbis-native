#pragma once

#ifdef ORBIS_EXPORTS
#define ORBIS_API  __declspec(dllexport)   // export DLL information
#else
#define ORBIS_API  __declspec(dllimport)   // import DLL information
#endif

namespace orbis::math {
    ORBIS_API void vec2fAdd(const float* A, const float* B, float* R);
    ORBIS_API void vec2fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec2fSub(const float* A, const float* B, float* R);
    ORBIS_API void vec2fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec2fScale(const float* A, const float* s, float* R);
    ORBIS_API void vec2fDot(const float* A, const float* B, float* r);
    ORBIS_API void vec2fCross(const float* A, const float* B, float* R);
    ORBIS_API void vec2fNorm(const float* A, float* r);
    ORBIS_API void vec2fNormSquared(const float* A, float* r);

    ORBIS_API void vec3fAdd(const float* A, const float* B, float* R);
    ORBIS_API void vec3fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec3fSub(const float* A, const float* B, float* R);
    ORBIS_API void vec3fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec3fScale(const float* A, const float* s, float* R);
    ORBIS_API void vec3fDot(const float* A, const float* B, float* r);
    ORBIS_API void vec3fCross(const float* A, const float* B, float* R);
    ORBIS_API void vec3fNorm(const float* A, float* r);
    ORBIS_API void vec3fNormSquared(const float* A, float* r);

    ORBIS_API void vec4fAdd(const float* A, const float* B, float* R);
    ORBIS_API void vec4fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec4fSub(const float* A, const float* B, float* R);
    ORBIS_API void vec4fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void vec4fScale(const float* A, const float* s, float* R);
    ORBIS_API void vec4fDot(const float* A, const float* B, float* r);
//    ORBIS_API void vec4fCross(const float* A, const float* B, float* R);
    ORBIS_API void vec4fNorm(const float* A, float* r);
    ORBIS_API void vec4fNormSquared(const float* A, float* r);



    ORBIS_API void mat2fAdd(const float* A, const float* B, float* R);
    ORBIS_API void mat2fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat2fSub(const float* A, const float* B, float* R);
    ORBIS_API void mat2fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat2fScale(const float* A, const float* s, float* R);
    ORBIS_API void mat2fMultiply(const float* A, const float* B, float* R);
    ORBIS_API void mat2fMultiplyV(const float* A, const float* B, float* R);
    ORBIS_API void mat2fPower(const float* A, const int* exp, float* R);
    ORBIS_API void mat2fDeterminant(const float* A, float* r);
    ORBIS_API void mat2fTranspose(const float* A, float* R);
    ORBIS_API void mat2fInverse(const float* A, float* R);

    ORBIS_API void mat3fAdd(const float* A, const float* B, float* R);
    ORBIS_API void mat3fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat3fSub(const float* A, const float* B, float* R);
    ORBIS_API void mat3fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat3fScale(const float* A, const float* s, float* R);
    ORBIS_API void mat3fMultiply(const float* A, const float* B, float* R);
    ORBIS_API void mat3fMultiplyV(const float* A, const float* B, float* R);
    ORBIS_API void mat3fPower(const float* A, const int* exp, float* R);
    ORBIS_API void mat3fDeterminant(const float* A, float* r);
    ORBIS_API void mat3fTranspose(const float* A, float* R);
    ORBIS_API void mat3fInverse(const float* A, float* R);

    ORBIS_API void mat4fAdd(const float* A, const float* B, float* R);
    ORBIS_API void mat4fAddScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat4fSub(const float* A, const float* B, float* R);
    ORBIS_API void mat4fSubScalar(const float* A, const float* s, float* R);
    ORBIS_API void mat4fScale(const float* A, const float* s, float* R);
    ORBIS_API void mat4fMultiply(const float* A, const float* B, float* R);
    ORBIS_API void mat4fMultiplyV(const float* A, const float* B, float* R);
    ORBIS_API void mat4fPower(const float* A, const int* exp, float* R);
    ORBIS_API void mat4fDeterminant(const float* A, float* r);
    ORBIS_API void mat4fTranspose(const float* A, float* R);

    [[maybe_unused]] ORBIS_API void mat4fInverse(const float* A, float* R);
}