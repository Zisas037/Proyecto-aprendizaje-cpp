#include <iostream>

int main(){
    int stamina=100;
    int gasto;

    while(stamina>0){
       std::cin>>gasto; 
       if(gasto<=0){
        std::cout<<"Ha ocurrido un error"<<std::endl;
       }
       else if(gasto<=stamina){
         stamina-=gasto;
         std::cout<<"El ataque ha sido un exito"<<std::endl;
       }
       else{
        std::cout<<"No tienes suficiente stamina para realizar el ataque"<<std::endl;
       }

    }
    std::cout<<"Te has quedado sin stamina"<<std::endl;
    return 0;
}