#include "./include/orbis.h"

////////////////
///// GLFW /////
////////////////

int orbis::glfw::init() {
    return glfwInit();
}

GLFWwindow* orbis::glfw::createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
    return glfwCreateWindow(width, height, title, monitor, share);
}

void orbis::glfw::makeContextCurrent(GLFWwindow *window) {
    glfwMakeContextCurrent(window);
}

int orbis::glfw::windowShouldClose(GLFWwindow* window) {
    return glfwWindowShouldClose(window);
}

void orbis::glfw::swapBuffers(GLFWwindow *window) {
    glfwSwapBuffers(window);
}

void orbis::glfw::pollEvents() {
    glfwPollEvents();
}

void orbis::glfw::shutDown() {
    glfwTerminate();
}

//////////////////
///// OpenGL /////
//////////////////

int orbis::gl::load() {
    return gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

GLuint orbis::gl::createShader(GLenum type) {
    return glCreateShader(type);
}

void orbis::gl::shaderSource(GLuint shader, GLsizei count, const GLchar *source, const GLint *length) {
    glShaderSource(shader, count, &source, length);
}

void orbis::gl::compileShader(GLuint shader) {
    glCompileShader(shader);
}

void orbis::gl::getShaderiv(GLuint shader, GLenum pname, GLint *params) {
    glGetShaderiv(shader, pname, params);
}

void orbis::gl::getShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

void orbis::gl::deleteShader(GLuint shader) {
    glDeleteShader(shader);
}

GLuint orbis::gl::createProgram() {
    return glCreateProgram();
}

void orbis::gl::attachShader(GLuint program, GLuint shader) {
    glAttachShader(program, shader);
}

void orbis::gl::linkProgram(GLuint program) {
    glLinkProgram(program);
}

void orbis::gl::getProgramiv(GLuint program, GLenum pname, GLint *params) {
    glGetProgramiv(program, pname, params);
}

void orbis::gl::getProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    glGetProgramInfoLog(program, bufSize, length, infoLog);
}

void orbis::gl::useProgram(GLuint program) {
    glUseProgram(program);
}

void orbis::gl::createVertexArrays(GLsizei n, GLuint *arrays) {
    glCreateVertexArrays(n, arrays);
}

void orbis::gl::bindVertexArray(GLuint array) {
    glBindVertexArray(array);
}

void orbis::gl::createBuffers(GLsizei n, GLuint *buffers) {
    glCreateBuffers(n, buffers);
}

void orbis::gl::bindBuffer(GLenum target, GLuint vbo) {
    glBindBuffer(target, vbo);
}

void orbis::gl::bufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {
    glBufferData(target, size, data, usage);
}

void orbis::gl::vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void orbis::gl::disableVertexAttribArray(GLuint index) {
    glDisableVertexAttribArray(index);
}

void orbis::gl::enableVertexAttribArray(GLuint index) {
    glEnableVertexAttribArray(index);
}

void orbis::gl::clear(GLbitfield mask) {
    glClear(mask);
}

void orbis::gl::drawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays(mode, first, count);
}

void orbis::gl::drawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
    glDrawElements(mode, count, type, indices);
}
