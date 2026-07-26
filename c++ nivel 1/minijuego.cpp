#include <iostream>

struct Personaje{
    std::string nombre;
    int vida;
    int stamina;
    int ataqueBase;
};

void mostrar(Personaje& pj){
    std::cout<<"     Nombre: "<<pj.nombre<<std::endl;
    std::cout<<"       Vida: "<<pj.vida<<std::endl;
    std::cout<<"    Stamina: "<<pj.stamina<<std::endl;
    std::cout<<"Ataque base: "<<pj.ataqueBase<<std::endl;
}

int ataque(Personaje& atacante, Personaje& objetivo, int stamina){
    if(stamina>=10){
        atacante.stamina-=10;
        objetivo.vida-=atacante.ataqueBase;
        std::cout<<atacante.nombre<<" ha atacado a "<<objetivo.nombre<<" con un ataque de "<<atacante.ataqueBase<<" de daño"<<std::endl;
        std::cout<<objetivo.nombre<<" tiene "<<objetivo.vida<<" de vida"<<std::endl;
    }

    return objetivo.vida;
}

void recuperar(Personaje& pj){
    if(pj.stamina>=5){
        pj.stamina-=5;
        pj.stamina+=20;
        pj.vida+=20;
        std::cout<<pj.nombre<<" se ha recuperado"<<std::endl;

    }
}

void turnos(int turno){
    if(turno==1){
        std::cout<<"==Turno del heroe=="<<std::endl;

    }
    else if(turno==2){
        std::cout<<"==Turno del jefe=="<<std::endl;
    }
}

int main(){
    int turno=1;
    int opc;
    Personaje heroe{"Heroe",100,100,20};
    Personaje jefe{"Jefe",100, 100, 15};

    while(heroe.vida>0 && jefe.vida>0){
       turnos(turno);
        if (turno==1){
        mostrar(heroe);
        std::cout<<"Ingrese 1 para atacar o 2 para recuperar: "<<std::ends;
        std::cin>>opc;
        if(opc==1){
            ataque(heroe,jefe,heroe.stamina);
        }
        else if(opc==2){
            recuperar(heroe);
        }
        turno=2;
    }


      if (turno==2){
        mostrar(jefe);
        
            ataque(jefe,heroe,jefe.stamina);
      
        turno=1;
    }

    }

    if(heroe.vida<=0){
        std::cout<<"El heroe ha sido derrotado"<<std::endl;
    }
    else{
        std::cout<<"El jefe ha sido derrotado"<<std::endl;
    }


    return 0;
}