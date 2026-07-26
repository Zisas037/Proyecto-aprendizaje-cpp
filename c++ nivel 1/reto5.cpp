#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

struct Objetivo{
    std::string nombre;
    std::string alias;
    int recompensa;
};

int main(){
    std::string nombre;
    std::vector<Objetivo>lista={
        {"Damian","El flaco",500},
        {"Vitor","El guapo",2000},
        {"Edgar","El chileno",100},
        {"Lucca","El pigga del norte",800}
    };

    std::cout<<"Ingrese el nombre del criminal a buscar:"<<std::ends;
    std::cin>>nombre;

    auto it=std::find_if(lista.begin(),lista.end(),[nombre](Objetivo& n){
        return n.nombre==nombre;
    });

    if(it!=lista.end()){
        std::cout<<"Se ha encontrado a "<<it->nombre<<" con el alias de "<<it->alias<<" con una recompensa de "<<it->recompensa<<" monedas "<<std::endl;

    }
    else{
        std::cout<<"No se ha encontrado al criminal en la base de datos"<<std::endl;
    }

    return 0;
}