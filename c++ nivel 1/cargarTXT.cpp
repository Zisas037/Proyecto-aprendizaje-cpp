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

void cargarArchivo(std::vector<Objetivo>& lista){
    std::ifstream archivo( "criminales.txt");

    if(archivo.is_open()){
        lista.clear();

        std::string nombre, alias;
        int recompensa;

        while(std::getline(archivo,nombre) && std::getline(archivo,alias) && archivo>>recompensa){
        archivo.ignore();
        
        lista.push_back({nombre,alias,recompensa});

        }

        archivo.close();
        std::cout<<"Datos cargados desde el archivo"<<std::endl;
    }
    else{
        std::cout<<"No se encontro el archivo previo. Iniciando lista vacia"<<std::endl;
    }

}

int main(){

    std::vector<Objetivo>lista={
        {"popo","El flaco",500},
        {"jiji","El guapo",2000},
        {"siuu","El chileno",100},
        {"ee","El pigga del norte",800}
    };
for(const Objetivo& criminal: lista){
        std::cout<<criminal.nombre<<" "<<criminal.alias<<" "<<criminal.recompensa<<" monedas\n"<<std::endl;

    }
    cargarArchivo(lista);
    


    return 0;
}