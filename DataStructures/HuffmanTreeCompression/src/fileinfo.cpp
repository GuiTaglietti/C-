/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Implementação das funções membro da classe file_info
 * @file
*/
#include "../include/fileinfo.h"
#include <fstream>
#include <iomanip>
#include <codecvt>
#include <locale>

namespace ED2{

ED2::file_info::file_info(const std::string &path){
    std::wifstream wif(path);
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::getline(wif, orig, L'\0');
    htree = new huffman_tree(orig);
    for(const wchar_t &ch : orig) 
        encoded += htree->get_huffcode()[ch];
}

ED2::file_info::~file_info(){ delete htree; }

void ED2::file_info::diff() const noexcept{
    double origsz = orig.size() * sizeof(wchar_t),
           encodededsz = encoded.size() / 8.0, /// Cada char é um bit
           df = origsz - encodededsz,
           prcnt = (df / origsz) * 100;
    std::wcout << "Original size: " << origsz << " bytes\n"
               << "Encoded size: " << encodededsz << " bytes\n"
               << "Absolute difference: " << df << " bytes\n"
               << "Percentage difference: " << std::fixed << std::setprecision(2) << prcnt << "%\n";
}

} // namespace ED2