#include <iostream>
#include <vector>
#include <queue>
 
int main() {
    int N, S;
    std::cin >> N >> S;
    --S;
    std::vector<std::vector<int>> graph(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool path;
            std::cin >> path;
            if (path) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            } } //зачем такой ужас..
      } std::vector<bool> visits(N, false);
    std::queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : graph[curr]) {
            if (visits[next]) continue;
                q.push(next);
                visits[next] = true;
        } visits[curr] = true;
  } int count = 0;
  for (bool visit : visits) {
      if (visit) ++count;
  } std::cout << count - 1;
}
