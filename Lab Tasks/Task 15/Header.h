#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int numVertices;
    int** adjMatrix;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix = new int* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    int getNumVertices() const {
        return numVertices;
    }

    void addVertex() {
        int** newMatrix = new int* [numVertices + 1];
        for (int i = 0; i < numVertices + 1; i++) {
            newMatrix[i] = new int[numVertices + 1];
            for (int j = 0; j < numVertices + 1; j++) {
                if (i < numVertices && j < numVertices) {
                    newMatrix[i][j] = adjMatrix[i][j];
                }
                else {
                    newMatrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        adjMatrix = newMatrix;
        numVertices++;
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjMatrix[src][dest] = 1;
        }
    }

    void bfsTraversal(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }

    void dfsTraversal(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        stack<int> s;
        visited[startVertex] = true;
        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();
            cout << currentVertex << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }

        delete[] visited;
    }
};