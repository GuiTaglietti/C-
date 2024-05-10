/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Implementação das funções membro da classe huffman_tree
 * @file
*/
#include <queue>
#include <vector>
#include <fstream>
#include <codecvt>
#include <locale>

#include "../include/huffman.h"

namespace ED2{

ED2::huffman_tree::huffman_tree(std::wstring text){
    std::unordered_map<wchar_t, int> freq;
    std::priority_queue<ED2::node*, std::vector<ED2::node*>, ED2::cmp> pq;
    for(const wchar_t &ch : text) 
        freq[ch]++;
    for(const auto &pair : freq) 
        pq.push(new ED2::node(pair.first, pair.second, nullptr, nullptr));
    while(pq.size() != 1){
        ED2::node *left = pq.top(); pq.pop();
        ED2::node *right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new ED2::node('\0', sum, left, right));
    }
    root = pq.top();
    encode(root, L"");
}

ED2::huffman_tree::~huffman_tree(){ delete_tree(root); }

void ED2::huffman_tree::delete_tree(node *root){
    if(!root)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void ED2::huffman_tree::encode(ED2::node *root, std::wstring str){
    if(!root)
        return;
    if(!root->left && !root->right)
        huffcode[root->ch] = str;
    encode(root->left, str + L"0");
    encode(root->right, str + L"1");
}

void ED2::huffman_tree::decode(ED2::node *root, int &index, std::wstring str){
    if(!root) 
        return;
    if(!root->left && !root->right){
        std::wcout << root->ch;
        return;
    }
    index++;
    if(str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

void ED2::huffman_tree::show_huffman_codes() const noexcept{
    std::wcout << "Huffman codes:\n";
    for(const auto &p : huffcode)
        std::wcout << p.first << " " << p.second << "\n";
}

void ED2::huffman_tree::show_encoded_string(std::wstring text) noexcept{
    std::wcout << "\nEncoded string:\n";
    std::wstring str;
    for(const wchar_t &ch : text) 
        str += huffcode[ch];
    std::wcout << str << '\n';
}

void ED2::huffman_tree::show_decoded_string(std::wstring str) noexcept{
    std::wcout << "\nDecoded string:\n";
    int idx = -1;
    while(idx < static_cast<int>(str.size()) - 2) 
        decode(root, idx, str);
}

// DESISTI DA IDEIA DO OPERATOR<<
//
// std::wostream& operator<<(std::wostream &os, const ED2::huffman_tree &tree){
//     os << "Códigos de Huffman:\n";
//     for(const auto &p : tree.huffcode) 
//         os << p.first << " " << p.second << "\n";
// }

} // namespace ED2