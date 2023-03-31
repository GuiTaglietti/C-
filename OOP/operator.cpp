#include <iostream>

// Arquivo .hpp

class Teste{
private:
    int x;
    int y;

public:
    Teste(int v1, int v2);
    Teste();
    void setX(int v);
    int getX();
    void setY(int v);
    int getY();
    int operator*(Teste v);
};

// Arquivo .cpp

Teste::Teste(){};
Teste::Teste(int v1, int v2){
    this->x = v1;
    this->y = v2;
}
void Teste::setX(int v) { this->x = v; }
int Teste::getX() { return this->x; }
void Teste::setY(int v) { this->y = v; }
int Teste::getY() { return this->y; }

/*
    Método simples para sobrecarregar o operador de multiplicação
    como forma de teste, retornando o produto da soma dos pontos X e Y
*/

int Teste::operator*(Teste v){
    return ((this->getX() + v.getX()) * (this->getY() + v.getY()));
}

// Arquivo que a classe será instânciada

int main(){
    Teste t1(10, 20), t2(20, 40);
    // Testando operador sobrecarregado *
    std::cout << t1 * t2 << std::endl;
    return 0;
}
