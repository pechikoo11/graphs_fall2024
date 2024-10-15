#include <iostream>
#include <set>
 
int main()
{
    int N, M;
    std::cin >> N >> M;
    std::set<std::pair<int, int>> edges;
    for (int i = 0; i < M; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        if (a < b) {
            int c = a;
            a = b;
            b = c;
    } edges.insert({ a, b });
  } std::cout << (edges.size() >= N ? "YES" : "NO");
}
