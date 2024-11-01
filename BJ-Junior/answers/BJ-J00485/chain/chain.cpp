#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1,R=1e2+1,A=2e5+1;
int t,n,k,q,l[N],r,c;
bool dp[2*R][A][2];
unordered_set<int> a[A];
vector<int> s[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        memset(dp,false,sizeof dp);
        for(int i=1;i<A;i++)a.clear();
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            s[i].resize(l[i]+1);
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
                if(j!=1){
                    dp[1][s[i][j]][0]=true;
                    for(int g=j-1;g>=max(0LL,j-k+1);g--){
                        a[s[i][j]].emplace(s[i][g]);
                    }
                    if(a[s[i][j]].count(1)!=0)dp[1][s[i][j]][1]=true;
                }
            }
        }
        for(int i=1;i<R;i++){
            for(int j=1;j<R;j++){
                for(int x=1;x<A;x++){
                    if(!dp[j][x][0])continue;
                    for(auto g:a[x]){
                        dp[i+j][x][0]=dp[i][g][0]&&dp[j][x][0];
                        dp[i+j][x][1]=dp[i][g][1]&&dp[j][x][0];
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            cout<<dp[r][c][1]<<'\n';
        }
    }
    return 0;
}


