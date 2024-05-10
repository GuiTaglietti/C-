/**
 * @author Guilherme Martinelli Taglietti
 * @brief  Definição da struct do node da árvore de huffman em um arquivo separado
 * @headerfile
*/
#ifndef NODE_H
#define NODE_H

#pragma once

namespace ED2{

class node{
public:
    wchar_t ch;
    int freq;
    node *left, *right;
    node(){}
    node(wchar_t _ch, int _freq, node *_left, node *_right) : ch(_ch), freq(_freq), left(_left), right(_right){}
};

struct cmp{
    bool operator()(node *l, node *r) const { return l->freq > r->freq; } /// Inline
};

} // Namespace ED2

#endif