#include "Model.h"

bool PD::Model::Startup(std::vector<float>& positions, std::vector<float>& normals, std::vector<float>& texCoords, std::vector<int>& indices)
{
    vao_ = CreateVAO();
    indexCount_ = static_cast<GLsizei>(indices.size());
    StoreDataInAttributeList(0, 3, positions);
    StoreDataInAttributeList(1, 3, normals);
    StoreDataInAttributeList(2, 2, texCoords);
    BindIndicesBuffer(indices);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    UnbindVAO();
    return true;
}

void PD::Model::Shutdown()
{
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(static_cast<GLsizei>(vboList_.size()), static_cast<GLuint*>(vboList_.data()));
}

void PD::Model::Render()
{
    glBindVertexArray(vao_);
    glDrawElements(GL_TRIANGLES, indexCount_, GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);
}

GLuint PD::Model::CreateVAO()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

void PD::Model::UnbindVAO()
{
    glBindVertexArray(0);
}

void PD::Model::StoreDataInAttributeList(int attributeLocation, int elementCountPerVertex, std::vector<float>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), static_cast<void*>(data.data()), GL_STATIC_DRAW);
    glVertexAttribPointer(attributeLocation, elementCountPerVertex, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    vboList_.push_back(vbo);
}

void PD::Model::BindIndicesBuffer(std::vector<int>& indices)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), &indices[0], GL_STATIC_DRAW);
    vboList_.push_back(vbo);
}
