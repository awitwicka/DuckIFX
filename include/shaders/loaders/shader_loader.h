//
// Created by jakub on 5/24/16.
//

#ifndef DUCK_SHADER_LOADER_H
#define DUCK_SHADER_LOADER_H

#include <shaders/shader.h>
#include <shaders/fragment_shader.h>
#include <shaders/vertex_shader.h>

class ShaderLoader {
private:

    std::string getShaderCode(const GLchar* path);
public:

    ShaderLoader();

    ~ShaderLoader();

    VertexShader loadVertexShader(const GLchar* path);
    FragmentShader loadFragmentShader(const GLchar* path);

    static VertexShader LoadDefaultVertexShader();
    static FragmentShader LoadDefaultFragmentShader();
};


#endif //DUCK_SHADER_LOADER_H
