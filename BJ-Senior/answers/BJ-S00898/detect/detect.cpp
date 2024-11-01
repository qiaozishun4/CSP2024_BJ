#include <bits/extc++.h>

int main() {
#define int long long
    std::ifstream fin("detect.in");
    std::ofstream fout("detect.out");
    int t;
    fin >> t;
    while (t--) {
        int n, m, L, V;
        fin >> n >> m >> L >> V;
        if (n <= 20 && m <= 20) {
            V *= V;
            std::vector<std::tuple<int, int, int>> cars{{0, 0, 0}};
            for (int i = 1; i <= n; ++i) {
                int d, v, a;
                fin >> d >> v >> a;
                cars.emplace_back(d, v, a);
            }
            std::vector<std::vector<int>> p(m + 1);
            std::set<int> s;
            for (int i = 1; i <= m; ++i) {
                int pos;
                fin >> pos;
                for (int j = 1; j <= n; ++j) {
                    int d = std::get<0>(cars.at(j));
                    int v = std::get<1>(cars.at(j));
                    int a = std::get<2>(cars.at(j));
                    if (pos < d) {
                        continue;
                    }
                    int vt = v * v + 2 * a * (pos - d);
                    if (vt > V) {
                        p.at(i).push_back(j);
                        s.insert(j);
                    }
                }
            }
            int ans = s.size();
            int ans2 = 0;
            for (int i = 0; i < (1 << m); ++i) {
                std::set<int> tmp;
                int now = m;
                for (int j = 0; j < m; ++j) {
                    if ((i >> j) & 1) {
                        --now;
                        for (auto &&item: p.at(j + 1)) {
                            tmp.insert(item);
                        }
                    }
                }
                if (ans == tmp.size()) {
                    ans2 = std::max(ans2, now);
                }
            }
            fout << ans << " " << ans2 << std::endl;
            continue;
        }
        int d, v, a;
        fin >> d >> v >> a;
        if (a > 0) {
            std::vector<std::pair<int, int>> pos;
            std::vector<int> pos2;
            auto add = [&](int d, int v, int a) {
                if (v > V) {
                    pos2.push_back(d);
                    return;
                }
                if (v == V) {
                    pos.emplace_back(d, 1);
                    return;
                }
                if (V * V - v * v + 2 * a * d <= 2 * L * a) {
                    pos.emplace_back(V * v - v * v + 2 * a * d, 2 * a);
                }   
            };
            add(d, v, a);
            for (int i = 2; i <= n; ++i) {
                int d, v, a;
                fin >> d >> v >> a;
                add(d, v, a);
            }
            std::vector<int> p(m + 1);
            for (int i = 1; i <= m; ++i) {
                fin >> p.at(i);
            }
            int ans = 0;
            for (auto &&item: pos) {
                int a = item.first;
                int b = item.second;
                if (a < b * p.at(m)) {
                    ++ans;
                }
            }
            for (auto &&item: pos2) {
                if (item <= p.at(m)) {
                    ++ans;
                }
            }
            fout << ans << " " << (ans == 0 ? m : m - 1) << std::endl;
        }
        if (a == 0) {
            std::vector<int> pos;
            auto add = [&](int d, int v, int a) {
                if (v > V) {
                    pos.push_back(d);
                }
            };
            add(d, v, a);
            for (int i = 2; i <= n; ++i) {
                int d, v, a;
                fin >> d >> v >> a;
                add(d, v, a);
            }
            std::vector<int> p(m + 1);
            for (int i = 1; i <= m; ++i) {
                fin >> p.at(i);
            }
            int ans = 0;
            for (auto &&item: pos) {
                if (item <= p.at(m)) {
                    ++ans;
                }
            }
            fout << ans << " " << (ans == 0 ? m : m - 1) << std::endl;
        }
        if (a < 0) {
            std::vector<std::pair<int, int>> pos;
            auto add = [&](int d, int v, int a) {
                if (V * V - v * v <= 0) {
                    pos.emplace_back(V * v - v * v + 2 * a * d, 2 * a);
                }
            };
            add(d, v, a);
            for (int i = 2; i <= n; ++i) {
                int d, v, a;
                fin >> d >> v >> a;
                add(d, v, a);
            }
            std::vector<int> p(m + 1);
            for (int i = 1; i <= m; ++i) {
                fin >> p.at(i);
            }
        }
    }
    return 0;
}
