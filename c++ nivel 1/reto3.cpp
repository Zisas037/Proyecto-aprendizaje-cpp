#include <iostream>
#include <vector>
#include <string>

    struct Jugador{
        std::string nombre;
        int puntaje;

    };


    void registrarPartida(Jugador& tabla, int nuevoPuntaje){
        if(nuevoPuntaje>tabla.puntaje){
        tabla.puntaje=nuevoPuntaje;
        std::cout<<"Nuevo record para "<<tabla.nombre<<std::endl;
        }
        else{
            std::cout<<" El puntaje no supera el récord actual"<<std::endl;
        }
       
    }

int main(){
    int opc=0;
    std::string nombre;
    int puntajeInicial=0;
    int jugadorI=0;
    int nuevoPuntaje=0;
    


    std::vector<Jugador> tabla;

    tabla.push_back({"Pablo",50});
    tabla.push_back({"Juan",80});

    while(opc!=4){
        std::cout<<"Elige una opcion: \n1. Ver tabla\n2. Agregar jugador\n3. Registrar partida\n4. Salir\nOpcion: "<<std::ends;
        std::cin>>opc;

        int i=0;
        if(opc==1){
            std::cout<<"\n\n"<<std::endl;
            std::cout<<"     Nombre     []     Puntaje     \n==================================="<<std::endl;
            for(const Jugador& registro: tabla){
                std::cout<<"                []                 "<<std::endl;
                std::cout<<"     "<<registro.nombre<<"      []     "<<registro.puntaje<<"           "<<std::endl;
                std::cout<<"                []                 \n==================================="<<std::endl;
                i++;
            }
            std::cout<<"\n\n"<<std::endl;
        }

        if(opc==2){
            std::cout<<"\n\nIngresa el nombre del jugador: "<<std::ends;
            std::cin>>nombre;
            std::cout<<"\nIngresa el puntaje inicial: "<<std::ends;
            std::cin>>puntajeInicial;
            tabla.push_back({nombre,puntajeInicial});
            std::cout<<"\n\n"<<std::endl;
        }

        if(opc==3){
            std::cout<<"\n\nIngresa el indice del jugador a actualizar: "<<std::ends;
            std::cin>>jugadorI;
            std::cout<<"\nIngrese el nuevo puntaje: "<<std::ends;
            std::cin>>nuevoPuntaje;
            registrarPartida(tabla[jugadorI-1],nuevoPuntaje);
            std::cout<<"\n\n"<<std::endl;
        }

    }

    return 0;
}