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
namespace orbis {
    namespace glfw {
        ORBIS_API int init();

        ORBIS_API GLFWwindow *createWindow(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share);

        ORBIS_API void makeContextCurrent(GLFWwindow *window);

        ORBIS_API int windowShouldClose(GLFWwindow *window);

        ORBIS_API void swapBuffers(GLFWwindow *window);

        ORBIS_API void pollEvents();

        ORBIS_API void shutDown();
    }

    namespace gl {
        ORBIS_API int load();

        ORBIS_API GLuint createShader(GLenum type);

        ORBIS_API void shaderSource(GLuint shader, GLsizei count, const GLchar *source, const GLint *length);

        ORBIS_API void compileShader(GLuint shader);

        ORBIS_API void getShaderiv(GLuint shader, GLenum pname, GLint *params);

        ORBIS_API void getShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);

        ORBIS_API void deleteShader(GLuint shader);

        ORBIS_API GLuint createProgram();

        ORBIS_API void attachShader(GLuint program, GLuint shader);

        ORBIS_API void linkProgram(GLuint program);

        ORBIS_API void getProgramiv(GLuint program, GLenum pname, GLint *params);

        ORBIS_API void getProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);

        ORBIS_API void useProgram(GLuint program);

        ORBIS_API void createVertexArrays(GLsizei n, GLuint *arrays);

        ORBIS_API void bindVertexArray(GLuint array);

        ORBIS_API void createBuffers(GLsizei n, GLuint *buffers);

        ORBIS_API void bindBuffer(GLenum target, GLuint buffer);

        ORBIS_API void bufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage);

        ORBIS_API void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

        ORBIS_API void disableVertexAttribArray(GLuint index);

        ORBIS_API void enableVertexAttribArray(GLuint index);

        ORBIS_API void clear(GLbitfield mask);

        ORBIS_API void drawArrays(GLenum mode, GLint first, GLsizei count);

        ORBIS_API void drawElements(GLenum mode, GLsizei count, GLenum type, const void *indices);
    }
}
}
