#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Objetivo{
    std::string nombre;
    int recompensa;
};

int main(){

    std::vector<Objetivo> lista={
        {"Duende",100},
        {"Dragón",5000},
        {"Orco",500}
    };

    std::sort(lista.begin(),lista.end(), [](const Objetivo& a, const Objetivo& b){
        return a.recompensa < b.recompensa;
    });

    for(const Objetivo& obj: lista){
        std::cout<<obj.nombre<<" - "<<obj.recompensa<<" oro"<<std::endl;
    }

    return 0;
}