#include <iostream>
#include <vector>
#include <queue>

int main() {
    int numberOfVertices, startPoint, endPoint;
    std::cin >> numberOfVertices >> startPoint >> endPoint;
    startPoint--;
    endPoint--;
    std::vector <std::vector <int>> adjacencyTable(numberOfVertices,std::vector <int> (numberOfVertices,-1));
    std::priority_queue <std::pair <int, int>> paths;
    std::vector <int> lenghts (numberOfVertices, -1);

    paths.push({0, startPoint});

    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            std::cin >> adjacencyTable[i][j];
        }  
    }

    while (!paths.empty()){
        auto current = paths.top();
        current.first *= -1;
        paths.pop();
        if(lenghts[current.second] != -1) continue;
        lenghts[current.second] = current.first; 

        for (int i = 0; i < numberOfVertices; ++i) {
            if (adjacencyTable[current.second][i] != -1 && lenghts[i] == -1 && i != current.second) {
                paths.push({-current.first - adjacencyTable[current.second][i], i});
            } 
        } 
    } 
    std::cout << lenghts[endPoint];
}
