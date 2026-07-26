#include <iostream>
#include <string>

class Jugador {
private:
    // ATRIBUTOS (Protegidos, nadie los cambia directamente desde el main)
    std::string nombre;
    int vida;
    int ataque;

public:
    // CONSTRUCTOR (Inicializa al personaje)
    Jugador(std::string n, int v, int a) {
        nombre = n;
        vida = v;
        ataque = a;
    }

    // MÉTODOS (Comportamientos del objeto)
    void recibirDano(int cantidad) {
        vida -= cantidad;
        if (vida < 0) vida = 0; // Control de seguridad: la vida nunca es menor a 0
        std::cout << nombre << " recibio " << cantidad << " de dano. Vida restante: " << vida << "\n";
    }

    void atacar(Jugador& enemigo) {
        std::cout << nombre << " ataca a " << enemigo.nombre << "!\n";
        enemigo.recibirDano(ataque); // Le aplicamos daño al enemigo usando su propio método
    }

    // GETTER (Permite LEER un valor privado sin poder modificarlo)
    int getVida() const {
        return vida;
    }
};

int main() {
    // Creación de dos objetos usando el constructor
    Jugador p1("Guerrero", 100, 20);
    Jugador p2("Goblin", 50, 10);

    // p1.vida = 999; // ❌ ERROR DE COMPILACIÓN: 'vida' es privada

    // Simulación de combate
    p1.atacar(p2); // El guerrero ataca al goblin
    p2.atacar(p1); // El goblin responde

    std::cout << "\nVida final del guerrero: " << p1.getVida() << "\n";

    return 0;
}