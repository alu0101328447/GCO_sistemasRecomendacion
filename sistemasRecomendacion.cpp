#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

int main() {
    std::string line;
    float valorMin, valorMax;
    const int FILAS = 5;

    // Pedir el nombre del archivo
    std::string nombreArchivo;
    std::cout << "Introduce el nombre del archivo: ";
    std::getline(std::cin, nombreArchivo);

    // Abrir el archivo
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return 1; // Salir con un código de error
    }

    // Leer el valor mínimo
    std::getline(archivo, line);
    valorMin = std::stof(line);

    // Leer el valor máximo
    std::getline(archivo, line);
    valorMax = std::stof(line);

    // Leer la matriz
    std::vector<std::vector<float>> matriz(FILAS);
    for (int i = 0; i < FILAS; ++i) {
        std::getline(archivo, line);

        // Vector para almacenar los valores de la fila
        std::vector<float> valores;
        std::istringstream iss(line);
        float value;

        // Separar y almacenar los valores en el vector
        while (iss >> value) {
            valores.push_back(value);
        }
        matriz[i] = valores; // Asignar la fila a la matriz
    }

    // Cerrar el archivo
    archivo.close();

    // Mostrar los resultados
    std::cout << "Valor mínimo: " << valorMin << std::endl;
    std::cout << "Valor máximo: " << valorMax << std::endl;

    std::cout << "Matriz de valores almacenados:" << std::endl;
    for (const auto& fila : matriz) {
        for (const float& val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl; // Nueva línea para cada fila
    }

    return 0;
}

