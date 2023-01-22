#include<iostream>
#include<queue>
using namespace std;

const int MAX_NODES = 5;

int Matrix[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int numnodes;

void initGraph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            Matrix[i][j] = 0;
        }
    }
}

void addEdge(int from, int to) {
    Matrix[from][to] = 1;
}

void removeEdge(int from, int to) {
    Matrix[from][to] = 0;
}

bool isAdjacent(int from, int to) {
    return Matrix[from][to] == 1;
}
void BFS(int startnode) {
    int size = 5;
    queue<int> q;
    q.push(startnode);
    visited[startnode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

    cout << currentNode << " ";

        for (int i = 0; i < numnodes; i++) {
            if (Matrix[currentNode][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }

        }
  }
}

void displayGraph() {
    for (int i = 0; i < numnodes; i++) {
        for (int j = 0; j < numnodes; j++) {
            cout << Matrix[i][j] << " ";
        }
     cout << endl;
    }
}

int main() {
    initGraph();
    numnodes = 4;
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(3, 2);
    int startnode;
    cin >> startnode;
    BFS(startnode);
    cout << "Adjacency Matrix:" << endl;
    displayGraph();
    return 0;
}