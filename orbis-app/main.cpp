#include <orbis.h>

using namespace std;

int main() {
    bool shouldTerminate = false;

    // create window
    GLFWwindow *window = createWindow(640, 480, "Hello World");
    if (!window) {
        terminateWindows();
        return -1;
    }

    // create shaders
    auto vertexShader = createShader(GL_VERTEX_SHADER);
    compileShader(vertexShader, "#version 450 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "void main()\n"
                                "{\n"
                                "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                "}", [&shouldTerminate](auto errorLog){
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n" << errorLog << std::endl;
        shouldTerminate = true;
    });
    auto fragmentShader = createShader(GL_FRAGMENT_SHADER);
    compileShader(fragmentShader, "#version 450 core\n"
                                  "out vec4 FragColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                  "}", [&shouldTerminate](auto errorLog){
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:\n" << errorLog << std::endl;
        shouldTerminate = true;
    });
    if (shouldTerminate) {
        terminateWindows();
        return -1;
    }

    // create shader program
    auto program = createProgram();
    attachShader(program, vertexShader);
    attachShader(program, fragmentShader);
    linkProgram(program, [&shouldTerminate](auto errorLog){
        std::cout << "ERROR::PROGRAM::LINKING_FAILED:\n" << errorLog << std::endl;
        shouldTerminate = true;
    });
    deleteShader(vertexShader);
    deleteShader(fragmentShader);
    if (shouldTerminate) {
        terminateWindows();
        return -1;
    }

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    // create buffers
    auto vao = createVao();
    bindVao(vao);
    auto vbo = createVbo();
    bindVbo(vbo);
    fillVbo(vertices, 9, GL_STATIC_DRAW);
    configVbo(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

    // render
    renderWindow(window, [program, vao] (unsigned int diff) {
        useProgram(program);
        bindVao(vao);
        drawArrays(GL_TRIANGLES, 0, 3);
    });

    terminateWindows();
    return 0;
}
