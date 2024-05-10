/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Definição da classe file_info usada para comparar e guardar informações pré e pós compressão de Huffman
 * @headerfile
*/
#ifndef FILEINFO_H
#define FILEINFO_H

#pragma once

#include <iostream>
#include "../include/huffman.h"

namespace ED2{

class file_info{
public:
    file_info(){}
    file_info(const std::string &path);
    virtual ~file_info();
    file_info(const file_info &cpy) = delete;
    file_info& operator=(const file_info& rhs) = delete;

    void diff() const noexcept;

private:
    std::wstring orig;
    std::wstring encoded;
    huffman_tree *htree;
};


} // namespace ED2

#endif