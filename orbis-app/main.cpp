#include <orbis.h>

using namespace std;

int main() {
    // create window
    GLFWwindow *window = createWindow(640, 480, "Hello World");
    if (!window) {
        shutDown();
        return -1;
    }

    // create shaders
    auto *errorLog = new GLchar[512];
    auto vertexShader = createShader(GL_VERTEX_SHADER);
    if (!compileShader(vertexShader, "#version 450 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "void main()\n"
                                "{\n"
                                "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                "}", errorLog, 512)) {
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n" << errorLog << std::endl;
        shutDown();
        return -1;
    }
    auto fragmentShader = createShader(GL_FRAGMENT_SHADER);
    if (!compileShader(fragmentShader, "#version 450 core\n"
                                      "out vec4 FragColor;\n"
                                      "void main()\n"
                                      "{\n"
                                      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                      "}", errorLog, 512)) {
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:\n" << errorLog<< std::endl;
        shutDown();
        return -1;
    }

    // create shader program
    auto program = createProgram();
    attachShader(program, vertexShader);
    attachShader(program, fragmentShader);
    auto linkSuccess = linkProgram(program, errorLog, 512);
    deleteShader(vertexShader);
    deleteShader(fragmentShader);
    if (!linkSuccess) {
        std::cout << "ERROR::PROGRAM::LINKING_FAILED:\n" << errorLog << std::endl;
        shutDown();
        return -1;
    }

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    // create buffers
    auto vao = createVertexArray();
    bindVertexArray(vao);
    auto vbo = createBuffer();
    bindBuffer(GL_ARRAY_BUFFER, vbo);
    bufferData(GL_ARRAY_BUFFER, vertices, 9, GL_STATIC_DRAW);
    vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
    enableVertexAttribArray(0);

    // render
    while (!shouldWindowClose(window)) {
        clear(GL_COLOR_BUFFER_BIT);

        useProgram(program);
        bindVertexArray(vao);
        drawArrays(GL_TRIANGLES, 0, 3);

        renderWindow(window);
    }

    shutDown();
    return 0;
}