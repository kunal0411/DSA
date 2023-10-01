#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Depth-First Search (DFS) traversal
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> stack;

        visited[start] = true;
        stack.push(start);

        while (!stack.empty()) {
            int current = stack.top();
            cout << current << " ";
            stack.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create a graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
