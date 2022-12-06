#include "orbis.h"
#include "orbismath.h"

using namespace std;

namespace glfw = orbis::glfw;
namespace gl = orbis::gl;
namespace om = orbis::math;

int main() {
    // create window
    if (!glfw::init()) {
        return -1;
    }
    GLFWwindow *window = glfw::createWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        glfw::shutDown();
        return -1;
    }
    glfw::makeContextCurrent(window);
    if (!gl::load()) {
        glfw::shutDown();
        return -1;
    }

    cout << "vec2: " << sizeof(om::Vec2f) << endl;
    cout << "vec3: " << sizeof(om::Vec3f) << endl;
    cout << "vec4: " << sizeof(om::Vec4f) << endl;
    cout << "mat2: " << sizeof(om::Mat2f) << endl;
    cout << "mat3: " << sizeof(om::Mat3f) << endl;
    cout << "mat4: " << sizeof(om::Mat4f) << endl;

    // create shaders
    int success;
    auto *errorLog = new GLchar[512];
    auto vertexShader = gl::createShader(GL_VERTEX_SHADER);
    gl::shaderSource(vertexShader, 1, "#version 450 core\n"
                                      "layout (location = 0) in vec3 aPos;\n"
                                      "void main()\n"
                                      "{\n"
                                      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                      "}", nullptr);
    gl::compileShader(vertexShader);
    gl::getShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        gl::getShaderInfoLog(vertexShader, 512, nullptr, errorLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:" << endl << errorLog << endl;
        glfw::shutDown();
        return -1;
    }
    auto fragmentShader = gl::createShader(GL_FRAGMENT_SHADER);
    gl::shaderSource(fragmentShader, 1,  "#version 450 core\n"
                                      "out vec4 FragColor;\n"
                                      "void main()\n"
                                      "{\n"
                                      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                      "}", nullptr);
    gl::compileShader(fragmentShader);
    gl::getShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        gl::getShaderInfoLog(fragmentShader, 512, nullptr, errorLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:" << endl << errorLog<< endl;
        glfw::shutDown();
        return -1;
    }

    // create shader program
    auto program = gl::createProgram();
    gl::attachShader(program, vertexShader);
    gl::attachShader(program, fragmentShader);
    gl::linkProgram(program);
    gl::getProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        gl::getProgramInfoLog(program, 512, nullptr, errorLog);
        cout << "ERROR::PROGRAM::LINKING_FAILED:" << endl << errorLog << endl;
        glfw::shutDown();
        return -1;
    }
    gl::deleteShader(vertexShader);
    gl::deleteShader(fragmentShader);

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    // create buffers
    GLuint vao;
    gl::createVertexArrays(1, &vao);
    gl::bindVertexArray(vao);
    GLuint vbo;
    gl::createBuffers(1, &vbo);
    gl::bindBuffer(GL_ARRAY_BUFFER, vbo);
    gl::bufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    auto vertexSize = 3;
    gl::vertexAttribPointer(0, vertexSize, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), nullptr);
    gl::enableVertexAttribArray(0);

    // render
    while (!glfw::windowShouldClose(window)) {
        gl::clear(GL_COLOR_BUFFER_BIT);

        gl::useProgram(program);
        gl::bindVertexArray(vao);
        gl::drawArrays(GL_TRIANGLES, 0, 3);

        glfw::swapBuffers(window);
        glfw::pollEvents();
    }

    glfw::shutDown();
    return 0;
}