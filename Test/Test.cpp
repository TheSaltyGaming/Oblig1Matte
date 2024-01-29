

#include <string>
#include <vector>
#include <glm/glm.hpp>

struct Vertex
{
    float x, y, z, r, g, b, u, v;
};

struct XYZ
{
    std::vector<Vertex> mVertices;
    std::string mName;
    glm::mat4;
    XYZ();
    
};

XYZ::XYZ()
{
    mVertices.push_back(Vertex{0,0,0,1,0,0});
    mVertices.push_back(Vertex{1,0,0,1,0,0});
    mVertices.push_back(Vertex{2,0,0,1,0,0});
}


int main(int argc, char* argv[])
{
    
    return 0;
}
