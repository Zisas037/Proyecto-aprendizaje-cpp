#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<fstream>

struct Objetivo{
    std::string nombre;
    std::string alias;
    int recompensa;
};

void mostrarTablon(std::vector <Objetivo>& lista){
    int i=0;
    std::sort(lista.begin(),lista.end(),[](const Objetivo& a, const Objetivo& b){
        return a.recompensa > b.recompensa;
    });
    for(const Objetivo& criminal:lista){
        std::cout<<"#"<<i+1<<" "<<criminal.nombre<<" ´"<<criminal.alias<<"´    []    "<<criminal.recompensa<<" oro\n"<<std::endl;
    i++;
    }
}

void aumentarRecompensa(Objetivo& presa, int cantidadExtra){
    presa.recompensa+=cantidadExtra;
}

void guardarArchivo(const std::vector<Objetivo>& lista){
    std::ofstream archivo("criminales.txt");

    if(archivo.is_open()){
        for(const Objetivo& criminal:lista){
            archivo<<criminal.nombre<<" "<<criminal.alias<<" [] Recompensa: "<<criminal.recompensa<<" monedas"<<std::endl;
        }
        archivo.close();
        std::cout<<"\nDatos guardados en archivo criminales.txt\n"<<std::endl;
    }
}

int main(){
    int opcM=0;
    std::string nombreCR;
    std::string alias;
    int recompensaCR=0;
    int indiceCR=0;
    int recompensaExtra=0;

    std::vector <Objetivo> lista{
        {"John","El Devorador de Sombras",500},
        {"Max","Manos de fuego",1000},
    };

   while(opcM!=6){
    std::cout<<"\n\nElige una opcion: \n1. Ver tablon de los mas buscados\n2. Registrar nuevo criminal\n3.Subir recompensa\n4.Cazar criminal\n5. Guardar lista en disco\n6. Salir\n\nOpcion: "<<std::ends;
    std::cin>>opcM;

    if(opcM==1){
    mostrarTablon(lista);
    }

    if(opcM==2){
        std::cout<<"\n\nNombre del criminal: "<<std::ends;
        std::cin>>nombreCR;
        std::cout<<"\nAlias del criminal: "<<std::ends;
        std::cin.ignore();
       std::getline(std::cin, alias);
        std::cout<<"\nRecompensa del criminal: "<<std::ends;
        std::cin>>recompensaCR;
        lista.push_back({nombreCR,alias,recompensaCR});
    }


     if(opcM==3){
        std::cout<<"\n\nIngrese el indice del criminal: "<<std::ends;
        std::cin>>indiceCR;
        std::cout<<"Recompensa extra: "<<std::ends;
        std::cin>>recompensaExtra;
        std::cout<<"\n\n"<<std::endl;
        aumentarRecompensa(lista[indiceCR-1],recompensaExtra);
    }

     if(opcM==4){
        std::cout<<"\n\nIngrese el indice del criminal cazado: "<<std::ends;
        std::cin>>indiceCR;
        lista.erase(lista.begin()+(indiceCR-1));
    }

    if(opcM==5){
        guardarArchivo(lista);
    }
   }
    return 0;
}