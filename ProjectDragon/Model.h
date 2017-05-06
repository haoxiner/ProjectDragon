#pragma once
#include "Platform.h"
#include <vector>
namespace PD
{
class Model
{
public:
    bool Startup(std::vector<float>& positions,
                 std::vector<float>& normals,
                 std::vector<float>& texCoords,
                 std::vector<int>& indices);
    void Shutdown();
    void Render();
protected:
    GLuint CreateVAO();
    void UnbindVAO();
    void StoreDataInAttributeList(int attributeLocation, int elementCountPerVertex, std::vector<float>& data);
    void BindIndicesBuffer(std::vector<int>& indices);
private:
    GLuint vao_;
    std::vector<GLuint> vboList_;
    GLsizei indexCount_;
};
}