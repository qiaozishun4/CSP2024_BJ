#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,q;
int cnt;
struct Edge{
    int v,w;
};
vector<Edge> g[222222];
void build(int x){
    int len,num[222222];
    cin>>len;
    for(int i=1;i<=len;i++){
        cin>>num[i];
    }
    for(int i=1;i<=len;i++){
        for(int j=i+1;j<=len&&j-i+1<=k;j++){
            g[num[j]].push_back({num[i],x});//注意这里是反图！
            cnt++;
            //cout<<num[i]<<"->"<<num[j]<<"\n";
        }
    }
}
bool judge(int x,int d,int lst){//能否d步从1走到x
    //cerr<<x<<" "<<d<<"\n";
    if(d==0){
        if(x==1)return 1;
        return 0;
    }
    bool ret=0;
    for(auto i:g[x]){
        int y=i.v,w=i.w;
        if(w==lst)continue;
        ret=ret||judge(y,d-1,w);
    }
    return ret;
}
void init(){//多测不清空，亲人两行泪
    for(int i=0;i<222222;i++){
        g[i].clear();
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        init();
        for(int i=1;i<=n;i++){
            build(i);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<judge(y,x,-1)<<"\n";
        }
    }
    return 0;
}
/*
1
1 2 1
2 1 2
1 2
⎲
cd
l -alhsR
*/
