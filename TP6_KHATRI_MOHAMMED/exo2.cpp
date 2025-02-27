#include <iostream>
#include <stack> // for DFS
#include <vector> // making the adjacency list
#include <unordered_map> // giving a key to every node
#include <unordered_set> // better for lookup (in this case checking if we already visited the node) 
#include <algorithm> 

using namespace std;

struct Node {
    int data;
    vector<Node*> next; // a set of pointers to the next nodes
};

struct Graph {
    unordered_map<int, Node*> nodes;
    // a map of all the nodes in the graph
    // this approach allows for constant time lookup of nodes by their data

    void addEdge(int src, int dest) {
        // adding an edge knowing the key to the node
        if (nodes.find(src) == nodes.end())
            nodes[src] = new Node{src}; // make it if it's not there
        if (nodes.find(dest) == nodes.end())
            nodes[dest] = new Node{dest}; // same

        // easily adding the edge:
        // go to src and add dest to its next
        nodes[src]->next.push_back(nodes[dest]);
    }

    void deleteEdge(int src, int dest) {
        // deleting an edge knowing the key to the node
        if (nodes.find(src) == nodes.end() || nodes.find(dest) == nodes.end()) {
            cerr << "Edge does not exist!" << endl;
            return;
        }

        Node* srcNode = nodes[src];

        auto& neighbors = srcNode->next;
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), nodes[dest]), neighbors.end());
    }

    void DFS_Iterative(int start) {
        if (nodes.find(start) == nodes.end()) {
            cout << "Start node not found in graph." << endl;
            return;
        }

        unordered_set<int> visited;
        stack<int> s;
        s.push(start);

        cout << "Parcours en profondeur à partir du sommet " << start << ": " << endl;

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited.count(node)) {
                cout << node << " ";
                visited.insert(node);

                // Push all unvisited neighbors onto the stack (in reverse order for correct order)
                for (auto it = nodes[node]->next.rbegin(); it != nodes[node]->next.rend(); ++it) {
                    if (!visited.count((*it)->data)) {
                        s.push((*it)->data);
                    }
                }
            }
        }
        cout << endl;
    }

    // deconstructor
    ~Graph() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
        nodes.clear();
    }
};

int main() {
    Graph graph;
    // let's fill the graph
    // it has the structure
    // 0 ->  1 
    // ^    | ^
    // |    v |
    // 3 <-  2 
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.DFS_Iterative(0);

    return 0;
}