#include <orbis.h>

using namespace std;

int main() {
    GLFWwindow *window = createWindow(640, 480, "Hello World");
    if (!window) {
        terminateWindows();
        return -1;
    }

    auto vertexShader = createShader(GL_VERTEX_SHADER);
    compileShader(vertexShader, "#version 450 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "void main()\n"
                                "{\n"
                                "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                "}", [](auto errorLog){
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n" << errorLog << std::endl;
    });
    auto fragmentShader = createShader(GL_FRAGMENT_SHADER);
    compileShader(fragmentShader, "#version 450 core\n"
                                  "out vec4 FragColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                  "}", [](auto errorLog){
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n" << errorLog << std::endl;
    });
    auto program = createProgram();
    attachShader(program, vertexShader);
    attachShader(program, fragmentShader);
    linkProgram(program, [](auto errorLog){
        std::cout << "ERROR::PROGRAM::LINKING_FAILED:\n" << errorLog << std::endl;
    });
    deleteShader(vertexShader);
    deleteShader(fragmentShader);

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    //create buffers
    auto vao = createVao();
    bindVao(vao);

    auto vbo = createVbo();
    bindVbo(vbo);
    fillVbo(vertices, 9, GL_STATIC_DRAW);
    configVbo(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

    renderWindow(window, [program, vao] (unsigned int diff) {
        useProgram(program);
        bindVao(vao);
        drawArrays(GL_TRIANGLES, 0, 3);
    });

    terminateWindows();
    return 0;
}
