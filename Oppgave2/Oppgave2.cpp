#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z, r, g, b, u, v;
};


void PrintDatafil(std::vector<Vertex> spiralPoints)
{
    std::ofstream dataFile("spiralpunkter.txt");
    dataFile << std::fixed << std::setprecision(3);
    if (dataFile.is_open()) {

        dataFile <<"Antall datapunkter: "<< spiralPoints.size() << std::endl;
        // Skriv datapunkter til filen
        for (int i = 0; i < spiralPoints.size(); ++i) {
            Vertex vertex = spiralPoints[i];
            // Skriv datapunktet til filen i formatet x, y
            dataFile <<"X: " << vertex.x << ", " << "Y: " << vertex.z << ", " << "Z: " << vertex.y << ", " << "r: " << vertex.r << ", " << "g: " << vertex.g << ", " << "b: " << vertex.b << std::endl;
        }

        // Lukk filen
        dataFile.close();
        std::cout << "Datapunkter er lagret i filen 'datapunkter.txt'.\n";
    } else {
        std::cout << "Kunne ikke åpne filen for å lagre datapunkter.\n";
    }
}


std::vector<Vertex> generateSpiralPoints(float radius, float start, float end, float step) {

    std::vector<Vertex> spiralPoints;
    for (float t = start; t <= end; t += step) {
        Vertex vertex;
        vertex.x = radius * cos(t);
        vertex.y = radius * sin(t);
        vertex.z = t;
        
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
    PrintDatafil(spiralPoints);

    return 0;
}