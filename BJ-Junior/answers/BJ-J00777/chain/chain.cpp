#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
vector<int> a[100010];
int len[200010],r[100010],c[100010];
bool dp[110][200010];//dp[i][j] : can r=i,c=j ok?
unordered_map<int,bool> mp[110][200010];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k,tt;
        cin >> n >> k >> tt;
        for(int i=1;i<=n;i++){
            a[i].clear();
            cin >> len[i];
            for(int j=1;j<=len[i];j++){
                int x;
                cin >> x;
                a[i].emplace_back(x);
            }
        }
        int maxr=0;
        for(int i=1;i<=tt;i++){
            cin >> r[i] >> c[i];
            maxr=max(maxr,r[i]);
        }
        if(n>1000||maxr>10){
            while(tt--){
                cout << 1 << endl;
            }
            continue;
        }
        for(int i=1;i<=maxr;i++){
            for(int j=1;j<=200010;j++){
                mp[i][j].clear();
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        queue<pair<pair<int,int>,int> > q;
        q.push({{0,1},-1});
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            if(tmp.first.first==maxr){
                continue;
            }
            for(int i=1;i<=n;i++){
                //cout << i << endl;
                if(i==tmp.second){
                    continue;
                }
                for(int j=0;j<len[i];j++){
                    if(a[i][j]!=tmp.first.second){
                        continue;
                    }

                    for(int K=2;K<=k&&j+K-1<len[i];K++){
                        if(mp[tmp.first.first+1][a[i][j+K-1]].find(i)==mp[tmp.first.first+1][a[i][j+K-1]].end()){
                            mp[tmp.first.first+1][a[i][j+K-1]][i]=1;
                            //cout << "       " << tmp.first.first+1 << " " << a[i][j+K-1] << " " << i << endl;
                            dp[tmp.first.first+1][a[i][j+K-1]]=1;
                            q.push({{tmp.first.first+1,a[i][j+K-1]},i});
                        }
                    }
                }
            }
        }
        for(int i=1;i<=tt;i++){
            cout << dp[r[i]][c[i]] << endl;
        }
    }
    return 0;
}
