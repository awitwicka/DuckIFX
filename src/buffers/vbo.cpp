//
// Created by jakub on 5/24/16.
//

#include <GL/glew.h>
#include <iostream>
#include "vbo.h"

using namespace std;

VBO::VBO(const std::vector<GLfloat>* vertices) : vertices(vertices){
    glGenBuffers(1, &vboID);
}

VBO::~VBO() {
    glDeleteBuffers(1, &vboID);
}

void VBO::bind(GLenum usage) {
    const GLfloat* rawData = vertices->data();
    GLuint bytesCount = sizeof(GLfloat) * vertices->size();

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, bytesCount, rawData, usage);
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
