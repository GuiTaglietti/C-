#include "../include/graph.h"
#include <iostream>

int main(){
    datastructures::Graph<std::string> g;
    g.insert_node("A", 0, 0);
    g.insert_node("B", 1, 1);
    g.insert_node("C", 2, 2);
    g.insert_node("D", 3, 3);
    g.insert_node("A", "B", 1.5);
    g.insert_node("B", "C", 1.5);
    g.insert_node("C", "D", 1.5);
    g.insert_node("A", "C", 2.5);
    std::string s1 = "A", s2 = "D";
    std::cout << "Distância usando dijkstra de A para D: " << g.dijkstra(s1, s2) << "\n";
    std::cout << "Distância usando A* de A para D: " << g.a_star(s1, s2) << "\n";
    return 0;
}
