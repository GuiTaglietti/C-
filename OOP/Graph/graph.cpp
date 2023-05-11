/**

Graph class implementation cpp file
Guilherme M. Taglietti

*/

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "graph.h"

namespace graph{

    graph::Digraph::Digraph(){}

    // Dúvida: Como delegar o construtor de uma classe para o de uma struct?
    graph::Digraph::Digraph(const node &n){
        node(n.value);
    }

    // Construtor de cópia
    graph::Digraph::Digraph(const Digraph &other){
        nodes = other.nodes;
    }

    graph::Digraph::~Digraph(){}

    bool graph::Digraph::insert_node(const std::string &s){
        if(nodes.count(s) > 0) return false;  
        node n(s);                                                        
        nodes[s] = n;                          
        return true;
    }

    graph::Digraph::node* graph::Digraph::find(const std::string &s){
        auto it = nodes.find(s);
        return it == nodes.end() ? nullptr : &it->second;
    }

    bool graph::Digraph::insert_link(const std::string &src, const std::string &dest){
        auto psrc = find(src);
        auto pdest = find(dest);
        if(!psrc || !pdest) return false;
        if(psrc->links.size() > 0){
            for(int i = 0; i < psrc->links.size(); i++){
                if(psrc->links[i]->value == pdest->value) return false;
            }
        }
        psrc->links.push_back(pdest);
        return true;
    }

    void graph::Digraph::save2dot(const std::string &filename) const{
        std::ofstream dot(filename);
        dot << "digraph{\n";
        for (auto n : nodes) {
            dot << "\t\"" << n.first << '"';
            if(!n.second.links.empty()){
                dot << " -> { ";
                for(auto link: n.second.links){
                    dot << '"' << link->value << "\" ";
                }
                dot << "}";
            }
            dot << "\n";
        }
        dot << "}\n";
    }

    void graph::Digraph::show() const{
        save2dot("temp.dot");
        std::system("dot -Tx11 temp.dot");
    }

    bool graph::Digraph::remove(const std::string &s){
        auto temp = find(s);
        if(!temp) return false;
        for(auto n : nodes){
            auto links = n.second.links;
            for(auto it = links.begin(); it != links.end();){
                if((*it)->value == s) it = links.erase(it); // Tive que usar conversão implícita para transformar em ponteiro pra classe
                else ++it;
            }
        }
        nodes.erase(s);
        return true;
    }

    size_t graph::Digraph::indegree(const std::string &s){
        size_t count = 0;
        for(auto n : nodes)
            for (auto &link : n.second.links) 
                if (link->value == s) count++;
        return count;
    }

    size_t graph::Digraph::outdegree(const std::string &s){
        auto pnode = find(s);
        if(!pnode) return 0;
        return pnode->links.size();
    }

    // Não funciona a identificação do cout :(
    std::ostream& operator<<(std::ostream &os, const Digraph g){
        // Identifica se é um fluxo de cout ou de arquivo
        if(!dynamic_cast<std::ostream*>(&std::cout)){
            os << "digraph{\n";
            for(auto n : g.nodes){
                os << "\t\"" << n.first << '"';
                if(!n.second.links.empty()){
                    os << " -> { ";
                    for(auto link: n.second.links){
                        os << '"' << link->value << "\" ";
                    }
                    os << "}";
                }
                os << "\n";
            }
            os << "}\n";
            return os;
        }
        g.show();
        return os;
    }
}