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

long double f(double x) {
    return x * x;
}

long double df(long double x, long double h) {
    return (f(x + h) - f(x)) / h;
}

void PrintDatafil(long double a, long double b, int num_points, long double h)
{
    // Åpne en fil for å lagre datapunkter
    std::ofstream dataFile("datapunkter.txt");
    dataFile << std::fixed << std::setprecision(3);

    if (dataFile.is_open()) {

        dataFile <<"Antall datapunkter: "<< num_points+1 << std::endl;
        // Skriv datapunkter til filen
        for (int i = 0; i < num_points+1; ++i) {
            long double x = a + i * h; // Beregn x-verdien
            long double y = f(x); // Beregn tilhørende y-verdi ved å evaluere f(x)

            //find derivative point
            long double dy = df(x, h);

            Vertex vertex;
            vertex.x = x;
            vertex.y = y;
            vertex.z = 0.0f;
            if (dy >= 0) {
                vertex.r = 0.0f;
                vertex.g = 1.0f;
                vertex.b = 0.0f;
            } else {
                vertex.r = 1.0f;
                vertex.g = 0.0f;
                vertex.b = 0.0f;
            }
            mVertices.push_back(vertex);

            

            // Skriv datapunktet til filen i formatet x, y
            //dataFile <<"X: " << x << ", " << "Y: " << y << ", " << "dy: " << dy << std::endl;
            dataFile <<"X: " << vertex.x << ", " << "Y: " << vertex.y << ", " << "Z: " << vertex.z << ", " << "r: " << vertex.r << ", " << "g: " << vertex.g << ", " << "b: " << vertex.b << std::endl;

        }

        // Lukk filen
        dataFile.close();
        std::cout << "Datapunkter er lagret i filen 'datapunkter.txt'.\n";
    } else {
        std::cout << "Kunne ikke åpne filen for å lagre datapunkter.\n";
    }
}

int main(int argc, char* argv[])
{
    // Definer definisjonsmengden Df = [a, b]
    long double a = -5.0; // Startpunkt
    long double b = 5.0;  // Sluttpunkt
    int num_points = 100; // Antall datapunkter
    long double h = (b-a)/num_points;

    PrintDatafil(a, b, num_points, h);
    return 0;
}