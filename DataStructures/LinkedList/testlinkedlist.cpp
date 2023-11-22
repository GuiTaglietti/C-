#include "linkedlist.h"

int main(){
    datastructures::LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Lista: ";
    for(const auto &e : list)
        std::cout << e << " ";
    std::cout << std::endl 
    << "Tamanho: " << list.size() << std::endl
    << "Possui o 3? " << ((list.find(3) != list.end()) ? "Sim!" : "Não!") << std::endl
    << "Possui o 5? " << ((list.find(5) != list.end()) ? "Sim!" : "Não!") << std::endl;

    list.erase(3);

    std::cout << "Lista: ";
    for(const auto &e : list)
        std::cout << e << " ";
    std::cout << std::endl 
    << "Tamanho: " << list.size() << std::endl
    << "Possui o 3? " << ((list.find(3) != list.end()) ? "Sim!" : "Não!") << std::endl
    << "Possui o 5? " << ((list.find(5) != list.end()) ? "Sim!" : "Não!") << std::endl;

    return 0;
}
