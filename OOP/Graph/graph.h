/**

Graph class implementation header file
Guilherme M. Taglietti

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>

namespace graph{

class Digraph{
private:
    struct node{
        std::string value;
        std::vector<node*> links;
        node(){}
        node(const std::string &val) : value(val){}
    };
    std::unordered_map<std::string, node> nodes;

public:
    Digraph();
    Digraph(const node &n);
    Digraph(const Digraph &other); // Construtor de cópia
    ~Digraph();
    bool insert_node(const std::string &s);
    size_t size() const { return nodes.size(); } // Inline
    node* find(const std::string &s);
    bool insert_link(const std::string &src, const std::string &dest);
    void save2dot(const std::string &s) const;
    void show() const;
    bool remove(const std::string &s);
    size_t indegree(const std::string &s);
    size_t outdegree(const std::string &s);
    size_t degree(const std::string &s) { return indegree(s) + outdegree(s); }
    friend std::ostream& operator<<(std::ostream &os, const Digraph g);
};

} // namespace graph

#endif