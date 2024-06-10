#include <cmath>
#include <queue>
#include <unordered_map>
#include <limits>
#include <vector>
#include <utility>

namespace datastructures{

template<class T>
class Graph {
public:
    explicit Graph() noexcept = default;
    explicit Graph(const Graph &cpy) noexcept;
    virtual ~Graph();
    Graph<T>& operator=(const Graph<T> &rhs);

    bool insert_node(const T &_val, double _x = 0, double _y = 0) noexcept;
    bool insert_node(const T &_src, const T &_dest) noexcept;
    bool insert_node(const T &_src, const T &_dest, double _cost) noexcept;
    typename Graph<T>::Node* find(const T &_val) const noexcept;
    double dijkstra(const T &_src, const T &_dest) noexcept;
    double a_star(const T &_src, const T &_dest) noexcept;

private:
    struct Node{
        T val;
        double x, y;
        std::vector<std::pair<Node*, double>> adj;

        explicit Node(const T &_val, double _x = 0, double _y = 0) noexcept : val(_val), x(_x), y(_y){}

        explicit Node(const T &_val, const Node* _node, double _x = 0, double _y = 0) noexcept : val(_val), x(_x), y(_y){
            adj.push_back({_node, 1});
        }

        explicit Node(const T &_val, const Node* _node, double _cost, double _x = 0, double _y = 0) noexcept : val(_val), x(_x), y(_y){
            adj.push_back({_node, _cost});
        }
    };
    std::unordered_map<T, Node*> nodes;
};

template<class T>
Graph<T>::Graph(const Graph &cpy) noexcept{
    for(const auto& [val, node] : cpy.nodes) 
        nodes[val] = new Node(*node);
    for(const auto& [val, node] : cpy.nodes) 
        for(const auto& [adjNode, cost] : node->adj) 
            nodes[val]->adj.push_back({nodes[adjNode->val], cost});
}

template<class T>
Graph<T>::~Graph(){
    for(auto& [val, node] : nodes) 
        delete node;
}

template<class T>
Graph<T>& Graph<T>::operator=(const Graph<T> &rhs){
    if(this == &rhs) 
        return *this;
    for(auto& [val, node] : nodes)
        delete node;
    nodes.clear();
    for(const auto& [val, node] : rhs.nodes) 
        nodes[val] = new Node(*node);
    for(const auto& [val, node] : rhs.nodes) 
        for(const auto& [adjNode, cost] : node->adj) 
            nodes[val]->adj.push_back({nodes[adjNode->val], cost});
    return *this;
}

template<class T>
bool Graph<T>::insert_node(const T &_val, double _x, double _y) noexcept {
    if(nodes.find(_val) != nodes.end()) 
        return false;
    nodes[_val] = new Node(_val, _x, _y);
    return true;
}

template<class T>
inline bool Graph<T>::insert_node(const T &_src, const T &_dest) noexcept{
    return insert_node(_src, _dest, 1.0);
}

template<class T>
bool Graph<T>::insert_node(const T &_src, const T &_dest, double _cost) noexcept{
    if(nodes.find(_src) == nodes.end()) 
        nodes[_src] = new Node(_src);
    if(nodes.find(_dest) == nodes.end()) 
        nodes[_dest] = new Node(_dest);
    nodes[_src]->adj.push_back({nodes[_dest], _cost});
    return true;
}

template<class T>
typename Graph<T>::Node* Graph<T>::find(const T &_val) const noexcept{
    auto it = nodes.find(_val);
    return it != nodes.end() ? it->second : nullptr;
}

template<class T>
double Graph<T>::dijkstra(const T &_src, const T &_dest) noexcept {
    if(nodes.find(_src) == nodes.end() || nodes.find(_dest) == nodes.end()) 
        return std::numeric_limits<double>::infinity();
    std::unordered_map<Node*, double> dist;
    std::unordered_map<Node*, Node*> prev;
    auto cmp = [](const std::pair<Node*, double>& left, const std::pair<Node*, double>& right) { return left.second > right.second; };
    std::priority_queue<std::pair<Node*, double>, std::vector<std::pair<Node*, double>>, decltype(cmp)> pq(cmp);
    for(const auto& [val, node] : nodes){
        dist[node] = std::numeric_limits<double>::infinity();
        prev[node] = nullptr;
    }
    dist[nodes[_src]] = 0;
    pq.push({nodes[_src], 0});
    while(!pq.empty()){
        auto [current, currentDist] = pq.top();
        pq.pop();
        if(current == nodes[_dest]) 
            break;
        for(const auto& [neighbor, cost] : current->adj){
            double newDist = currentDist + cost;
            if(newDist < dist[neighbor]){
                dist[neighbor] = newDist;
                prev[neighbor] = current;
                pq.push({neighbor, newDist});
            }
        }
    }
    return dist[nodes[_dest]];
}

template<class T>
double Graph<T>::a_star(const T &_src, const T &_dest) noexcept {
    if(nodes.find(_src) == nodes.end() || nodes.find(_dest) == nodes.end()) 
        return std::numeric_limits<double>::infinity();
    auto heuristic = [](const Node* a, const Node* b){
        double dx = a->x - b->x;
        double dy = a->y - b->y;
        return std::sqrt(dx * dx + dy * dy);
    };
    std::unordered_map<Node*, double> dist;
    std::unordered_map<Node*, double> fScore;
    std::unordered_map<Node*, Node*> prev;
    auto cmp = [&fScore](Node* left, Node* right) { return fScore[left] > fScore[right]; };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openSet(cmp);
    for(const auto& [val, node] : nodes){
        dist[node] = std::numeric_limits<double>::infinity();
        fScore[node] = std::numeric_limits<double>::infinity();
        prev[node] = nullptr;
    }
    dist[nodes[_src]] = 0;
    fScore[nodes[_src]] = heuristic(nodes[_src], nodes[_dest]);
    openSet.push(nodes[_src]);
    while(!openSet.empty()){
        Node* current = openSet.top();
        openSet.pop();
        if(current == nodes[_dest]) 
            break;
        for(const auto& [neighbor, cost] : current->adj){
            double tentativeGScore = dist[current] + cost;
            if(tentativeGScore < dist[neighbor]){
                prev[neighbor] = current;
                dist[neighbor] = tentativeGScore;
                fScore[neighbor] = dist[neighbor] + heuristic(neighbor, nodes[_dest]);
                openSet.push(neighbor);
            }
        }
    }
    return dist[nodes[_dest]];
}

} // namespace datastructures