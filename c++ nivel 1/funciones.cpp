#include <iostream>

void aplicarPocion(int&vida, int puntos){
    vida+=puntos;
}

int main(){
    int vida=30;


    std::cout<<"Vida: "<<vida<<std::endl;
    aplicarPocion(vida, 25);

    std::cout<<"Vida: "<<vida<<std::endl;


    return 0;
}