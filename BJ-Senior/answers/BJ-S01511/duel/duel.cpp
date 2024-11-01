#include<bits/stdc++.h>
#define PP pair<int,int>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],ans;
vector<PP> g;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i==0) g.push_back({a[i],1});
        else if(g[g.size()-1].first==a[i]) g[g.size()-1].second++;
        else g.push_back({a[i],1});
    }
    int live=g[0].second;
    for(int i=1;i<g.size();i++){
        if(g[i].second>=live) live=g[i].second;
    }
    cout<<live<<endl;
    return 0;
}
