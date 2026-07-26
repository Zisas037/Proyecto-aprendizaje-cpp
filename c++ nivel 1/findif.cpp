#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Producto{
    std::string nombre;
    float precio;
};



int main(){

    std::vector<Producto> tienda={
        {"Manzana",15.5},
        {"Pan",20.0},
        {"Leche",25.0},
    };

    std::string buscando="Pan";

    auto it= std::find_if(tienda.begin(),tienda.end(),[buscando](Producto& p){
        return p.nombre==buscando;
    });

    if( it!=tienda.end()){
        std::cout<<"Encontrado "<<it->nombre<<"cuesta $"<<it->precio<<std::endl;
    }
    else{
        std::cout<<"El producto no existe en la tienda"<<std::endl;
    }
    
    return 0;
}