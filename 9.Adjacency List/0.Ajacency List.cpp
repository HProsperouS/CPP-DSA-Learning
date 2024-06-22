#include <iostream>

using namespace std;

class Graph{
private:
    struct EdgeNode{
        int vertex;
        int weight;
        EdgeNode *next;
    };

    struct VertexNode{
        int vertex;
        EdgeNode *firstEdge;
    };

    int vertices;
    VertexNode *nodes;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int i, int j, int w);
    void display();
};

Graph::Graph(int vertices){
    this->vertices = vertices;
    this->nodes = new VertexNode[vertices];
    for(int i = 0; i < vertices; i++){
        nodes[i].vertex = i;
        nodes[i].firstEdge = NULL;
    }
}

Graph::~Graph(){
    for(int i = 0; i < vertices; i++){
        EdgeNode *edge = nodes[i].firstEdge;
        while(edge != NULL){
            EdgeNode *temp = edge;
            edge = edge->next;
            delete temp;
        }
    }
    delete[] nodes;
}


void Graph::addEdge(int i, int j, int w){
    EdgeNode *edge = new EdgeNode;
    edge->vertex = j;
    edge->weight = w;
    edge->next = nodes[i].firstEdge;
    nodes[i].firstEdge = edge;
}

void Graph::display(){
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i << " is connected to: ";
        EdgeNode *edge = nodes[i].firstEdge;
        while(edge != NULL){
            cout << edge->vertex << "(" << edge->weight << ") ";
            edge = edge->next;
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