#include <iostream>

int main() {
    int stamina=29;
    int costoST=30;
    if(stamina>=costoST){
        stamina-=costoST;
        std::cout<<"Ataque exitoso, stamina restante:"<<stamina<<std::endl;

    }   
    else{
        std::cout<<"No tienes suficiente stamina para realizar el ataque."<<std::endl;
    } 
    return 0;
}