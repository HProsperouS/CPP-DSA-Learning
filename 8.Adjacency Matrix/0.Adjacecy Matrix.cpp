#include <iostream>

using namespace std;    

#define inf -1;

class Graph{
private:
    int **edges;
    int vertices;
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int i, int j, int weight);
    void display();
};

Graph::Graph(int vertices){
    this->vertices = vertices;
    edges = new int*[vertices];
    for(int i = 0; i < vertices; i++){
        edges[i] = new int[vertices];
        for(int j = 0; j < vertices; j++){
            edges[i][j] = inf;
        }
    }
}

Graph::~Graph(){
    for(int i = 0; i < vertices; i++){
        delete[] edges[i];
    }
    delete[] edges;
}

void Graph::addEdge(int i, int j, int weight){
    edges[i][j] = weight;
}

void Graph::display(){
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.display();
    return 0;
}