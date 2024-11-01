#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T;
int n, k, q;
int l[N];
int r[N], c[N];
int x;
int kk;
bool f;
vector<int> s[N];
map<int, bool> v[N];

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &k, &q);
        for(int i=1; i<=n; i++){
            scanf("%d", &l[i]);
            for(int j=1; j<=l[i]; j++){
                scanf("%d", &x);
                s[i].push_back(x);
                if(kk>=1){
                    v[i][x] = true;
                    kk--;
                }
                if(x==1){
                    kk = k - 1;
                }
            }
            kk = 0;
        }
        for(int i=1; i<=q; i++){
            scanf("%d%d", &r[i], &c[i]);
            if(r[i]==1){
                f = false;
                for(int j=1; j<=n; j++){
                    if(v[j][c[i]]){
                        printf("1\n");
                        f = true;
                        break;
                    }
                }
                if(!f) printf("0\n");
            }
        }
        for(int i=1; i<=n; i++){
            s[i].clear();
            v[i].clear();
        }
    }

    return 0;
}
