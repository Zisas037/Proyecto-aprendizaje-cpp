#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

struct Objetivo{
    std::string nombre;
    std::string alias;
    int recompensa;
};

void guardarArchivo(const std::vector<Objetivo>& lista){
    std::ofstream archivo("criminales.txt");

    if(archivo.is_open()){
        for(const Objetivo& criminal: lista){
            archivo<<criminal.nombre<<" ";
            archivo<<criminal.alias<<" ";
            archivo<<criminal.recompensa<<"\n";
        }
        archivo.close();
        std::cout<<"Datos guardados en criminales.txt"<<std::endl;
    }

}

int main(){

  std::vector<Objetivo>lista={
        {"Damian","El flaco",500},
        {"Vitor","El guapo",2000},
        {"Edgar","El chileno",100},
        {"Lucca","El pigga del norte",800}
    };

    guardarArchivo(lista);
    return 0;
}