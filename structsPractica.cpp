#include <iostream>

struct Personaje{
    int vida;
    int stamina;
};

void recibirDano(Personaje& p, int dano){
p.vida-=dano;
if(p.vida<0) p.vida=0;
std::cout<<"El personaje sufrio "<<dano<<" de dano!"<<std::endl;
}

void mostrarEstado(const Personaje& p){
std::cout << "----------------------" << std::endl;
    std::cout << "Vida: " << p.vida << std::endl;
    std::cout << "Stamina: " << p.stamina << std::endl;
    std::cout << "----------------------" << std::endl;

}



int main(){
Personaje heroe={100, 80};

std::cout << "=== ESTADO INICIAL ===" << std::endl;
mostrarEstado(heroe);

recibirDano(heroe, 35);

std::cout << "\n=== ESTADO DESPUES DEL ATAQUE ===" << std::endl;
mostrarEstado(heroe);

    return 0;
}