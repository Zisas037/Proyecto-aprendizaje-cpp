#include <iostream>

struct Armadura{
    int durabilidad;
    int durabilidadMaxima;
};

int repararArmadura(Armadura& armadura, int puntos){
    armadura.durabilidad+=puntos;
    if(armadura.durabilidad>armadura.durabilidadMaxima){ 
        armadura.durabilidad=armadura.durabilidadMaxima;

    }
    return armadura.durabilidad;

}

int main(){
    Armadura armadura1{20,100};
    std::cout<<"Durabilidad actual: "<<armadura1.durabilidad<<std::endl;
    repararArmadura(armadura1,50);
    std::cout<<"Durabilidad con reparacion:" <<armadura1.durabilidad<<std::endl;

    return 0;
}