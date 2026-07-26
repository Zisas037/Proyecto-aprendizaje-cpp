#include <iostream>

struct Maniqui{
        int vida=50;
    };


    int golpearManiqui(Maniqui& maniqui, int daño){
        maniqui.vida-=daño;
        if(maniqui.vida<0){
            maniqui.vida=0;
        }
        std::cout<<"El maniqui ha recibido "<<daño<<" de daño, su vida es de "<<maniqui.vida<<std::endl;
        return maniqui.vida;

    }


int main(){
    int daño;
    Maniqui maniqui1;
    while(maniqui1.vida>0){
        std::cout<<"Vida del maniqui: "<<maniqui1.vida<<std::endl;
        std::cout<<"Ingrese daño a infligir: "<<std::ends;
        std::cin>>daño;
        golpearManiqui(maniqui1,daño);
    }
    std::cout<<"El maniqui ha sido vencido"<<std::endl;

    return 0;
}