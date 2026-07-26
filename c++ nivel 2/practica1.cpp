#include <iostream>
#include <string>

class Mascota {
private:
    // ATRIBUTOS
    std::string nombre;
    int energia;

public:
    // CONSTRUCTOR
    Mascota(std::string n, int e) {
        nombre = n;
        energia = e;
    }

    // MÉTODOS
    void jugar() {
        energia -= 20;
        if (energia < 0) energia = 0; // No baja de 0
    }

    void alimentar() {
        energia += 15;
        if (energia > 100) energia = 100; // No sube de 100
    }

    // Ya no necesita recibir a 'm1' porque ya conoce sus variables
    void mostrarPantalla() const {
        std::cout << "-----------------------\n";
        std::cout << "Nombre: " <<nombre<< "\nEnergia: " << energia << "\n";
        std::cout << "-----------------------\n";
    }
};

int main() {
    int opcM = 0;
    Mascota m1("Pedro", 80);

    while (opcM != 3) {
        m1.mostrarPantalla();

        std::cout << "\nElige una opcion:\n1. Jugar\n2. Alimentar\n3. Salir\n\nOpcion: ";
        std::cin >> opcM;

        if (opcM == 1) {
            m1.jugar();
        } 
        else if (opcM == 2) {
            m1.alimentar();
        }
    }
    return 0;
}