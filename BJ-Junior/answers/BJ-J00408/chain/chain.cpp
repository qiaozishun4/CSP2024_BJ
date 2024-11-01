#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,k,q,r,c;
const int N=1e5+5;
int l[N];
vector<int>s[N];
bool dfs(int ned,int now,int lst){
    if(now==r){
        for(int i=1;i<=n;i++){
            int f=-1;
            for(int j=0;j<l[i];j++){
                if(f!=-1&&s[i][j]==c&&j-f+1<=k&&j-f+1>=2){
                    return 1;
                }
                if(s[i][j]==ned) f=j;
            }
        }
        return 0;
    }
    bool f=0;
    for(int i=1;i<=n;i++){
        if(i==lst) continue;
        for(int j=0;j<l[i];j++){
            if(s[i][j]==ned){
                int jj=j+1;
                while(jj<=j+k-1){
                    f|=dfs(s[i][jj],now+1,i);
                    jj++;
                    if(f) return 1;
                }
            }
        }
    }
    return 0;
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                bool _=0;
                for(int i=1;i<=n;i++){
                    bool theend=0;
                    int f=-1;
                    for(int j=0;j<l[i];j++){
                        if(f!=-1&&s[i][j]==c&&j-f+1<=k&&j-f+1>=2){
                            cout<<"1\n";
                            theend=1;
                            _=1;
                            break;
                        }
                        if(s[i][j]==1) f=j;
                    }
                    if(theend) break;
                }
                if(!_) cout<<"0\n";
            }
            else cout<<dfs(1,1,-1)<<'\n';
        }
    }
    return 0;
}
//9428.09036868018145
