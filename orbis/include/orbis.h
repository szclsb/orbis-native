#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>

#ifdef ORBIS_EXPORTS
    #define ORBIS_API  __declspec(dllexport)   // export DLL information
#else
    #define ORBIS_API  __declspec(dllimport)   // import DLL information
#endif

typedef std::function<void(std::string errorLog)> ErrorCallback;
typedef std::function<void(unsigned int diff)> RenderCallback;

extern "C" {
ORBIS_API GLFWwindow* createWindow(int width, int height, const std::string& title);
ORBIS_API GLuint createShader(GLenum type);
ORBIS_API void compileShader(GLuint shader, const std::string& source, const ErrorCallback& errorCallback);
ORBIS_API void deleteShader(GLuint shader);
ORBIS_API GLuint createProgram();
ORBIS_API void attachShader(GLuint program, GLuint shader);
ORBIS_API void linkProgram(GLuint program, const ErrorCallback& errorCallback);
ORBIS_API void useProgram(GLuint program);

ORBIS_API GLuint createVao();
ORBIS_API void bindVao(GLuint vao);
ORBIS_API GLuint createVbo();
ORBIS_API void bindVbo(GLuint vbo);
ORBIS_API void fillVbo(float *vertices, size_t count, GLenum usage);
ORBIS_API void configVbo(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);

ORBIS_API void drawArrays(GLenum mode, GLint first, GLsizei count);

ORBIS_API void renderWindow(GLFWwindow *window, const RenderCallback& callback);
ORBIS_API void terminateWindows();
}