#include <iostream>
#include <vector>
#include <algorithm>
 
constexpr int INF = 100000;
 
bool HasNegativeCycle(std::vector<std::vector<int>>& graph) {
    for (int startPoint = 0; startPoint < graph.size(); ++startPoint) {
        for (int endPoint = 0; endPoint < graph.size(); ++endPoint) {
            for (int midPoint = 0; midPoint < graph.size(); ++midPoint) {
                if (graph[startPoint][midPoint] < INF && 
                    graph[midPoint][endPoint] < INF) {
                    graph[startPoint][endPoint] = std::min(graph[startPoint][endPoint],
                    graph[startPoint][midPoint] + graph[midPoint][endPoint]);
                }
            }
        }
    }
 
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[i][i] < 0) return true;
    }
 
    return false;
}
 
int main() {
    int numberOfVertices = 0;
    std::cin >> numberOfVertices;
 
    std::vector<std::vector<int>> graph(numberOfVertices, std::vector<int>(numberOfVertices, INF));
 
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
        std::cin >> graph[i][j];
        }
    }
 
    std::cout << (HasNegativeCycle(graph) ? "YES\n" : "NO\n");
}
