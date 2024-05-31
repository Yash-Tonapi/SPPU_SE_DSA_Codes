/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify 
the prominent land marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
private:
    map<string, vector<string> > adjacencyList;
    map<string, vector<string> > adjacencyMatrix;

public:

    void addEdge(string u, string v) {
        adjacencyList[u].push_back(v);
        adjacencyMatrix[u].push_back(v);
        adjacencyMatrix[v].push_back(u); // Assuming an undirected graph
    }

    void DFS(string startNode) {
        map<string, bool> visited;
        stack<string> stack;
        stack.push(startNode);

        while (!stack.empty()) {
            string current = stack.top();
            stack.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                for (string neighbor : adjacencyList[current]){
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
            cout << endl;
        } 
    }

    void BFS(string startNode) {
        map<string, bool> visited;
        queue<string> queue;
        queue.push(startNode);
        visited[startNode] = true;

        while (!queue.empty()) {
            string current = queue.front();
            queue.pop();
            cout << current << " ";

            for (string neighbor : adjacencyList[current]){
                if (!visited[neighbor]) {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph;
    string startNode, u, v;
    char choice;

    do {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        graph.addEdge(u, v);

        cout << "Do you want to add another edge? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "Enter start node for DFS traversal: ";
    cin >> startNode;
    cout << "DFS traversal from " << startNode << ": ";
    graph.DFS(startNode);

    cout << "Enter start node for BFS traversal: ";
    cin >> startNode;
    cout << "BFS traversal from " << startNode << ": ";
    graph.BFS(startNode);

    return 0;
}