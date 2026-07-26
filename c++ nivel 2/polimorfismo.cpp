#include <iostream>
#include <string>
#include <vector>

// 1. CLASE BASE
class Mascota {
protected:
    std::string nombre;

public:
    Mascota(std::string n) : nombre(n) {}

    // 'virtual' habilita el polimorfismo
    virtual void hacerSonido() const {
        std::cout << nombre << " hace un sonido generico.\n";
    }
};

// 2. CLASE HIJA: Perro
class Perro : public Mascota {
public:
    Perro(std::string n) : Mascota(n) {}

    // 'override' indica que estamos reescribiendo el método del padre
    void hacerSonido() const override {
        std::cout << nombre << " dice: ¡Guau! 🐶\n";
    }
};

// 3. CLASE HIJA: Gato
class Gato : public Mascota {
public:
    Gato(std::string n) : Mascota(n) {}

    void hacerSonido() const override {
        std::cout << nombre << " dice: ¡Miau! 🐱\n";
    }
};

int main() {
    // Apuntamos a diferentes animales usando punteros de tipo 'Mascota*'
    Mascota* mascota1 = new Perro("Firulais");
    Mascota* mascota2 = new Gato("Michi");

    // ¡Aquí ocurre la magia del Polimorfismo!
    // Usamos exactamente el mismo método, pero cada uno responde diferente
    mascota1->hacerSonido(); // Ejecuta la versión de Perro
    mascota2->hacerSonido(); // Ejecuta la versión de Gato

    // Liberamos memoria
    delete mascota1;
    delete mascota2;

    return 0;
}