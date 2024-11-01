#include <bits/stdc++.h>

int main() {
    std::ifstream fin("duel.in");
    std::ofstream fout("duel.out");
//#define fin std::cin
//#define fout std::cout
    int n;
    fin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> a.at(i);
    }
    std::sort(a.begin() + 1, a.begin() + n + 1);
    int lst = 1;
    int ans = n;
    for (int i = 2; i <= n; ++i) {
        if (a.at(i) > a.at(lst)) {
            ++lst;
            --ans;
        }
    }
    fout << ans << std::endl;
    return 0;
}
