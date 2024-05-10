/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Definição da classe da árvore de Huffman
 * @headerfile
*/
#ifndef HUFFMAN_H
#define HUFFMAN_H

#pragma once

#include <iostream>
#include <unordered_map>

#include "node.h"

namespace ED2{

/// @brief Usando a nomenclatura "padrão" da STL, com os nomes em minúsculo
///        Ex: unordered_map
class huffman_tree{
public:
    huffman_tree(){}
    huffman_tree(std::wstring text);
    virtual ~huffman_tree();
    huffman_tree(const huffman_tree &cpy) = delete;
    huffman_tree& operator=(const huffman_tree& rhs) = delete;
    
    // friend std::wostream& operator<<(std::wostream &os, const huffman_tree &tree);

    void show_huffman_codes() const noexcept;
    void show_encoded_string(std::wstring text) noexcept;
    void show_decoded_string(std::wstring str) noexcept;
    [[nodiscard]] std::unordered_map<wchar_t, std::wstring> get_huffcode() const noexcept { return huffcode; } /// Inline

private:
    ED2::node* root;
    std::unordered_map<wchar_t, std::wstring> huffcode;
    void encode(ED2::node *root, std::wstring str);
    void decode(ED2::node *root, int &index, std::wstring str);
    void delete_tree(node *root);
};

} // namespace ED2

#endif