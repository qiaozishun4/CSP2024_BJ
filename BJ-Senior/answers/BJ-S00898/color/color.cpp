#include <bits/extc++.h>

int main() {
#define int long long
    std::ifstream fin("color.in");
    std::ofstream fout("color.out");
    int t;
    fin >> t;
    while (t--) {
        int n;
        fin >> n;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            fin >> a.at(i);
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int c = 0;
            int red = -1, blue = -1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    if (red != -1 && a.at(j + 1) == a.at(red + 1)) {
                        c += a.at(j + 1);
                    }
                    red = j;
                } else {
                    if (blue != -1 && a.at(j + 1) == a.at(blue + 1)) {
                        c += a.at(j + 1);
                    }
                    blue = j;
                }
            }
            ans = std::max(ans, c);
        }
        fout << ans << std::endl;
    }
    return 0;
}
