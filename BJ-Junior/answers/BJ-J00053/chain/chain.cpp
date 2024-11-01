#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,q;
vector<int>s[100005];
vector<pair<int,int>>lo;
void slv(){
    cin>>n>>k>>q;
    lo.clear();
    for(int i=1;i<=n;i++){
        s[i].clear();
        int l;
        cin>>l;
        while(l--){
            int x;
            cin>>x;
            if(x==1)
            lo.push_back({i,s[i].size()});
            s[i].push_back(x);
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        bool found=0;
        for(auto x:lo){
            for(int i=1;i<k&&x.second+i<s[x.first].size();i++)if(s[x.first][x.second+i]==b){cout<<1<<endl;found=1;break;}
            if(found)break;
        }if(!found)
        cout<<0<<endl;
    }
    return;
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    slv();
    return 0;
}