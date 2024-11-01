#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t,n,k,q,l[100005],ls,r,c;
bool cg[200005],ans[105][200005];
vector<bool> dp[105][100005];
vector<int> s[100005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            s[i].clear();
            cin >> l[i];
            s[i].push_back(0);
            for(int j = 1;j <= l[i];j++){
                cin >> ls;
                s[i].push_back(ls);
            }
        }
        for(int i = 1;i <= n;i++){
            dp[1][i].push_back(0);
            int ls=1,cnt=0;
            bool zt=0;
            for(int z = 2;z <= l[i];z++){
                 if(s[i][z-1]==1){
                     cnt++;
                     if(cnt==1){
                         zt=1;
                     }
                 }
                 if(z-ls+1==k+1){
                     if(s[i][ls]==1){
                         cnt--;
                         if(cnt==0){
                             zt=0;
                         }
                     }
                 }
                 dp[1][i].push_back(zt);
              }
        }
        for(int i = 2;i <= 100;i++){
            for(int j = 1;j <= 200000;j++){
                cg[j]=0;
                dp[i][j].clear();
            }
            for(int j = 1;j <= n;j++){
                dp[i][j].push_back(0);
                int ls=1,cnt=0;
                bool zt=0;
                for(int z = 2;z <= l[j];z++){
                    if(cg[s[j][z-1]]){
                        cnt++;
                        if(cnt==1){
                            zt=1;
                        }
                    }
                    if(z-ls+1==k+1){
                        if(cg[s[j][ls]]){
                            cnt--;
                            if(cnt==0){
                                zt=0;
                            }
                        }
                    }
                    dp[i][j].push_back(zt);
                }
                for(int z = 1;z <= l[j];z++){
                    cg[s[j][z]]|=dp[i-1][j][z];
                }
            }
            for(int j = 1;j <= 200000;j++){
                cg[j]=0;
            }
            for(int j = n;j >= 1;j--){
                int ls=1,cnt=0;
                bool zt=0;
                for(int z = 2;z <= l[j];z++){
                    if(cg[s[j][z-1]]){
                        cnt++;
                        if(cnt==1){
                            zt=1;
                        }
                    }
                    if(z-ls+1==k+1){
                        if(cg[s[j][ls]]){
                            cnt--;
                            if(cnt==0){
                                zt=0;
                            }
                        }
                    }
                    dp[i][j][z]=zt||dp[i][j][z];
                    ans[i][s[j][z]]|=dp[i][j][z];
                }
                for(int z = 1;z <= l[j];z++){
                    cg[s[j][z]]|=dp[i-1][j][z];
                }
            }
        }
        while(q--){
            cin >> r >> c;
            cout << ans[r][c] << "\n";
        }
    }
    return 0;
}