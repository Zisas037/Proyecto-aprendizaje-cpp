#include <iostream>
#include <string>

// 1. CLASE BASE (Padre)
class Mascota {
protected: // 'protected' permite que las clases hijas accedan a estas variables
    std::string nombre;
    int energia;

public:
    Mascota(std::string n, int e) {
        nombre = n;
        energia = e;
    }

    void jugar() {
        energia -= 20;
        if (energia < 0) energia = 0;
    }

    void alimentar() {
        energia += 15;
        if (energia > 100) energia = 100;
    }

    void mostrarPantalla() const {
        std::cout << "-----------------------\n";
        std::cout << "Nombre: " << nombre << "\nEnergia: " << energia << "\n";
        std::cout << "-----------------------\n";
    }
};

// 2. CLASE DERIVADA (Hija): Perro hereda de Mascota
class Perro : public Mascota {
public:
    // El constructor del Perro le pasa los datos al constructor de Mascota
    Perro(std::string n, int e) : Mascota(n, e) {}

    // Método único que SOLO tienen los perros
    void ladrar() {
        if (energia >= 10) {
            std::cout << nombre << " dice: ¡Guau! ¡Guau!\n";
            energia -= 10;
        } else {
            std::cout << nombre << " esta demasiado cansado para ladrar...\n";
        }
    }
};

int main() {
    // Creamos un Perro en lugar de una Mascota genérica
    Perro miPerro("Firulais", 50);

    // Métodos heredados de Mascota:
    miPerro.mostrarPantalla();
    miPerro.alimentar();
    
    // Método exclusivo de Perro:
    miPerro.ladrar();
    
    miPerro.mostrarPantalla();

    return 0;
}