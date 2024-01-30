#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
    float x, y, z, r, g, b, u, v;
};

vector<Vertex> mVertices;

long double f(double x, double y) {
    return (x * x) + (y * y);
}

long double dfx(long double x, long double y, long double h) {
    return (f(x + h, y) - f(x, y)) / h;
}

long double dfy(long double x, long double y, long double h) {
    return (f(x, y + h) - f(x, y)) / h;
}

void PrintDatafil(long double a, long double b, int num_points, long double h)
{
    std::ofstream dataFile("datapunkter.txt");
    dataFile << std::fixed << std::setprecision(3);

    if (dataFile.is_open()) {

        dataFile <<"Antall datapunkter: "<< (num_points+1)*(num_points+1) << std::endl;
        for (int i = 0; i < num_points+1; ++i) {
            for (int j = 0; j < num_points+1; ++j) {
                long double x = a + i * h;
                long double y = a + j * h;
                long double z = f(x, y);

                long double dx = dfx(x, y, h);
                long double dy = dfy(x, y, h);

                Vertex vertex;
                vertex.x = x;
                vertex.y = y;
                vertex.z = z;
                if (dx >= 0 && dy >= 0) {
                    vertex.r = 0.0f;
                    vertex.g = 1.0f;
                    vertex.b = 0.0f;
                } else {
                    vertex.r = 1.0f;
                    vertex.g = 0.0f;
                    vertex.b = 0.0f;
                }
                mVertices.push_back(vertex);

                dataFile <<"X: " << vertex.x << ", " << "Y: " << vertex.y << ", " << "Z: " << vertex.z << ", " << "r: " << vertex.r << ", " << "g: " << vertex.g << ", " << "b: " << vertex.b << std::endl;
            }
        }

        dataFile.close();
        std::cout << "Datapunkter er lagret i filen 'datapunkter.txt'.\n";
    } else {
        std::cout << "Kunne ikke åpne filen for å lagre datapunkter.\n";
    }
}


int main(int argc, char* argv[])
{
    long double a = -5.0;
    long double b = 5.0;
    int num_points = 100;
    long double h = (b-a)/num_points;

    PrintDatafil(a, b, num_points, h);
    return 0;
}