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

extern "C" {
ORBIS_API GLFWwindow* createWindow(int width, int height, const std::string& title);
ORBIS_API GLuint createShader(GLenum type);
ORBIS_API GLuint compileShader(GLuint shader, const GLchar* source, GLchar *errorLog, GLsizei errorLength);
ORBIS_API void deleteShader(GLuint shader);
ORBIS_API GLuint createProgram();
ORBIS_API void attachShader(GLuint program, GLuint shader);
ORBIS_API GLuint linkProgram(GLuint program, GLchar *errorLog, GLsizei errorLength);
ORBIS_API void useProgram(GLuint program);

ORBIS_API GLuint createVertexArray();
ORBIS_API void bindVertexArray(GLuint vao);
ORBIS_API GLuint createBuffer();
ORBIS_API void bindBuffer(GLenum target, GLuint vbo);
ORBIS_API void bufferData(GLenum target, float *vertices, GLsizei count, GLenum usage);
ORBIS_API void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
ORBIS_API void enableVertexAttribArray(GLuint index);

ORBIS_API void clear(GLbitfield mask);
ORBIS_API void drawArrays(GLenum mode, GLint first, GLsizei count);

ORBIS_API int shouldWindowClose(GLFWwindow*);
ORBIS_API void renderWindow(GLFWwindow*);
ORBIS_API void shutDown();
}