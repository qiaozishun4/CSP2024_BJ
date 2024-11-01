#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c;
bool can;
struct node{
    int u;
    vector<pair<int,int>>v;
}g[100010];

struct person{
    int l,s[100010];
}p;
int dfs(int now,int to,int step,int need,int in){
    if(step==need && now==to){
        can=1;
        return 0;
    }
    if(can)return 0;
    if(step>=need){return 0;}
    for(pair<int,int> ct:g[now].v){
        //cout<<step+1<<" "<<now<<"->"<<ct<<'\n';
        if(ct.second!=in)dfs(ct.first,to,step+1,need,ct.second);
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>p.l;
            for(int j=1;j<=p.l;j++){
                cin>>p.s[j];
            }
            for(int len=2;len<=k;len++){
                for(int be=1;be<=p.l-len+1;be++){
                    g[p.s[be]].v.push_back({p.s[be+len-1],i});
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            can=0;
            for(int i=1;i<=n;i++)dfs(1,c,0,r,i);
            cout<<can<<'\n';
        }
    }
    return 0;
}