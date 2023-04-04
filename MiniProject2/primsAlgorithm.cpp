#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define INF 10000


using namespace std;
typedef pair<int, int> intPair;


class Graph {
    // number of vertices
    int Vertex;
    // Adjacency list representation Pair of a neighbor vertex and a weight for
    // every edge
    list<intPair>* adj;

public:
    // Allocates memory for adjacency list
    Graph(int V) {
        this->Vertex = V + 1;
        adj = new list<intPair>[V + 1];
    }

    // Function to add an edge to graph
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Print MST using Prim's algorithm
    void primMST() {

        // prirority queue to store vertices
        priority_queue<intPair, vector<intPair>, greater<intPair>> pq;

        int source = 0; // vertex start with 0 for the source

        // Vector for keys and initialize it
        vector<int> key(Vertex, INF);

        // For storing parent array which stores MST
        vector<int> parent(Vertex, -1);

        // Keeping track of vertices
        vector<bool> inMST(Vertex, false);

        // To put the source in the priority queue
        pq.push(make_pair(0, source));
        key[source] = 0;

        // To loop priority queue until it becomes empty
        while (!pq.empty()) {

            // For storing vertext in second of par
            int value = pq.top().second;
            pq.pop();

            // For handling different key values for same vertices
            if (inMST[value] == true) { // process the least key values first
                continue;                      // ignore the rest of the values
            }


            // To put vertex in MST
            inMST[value] = true;

            // TO get all the adjacent vertices of the vertex
            list< pair<int, int> >::iterator i;
            for (i = adj[value].begin(); i != adj[value].end(); ++i)
            {

                // To get vertext of current adjacent
                int k = (*i).first;
                int weight = (*i).second;

                // When k is not in MST and weight of (u,v) is smaller than key of K
                if (inMST[k] == false && key[k] > weight) {

                    // To update key
                    key[value] = weight;
                    pq.push(make_pair(key[k], k));
                    parent[k] = value;
                }
            }
        }
        // To print the edges of MST
        for (int i = 1; i < Vertex; ++i) {
            cout << parent[i] << " - " << i << endl;
        }
    }
};

int main() {

    // Tests the program
    int V = 8;
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 9);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 2, 12);
    g.addEdge(4, 7, 8);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 3);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 3);
    g.addEdge(6, 7, 15);
    g.addEdge(6, 8, 11);
    g.addEdge(7, 8, 10);

    g.primMST();

    cin.get();
}
