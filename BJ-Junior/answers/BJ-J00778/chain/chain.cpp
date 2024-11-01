#include<iostream>
#include<vector>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
vector<int> a[N];
vector<pii> pos[N<<1];

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        int j=0;
        while(len--){
            int x;
            cin>>x;
            a[i].push_back(x);
            pos[x].push_back({i,j});
            j++;
        }
    }
    while(q--){
        int r,c;
        cin>>r>>c;
        bool flag=false;
        for(pii p:pos[c]){
            int l=max(0,p.second-m);
            for(int i=l;i<=p.second-1;i++){
                if(a[p.first][i]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        cout<<flag<<'\n';
    }
}

int main(){
    freopen("chain2.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
