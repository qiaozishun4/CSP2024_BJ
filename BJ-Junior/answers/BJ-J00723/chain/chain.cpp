#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int NR = 2e5 + 10;
int l[NR];
vector<int> s[NR];

// r = 1
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &l[i]);
            for(int j = 1; j <= l[i]; j++) {
                int x;
                scanf("%d", &x);
                s[i].push_back(x);
            }
        }
        while(q--) {
            int r, c;
            scanf("%d%d", &r, &c);
            bool flag = false;
            for(int i = 1; i <= n; i++) {
                if(flag) break;
                for(int j = 0; j < l[i]; j++) {
                    if(flag) break;
                    if(s[i][j] == 1)
                        for(int g = j + 1; g < l[i] && g < j + k; g++)
                            if(s[i][g] == c) {
                                flag = true;
                                break;
                            }
                }
            }
            if(flag) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
