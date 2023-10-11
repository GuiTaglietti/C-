#include "memoryalloc.cpp"
using namespace SO2;

#define RANDS_MAX_SIZE 10

int main(){
    memoryalloc ma; int rands[RANDS_MAX_SIZE];
    charge_random_values(rands, (size_t)RANDS_MAX_SIZE);
    std::cout << "===== Gerenciador de memoria por particoes dinamicas =====" << std::endl << std::endl;
    std::cout << "===== Algoritmo First-fit! =====" << std::endl << std::endl;
    std::cout << "Original " << ma << std::endl;
    for(size_t i = 0; i < RANDS_MAX_SIZE; i++){
        SO2::memoryalloc::aloc_report tempff = ma.first_fit(rands[i]);
        if(!tempff.is_allocated) std::cout << "[" << i << " - " << rands[i] << "] \33[1m Solicitacao nao pode ser atendida \33[0m" << std::endl;
        else if(tempff.is_perfect_fit) std::cout << "[" << i << " - " << rands[i] << "] " << ma << " \33[1m Encaixe perfeito \33[0m" << std::endl;
        else std::cout << "[" << i << " - " << rands[i] << "] " << ma << std::endl;
    }
    std::cout << std::endl << "===== Algoritmo Best-fit! =====" << std::endl << std::endl;
    std::cout << "Original " << ma << std::endl;
    for(size_t i = 0; i < RANDS_MAX_SIZE; i++){
        SO2::memoryalloc::aloc_report tempbf = ma.best_fit(rands[i]);
        if(!tempbf.is_allocated) std::cout << "[" << i << " - " << rands[i] << "] \33[1m Solicitacao nao pode ser atendida \33[0m" << std::endl;
        else if(tempbf.is_perfect_fit) std::cout << "[" << i << " - " << rands[i] << "] " << ma << " \33[1m Encaixe perfeito \33[0m" << std::endl;
        else std::cout << "[" << i << " - " << rands[i] << "] " << ma << std::endl;
    }
    std::cout << std::endl  << "===== Algoritmo Worst-fit! =====" << std::endl << std::endl;
    std::cout << "Original " << ma << std::endl;
    for(size_t i = 0; i < RANDS_MAX_SIZE; i++){
        SO2::memoryalloc::aloc_report tempwf = ma.worst_fit(rands[i]);
        if(!tempwf.is_allocated) std::cout << "[" << i << " - " << rands[i] << "] \33[1m Solicitacao nao pode ser atendida \33[0m" << std::endl;
        else if(tempwf.is_perfect_fit) std::cout << "[" << i << " - " << rands[i] << "] " << ma << " \33[1m Encaixe perfeito \33[0m" << std::endl;
        else std::cout << "[" << i << " - " << rands[i] << "] " << ma << std::endl;
    }
    std::cout << std::endl  << "===== Algoritmo Next-fit! =====" << std::endl << std::endl;
    std::cout << "Original " << ma << std::endl;
    for(size_t i = 0; i < RANDS_MAX_SIZE; i++){
        SO2::memoryalloc::aloc_report tempnf = ma.next_fit(rands[i]);
        if(!tempnf.is_allocated) std::cout << "[" << i << " - " << rands[i] << "] \33[1m Solicitacao nao pode ser atendida \33[0m" << std::endl;
        else if(tempnf.is_perfect_fit) std::cout << "[" << i << " - " << rands[i] << "] " << ma << " \33[1m Encaixe perfeito \33[0m" << std::endl;
        else std::cout << "[" << i << " - " << rands[i] << "] " << ma << std::endl;
    }
    return 0; 
}