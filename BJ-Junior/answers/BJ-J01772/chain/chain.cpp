#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,r,c;
vector<long long> s[100005];
bool pd;
void dfs(long long sz,long long p,long long bs){
    if(bs==r){
        if(sz==c)pd=1;
        return;
    }
    for(long long i=1;i<=n;i++){
        if(p==i)continue;
        set<long long> v;
        for(long long j=0;j<s[i].size();j++){
            if(s[i][j]==sz){
                for(long long o=j+1;o<=min(j+k-1,(long long)s[i].size()-1);o++){
                    v.insert(s[i][o]);
                }
            }
        }
        for(auto it=v.begin();it!=v.end();it++){
            dfs(*it,i,bs+1);
            if(pd)return;
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(long long i=1;i<=n;i++){
            long long l,x;
            cin>>l;
            s[i].clear();
            for(long long j=1;j<=l;j++)cin>>x,s[i].push_back(x);
        }
        while(q--){
            cin>>r>>c;
            pd=0;
            dfs(1,0,0);
            cout<<pd<<"\n";
        }
    }
    return 0;
}
