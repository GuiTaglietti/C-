#include <iostream>
#include "graph.cpp"

int main(){
  graph::Digraph g;

  g.insert_node("A");
  g.insert_node("B");
  g.insert_node("C");
  g.insert_node("D");
  g.insert_node("E");
  g.insert_node("X Y");
  std::cout << g.size() << " nodes\n";

  auto p=g.find("A");  
  if(p) std::cout << "Found " << p->value << std::endl;
  else std::cout << "Not found\n";

  g.insert_link("A", "B");
  g.insert_link("A", "C");
  g.insert_link("C", "B");
  g.insert_link("E", "B");
  g.insert_link("B", "D");

  g.remove("E");

  std::cout << "Outdegree: " << g.outdegree("B") << std::endl;
  std::cout << "Indegree: " << g.indegree("B") << std::endl;
  std::cout << "Degree: " << g.degree("B") << std::endl;

  // Testando a sobrecarga do operador
  
  std::cout << g; // Deverá mostrar o grafo com o show()
  std::ofstream teste("teste.txt");
  teste << g; // Devera inserir no arquivo o grafo
  return 0;
}
