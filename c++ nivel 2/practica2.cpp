 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Mascota{
protected:
    std::string nombre;
    int energia;

    public:
    Mascota(std::string n, int e): nombre(n), energia(e) {}
    virtual void hacerSonido() const{
        std::cout << nombre << " hace un sonido genérico.\n";

    }
    void alimentar(){
        energia+=10;
        if(energia>100) energia=100;
    }

};

class Perro: public Mascota{
    public:
    Perro(std::string n, int e): Mascota(n, e) {}

    void hacerSonido() const override{
        std::cout << nombre << " dice: ¡Guau!\n";

    }

};

class Gato: public Mascota{
    public:
    Gato(std::string n, int e): Mascota(n, e) {}

    void hacerSonido() const override{
        std::cout << nombre << " dice: ¡Miau!\n";
        
    }

};

int main(){

    std::vector<Mascota*> refugio;

    Mascota* perro1 = new Perro("Firulais", 50);
    Mascota* gato1 = new Gato("Michi", 30);
    Mascota* perro2 = new Perro("Rex", 70);
    Mascota* gato2 = new Gato("Garfield", 90);

    refugio.push_back(perro1);
refugio.push_back(gato1);
refugio.push_back(perro2);
refugio.push_back(gato2);

    for(Mascota* mascota : refugio){
        mascota->hacerSonido();
        mascota->alimentar();
    }


    return 0;
}