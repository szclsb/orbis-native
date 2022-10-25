#include "./include/orbis.h"

GLFWwindow* createWindow(int width, int height, const char* title) {
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return nullptr;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // load opengl functions
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        return nullptr;
    }
    return window;
}

GLuint createShader(GLenum type) {
    return glCreateShader(type);
}

GLuint compileShader(GLuint shader, const GLchar *source, GLchar* errorLog, GLsizei errorLength) {
    int success;
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, errorLength, nullptr, errorLog);
    }
    return success;
}

void deleteShader(GLuint shader) {
    glDeleteShader(shader);
}

GLuint createProgram() {
    return glCreateProgram();
}

void attachShader(GLuint program, GLuint shader) {
    glAttachShader(program, shader);
}

GLuint linkProgram(GLuint program, GLchar *errorLog, GLsizei errorLength) {
    int success;
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, errorLength, nullptr, errorLog);
    }
    return success;
}

void useProgram(GLuint program) {
    glUseProgram(program);
}

GLuint createVertexArray() {
    unsigned int vao;
    glCreateVertexArrays(1, &vao);
    return vao;
}

void bindVertexArray(GLuint vao) {
    glBindVertexArray(vao);
}

GLuint createBuffer() {
    unsigned int vbo;
    glCreateBuffers(1, &vbo);
    return vbo;
}

void bindBuffer(GLenum target, GLuint vbo) {
    glBindBuffer(target, vbo);
}

void bufferData(GLenum target, float* vertices, GLsizei count, GLenum usage) {
    glBufferData(target, count * sizeof(vertices), vertices, usage);
}

void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
    glVertexAttribPointer(index, size, type, normalized, stride, (void*)nullptr);
}

void enableVertexAttribArray(GLuint index) {
    glEnableVertexAttribArray(index);
}

void clear(GLbitfield mask) {
    glClear(mask);
}

void drawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays(mode, first, count);
}

int shouldWindowClose(GLFWwindow* window) {
    return glfwWindowShouldClose(window);
}

void renderWindow(GLFWwindow* window) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void shutDown() {
    glfwTerminate();
}
