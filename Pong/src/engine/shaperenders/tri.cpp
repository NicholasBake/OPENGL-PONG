#include<engine/shaperenders/tri.h>
#include<engine/Util/Colors.hpp>
#include <string>
void tri::drawTri(const char* Material){
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // vertex buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);
  
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, tri::Positionz.vertsCalculated, GL_STATIC_DRAW);  
    
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);   
    // vertex shader
    const char* vertexShader = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main(){\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    unsigned int vertex;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShader, NULL);
    unsigned int fragment;
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &Material, NULL);
    // shader program

    glCompileShader(vertex);
    glCompileShader(fragment);
    GLint compileStatus;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &compileStatus);
    if(compileStatus != GL_TRUE){
        GLint infoLength;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &infoLength);

        GLchar* info = new GLchar[infoLength];

        GLsizei buffersize;
        glGetShaderInfoLog(fragment, infoLength, &buffersize, info);

        std::cout << info;

        delete [] info;
    }
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertex);
    glAttachShader(shaderProgram, fragment);
    glLinkProgram(shaderProgram);
    // Deleting unlinked shaders from memory
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    /*---- END OF SETUP ----*/
    
    
    // Drawing triangle using our buffer and our shader
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glUseProgram(shaderProgram);

     
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Cleaning up
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &VAO);
}
