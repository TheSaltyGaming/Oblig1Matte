#include <cmath>
#include <vector>

struct Vertex
{
    float x, y, z, r, g, b, u, v;
};

std::vector<Vertex> generateSpiralPoints(float radius, float start, float end, float step) {
    std::vector<Vertex> spiralPoints;

    for (float t = start; t <= end; t += step) {
        Vertex vertex;
        vertex.x = radius * cos(t);
        vertex.y = radius * sin(t);
        vertex.z = t;

        // You can set the color attributes (r, g, b) here if you want
        // For example, let's set them to 1.0f
        vertex.r = 1.0f;
        vertex.g = 1.0f;
        vertex.b = 1.0f;

        spiralPoints.push_back(vertex);
    }

    return spiralPoints;
}

int main(int argc, char* argv[]) {
    float radius = 1.0f;
    float start = 0.0f;
    float end = 10.0f;
    float step = 0.1f;

    std::vector<Vertex> spiralPoints = generateSpiralPoints(radius, start, end, step);

    // Now you can use the spiralPoints vector as you wish

    return 0;
}