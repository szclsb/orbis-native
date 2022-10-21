#include "./include/orbis.h"

GLFWwindow* createWindow(int width, int height, const std::string& title) {
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return nullptr;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
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

void compileShader(GLuint shader, const std::string& source, const ErrorCallback& errorCallback) {
    int  success;
    GLsizei infoLength;
    char infoLog[512];
    auto source_ptr = source.c_str();
    glShaderSource(shader, 1, &source_ptr, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, &infoLength, infoLog);
        std::string log(infoLog, infoLength);
        errorCallback(log);
    }
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

void linkProgram(GLuint program, const ErrorCallback& errorCallback) {
    int success;
    GLsizei infoLength;
    char infoLog[512];
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, &infoLength, infoLog);
        std::string log(infoLog, infoLength);
        errorCallback(log);
    }
}

void useProgram(GLuint program) {
    glUseProgram(program);
}

GLuint createVao() {
    unsigned int vao;
    glCreateVertexArrays(1, &vao);
    return vao;
}

void bindVao(GLuint vao) {
    glBindVertexArray(vao);
}

GLuint createVbo() {
    unsigned int vbo;
    glCreateBuffers(1, &vbo);
    return vbo;
}

void bindVbo(GLuint vbo) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void fillVbo(float* vertices, size_t count, GLenum usage) {
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(vertices), vertices, usage);
}

void configVbo(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
    glVertexAttribPointer(index, size, type, normalized, stride, (void*)nullptr);
    glEnableVertexAttribArray(index);
}

void drawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays(mode, first, count);
}

void renderWindow(GLFWwindow* window, const RenderCallback& renderCallback) {
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        renderCallback(0);  //fixme frame diff time

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void terminateWindows() {
    glfwTerminate();
}
