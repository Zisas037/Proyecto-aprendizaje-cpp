#include <iostream>
#include <vector>
#include <string>


struct Item{
    std::string nombre;
    int cura;
};


int main(){
    int opc=0;
    int curaObj;
    int opc2=0;
    int vida=40;

    std::vector<Item> mochila;

    mochila.push_back({"Pocion pequeña",10});
    mochila.push_back({"Pocion grande",20});

    while(opc!=4){
        std::cout<<"\nElige una opcion:\n\n 1. Ver estado y mochila\n 2. Usar objeto\n 3. Buscar/Recolectar objeto\n 4. Salir\n\n Opcion:  "<<std::ends;
        std::cin>>opc;

        if(opc==1){
            std::cout<<"\n\n\nVida: "<<vida<<"\nInventario: "<<std::endl;
            for(const Item& item: mochila){
                std::cout<<"- "<<item.nombre<<" cura +"<< item.cura<<std::endl;
            }
           
        }

        if(opc==2){
            std::cout<<"\n\n Ingrese el indice del objeto que quiera usar: "<<std::ends;
            std::cin>>opc2;

            std::cout<<"\nHas elegido la "<<mochila[opc2-1].nombre<<" con una cura de +"<<mochila[opc2-1].cura<<std::endl;
            vida+=mochila[opc2-1].cura;
            mochila.erase(mochila.begin()+(opc2-1));

        }

        if(opc==3){
            mochila.push_back({"Pocion pequeña",10});
            std::cout<<"\n\nSe ha agregado un objeto a la mochila\n\n"<<std::endl;

        }

    }

    return 0;
}