#include "src/hd.cpp"
using namespace SO2;

void display_info(const HardDisk &hd) noexcept{
    std::vector<int> temp = hd.get_req_buffer();
    std::cout << std::endl << "Posição inicial da cabeça de leitura e gravação: " << hd.get_head_ptr() << std::endl;
    std::cout << "Original: [";
    for(std::size_t i = 0; i < (std::size_t)MAX_REQUISITONS - 1; i++)
        std::cout << temp[i] << " - ";
    std::cout << temp.back() << "]" << std::endl << std::endl; 
}

int main(){
    std::cout << std::endl << "===== Gerenciador de escalonamento de acesso a disco =====" << std::endl;
    HardDisk hd;
    // hd.debug(); --> Usa os valores mostrados na explicação do TDE
    display_info(hd);
    hd.FCFS();
    display_info(hd);
    hd.SSTF();
    display_info(hd);
    hd.SCAN();
    display_info(hd);
    hd.CSCAN();
    display_info(hd);
    hd.CLOOK();
    return 0;
}