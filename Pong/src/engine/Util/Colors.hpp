#pragma once

const constexpr char* Red = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "   FragColor = vec4(1.0,0.0,0.0,1.0);\n"
    "}\0";
const constexpr char* Green = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "   FragColor = vec4(0.0,1.0,0.0,1.0);\n"
    "}\0";
const constexpr char* Blue = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "   FragColor = vec4(0.0,0.0,1.0,1.0);\n"
    "}\0";
const constexpr char* White = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "   FragColor = vec4(1.0,1.0,1.0,1.0);\n"
    "}\0";