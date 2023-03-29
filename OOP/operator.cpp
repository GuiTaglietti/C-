#include <iostream>

// Arquivo .hpp

class Teste{
private:
    int x;
    int y;

public:
    Teste(int v1, int v2){
        this->x = v1;
        this->y = v2;
    };
    Teste(){};
    void setX(int v);
    int getX();
    void setY(int v);
    int getY();
    int operator*(Teste v);
    void operator<<(Teste v);
};

// Arquivo .cpp

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

/*
    Método de sobrecarga de operador que atribui ao 
    primeiro operando o valor da soma do ponto X
    do primeiro com o segundo operando e repete o processo
    com o ponto Y

    Ex: teste1 << teste2
    
    Nesse caso o valor X em teste1 recebe teste1.getX + teste2.getX
    repetindo o processo com o Y
*/
void Teste::operator<<(Teste v){
    this->setX(this->getX() + v.getX());
    this->setY(this->getY() + v.getY());
}

// Arquivo que a classe será instânciada

int main(){
    Teste t1(10, 20), t2(20, 40);
    // Testando operador sobrecarregado *
    std::cout << t1 * t2 << std::endl;
    
    // Testando operador sobrecarregado <<
    std::cout << "Valor do X antes de usar a operação: " << t1.getX() << std::endl;
    std::cout << "Valor do Y antes de usar a operação: " << t1.getY() << std::endl;
    std::cout << std::endl;
    t1 << t2;
    std::cout << "Valor do X após usar a operação: " << t1.getX() << std::endl;
    std::cout << "Valor do Y após usar a operação: " << t1.getY() << std::endl;
    std::cout << std::endl;
    return 0;
}
