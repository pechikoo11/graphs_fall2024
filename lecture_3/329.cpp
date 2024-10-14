#include <iostream>
#include <vector>

int main() {
    int numberOfSteps;
    std::cin >> numberOfSteps;
    std::vector <int> steps (numberOfSteps + 1, 0);
    std::vector <int> path (numberOfSteps + 1, -1);
    std::vector <int> answ;

    for (int i = 1; i <= numberOfSteps; ++i) {
        std::cin >> steps[i];
    }

    for (int i = 2; i <= numberOfSteps; ++i) {
        if (steps[i-1] >= steps [i-2]) {
            steps[i] += steps[i-1];
            path[i] = i - 1;
        } else {
            steps[i] += steps[i-2];
            path[i] = i - 2;
        }       
    } 

    int step = numberOfSteps;
    while (path[step] != -1) {
        answ.push_back(step);
        step = path[step];
    } 
    if (step != 0) {
        answ.push_back(step);    
    }

    std::cout << steps[numberOfSteps] << '\n';

    for (int i = answ.size() - 1; i >= 0; --i) {
        std::cout << answ[i] << ' ';
    } 
}
