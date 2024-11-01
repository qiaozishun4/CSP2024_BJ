#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n;

int a[N];

struct Node{
    int lc,rc;
    int v,w;
    int sz;
}tr[N];
int root;
int tot;
void pushup(int p){
    if(p){
        tr[p].sz=tr[tr[p].lc].sz+1+tr[tr[p].rc].sz;
    }
}
int merge(int u,int v){
    if(!(u&&v)){
        return u|v;
    }
    if(tr[u].w>tr[v].w){
        tr[u].rc=merge(tr[u].rc,v);
        pushup(u);
        return u;
    }
    else{
        tr[v].lc=merge(u,tr[v].lc);
        pushup(v);
        return v;
    }
}
pair<int,int> split(int u,int x){
    if(!u){
        return {0,0};
    }
    if(x<tr[u].v){
        auto pr=split(tr[u].lc,x);
        tr[u].lc=pr.second;
        pushup(u);
        return {pr.first,u};
    }
    else{
        auto pr=split(tr[u].rc,x);
        tr[u].rc=pr.first;
        pushup(u);
        return {u,pr.second};
    }
}
void insert(int x){
    tr[++tot]={0,0,x,rand(),1};
    auto pr=split(root,x);
    root=merge(merge(pr.first,tot),pr.second);
}
void erase(int& u,int x){
    if(!u){
        return;
    }
    if(x<tr[u].v){
        erase(tr[u].lc,x);
    }
    else if(tr[u].v<x){
        erase(tr[u].rc,x);
    }
    else{
        u=merge(tr[u].lc,tr[u].rc);
    }
    pushup(u);
}
int cnt_lower(int u,int x){
    if(!u){
        return 0;
    }
    if(x<tr[u].v){
        return cnt_lower(tr[u].lc,x);
    }
    else{
        return tr[tr[u].lc].sz+1+cnt_lower(tr[u].rc,x);
    }
}
int get_id(int u,int k){
    if(!u){
        return 0;
    }
    if(k<=tr[tr[u].lc].sz){
        return get_id(tr[u].lc,k);
    }
    else if(k==tr[tr[u].lc].sz+1){
        return u;
    }
    else{
        return get_id(tr[u].rc,k-tr[tr[u].lc].sz-1);
    }
}

priority_queue<int,vector<int>,std::greater<int>> q;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
        insert(a[i]);
    }

    int ans=n;
    while(q.size()){
        int x=q.top();
        q.pop();
        int k=cnt_lower(root,x);
        if(k+1>tr[root].sz){
            break;
        }
        int id=get_id(root,k+1);
        erase(root,tr[id].v);
        erase(root,x);
        ans--;
    }

    cout<<ans<<endl;


    return 0;
}