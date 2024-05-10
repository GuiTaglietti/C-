/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Arquivo principal para testes usando as classes huffman_tree e file_info
 * @file
*/
#include "src/huffman.cpp"
#include "src/fileinfo.cpp"

int main(){
    std::wstring filename = L"teste.txt";
    std::string filename_utf8(filename.begin(), filename.end());
    /// Por algum motivo tive que usar as duas linhas de cima, se passasse direto a wstring, std::string ou c.str() ele não aceitava...
    std::wifstream file(filename_utf8);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    if(!file){
        std::wcout << L"Arquivo não encontrado!\n";
        exit(1);
    }
    std::wstring text((std::istreambuf_iterator<wchar_t>(file)), std::istreambuf_iterator<wchar_t>());
    std::string urlpath(text.begin(), text.end()); 
    ED2::huffman_tree ht(text);
    ED2::file_info finfo("teste.txt");
    ht.show_huffman_codes();
    ht.show_encoded_string(text);
    finfo.diff();
    short op;
    std::wcout << "\n\nDeseja vizualizar graficamente a árvore de Huffman? (0 - Não | 1 - Sim): "; std::cin >> op;
    switch(op){
        case 0:
            std::wcout << "\nPrograma encerrado!\n";
            break;
        
        case 1:
        {
            [[maybe_unused]] int discard = std::system(std::string("cd pyscript && python3 webhuff.py https://huffman.ooz.ie/?text=" + urlpath).c_str());
            break;
        }

        default:
            std::wcout << "\nOpção inválida!\nEncerrando programa...\n";
            break;
    }
    return 0;
}