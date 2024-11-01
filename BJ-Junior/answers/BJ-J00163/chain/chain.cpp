#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 2e5 + 5;
vector<int> G1[N],G2[N];
int T,n,k,q,s[N][N],l[N],cur[N],r,c;
bool vis[M];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >>T;
    while(T--){
        vector<int> G1[N],G2[N];
        cin >> n >> k >> q;
        memset(s,0,sizeof s);
        memset(l,0,sizeof l);
        memset(vis,false,sizeof vis);
        for(int i = 1; i <= n; ++i){
            cin >> l[i];
            for(int j = 1; j <= l[i];++j){
                cin >> s[i][j];
                if(s[i][j] == 1){
                    cur[i]=j;

                }
            }
            vis[s[i][cur[i]+1]] = true;
        }
        while(q--){
            cin >> r >> c;
            if(r==1){
                if(vis[c]) printf("1\n");
                else printf("0\n");
            }
            else printf("0\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
