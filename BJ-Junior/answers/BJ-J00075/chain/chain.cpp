#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int t,n,k,q,rmax,l[100001],r[100001],c[100001],dis[200001];
vector<int> v[100001];
vector<pair<int,int>> go;
bool ok[200001];
queue<pair<int,int>> que;
void input() {
    for(int i=1;i<=100000;i++) v[i].clear();
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++) {
        cin>>l[i];
        for(int j=1;j<=l[i];j++) {
            int tmp;
            cin>>tmp;
            v[i].push_back(tmp);
        }
    }
    rmax=0;
    for(int i=1;i<=q;i++) {
        cin>>r[i]>>c[i];
        rmax=max(rmax,r[i]);
    }
}
void r1() {
    for(int i=1;i<=200000;i++) ok[i]=false;
    for(int i=1;i<=n;i++) {
        int l1=-k;
        for(int j=0;j<l[i];j++) {
            if(j-l1+1>=2 && j-l1+1<=k) ok[v[i][j]]=true;
            if(v[i][j]==1) l1=j;
        }
    }
    for(int i=1;i<=q;i++) {
        if(ok[c[i]]) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
void ggo(int p,int nu) {
    go.clear();
    for(int i=1;i<=n;i++) {
        if(i==p) continue;
        int l1=-k;
        for(int j=0;j<l[i];j++) {
            if(j-l1+1>=2 && j-l1+1<=k && !ok[v[i][j]]) {
                ok[v[i][j]]=true;
                go.push_back({i,j});
            }
            if(v[i][j]==nu) l1=j;
        }
    }
    for(pair<int,int> i:go) ok[i.second]=false;
}
bool bfs(int r,int c) {
    for(int i=1;i<=200000;i++) dis[i]=0;
    while(!que.empty()) que.pop();
    for(int i=1;i<=n;i++)
        for(int j=0;j<l[i];j++)
            if(v[i][j]==1)
                que.push({i,j});
    dis[1]=1;
    while(!que.empty()) {
        pair<int,int> t=que.front();
        que.pop();
        if(dis[v[t.first][t.second]]>=r) break;
        ggo(t.first,v[t.first][t.second]);
        for(pair<int,int> i:go) {
            que.push(i);
            dis[v[i.first][i.second]]=dis[v[t.first][t.second]]+1;
        }
    }
    return dis[c]==r;
}
void r5() {
    for(int i=1;i<=q;i++) {
        if(bfs(r[i],c[i])) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
void pf() {
    for(int i=1;i<=q;i++) cout<<0<<endl;
}
int main() {
    freopen("chain3.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--) {
        input();
        if(rmax==1) r1();
        else if(rmax<=5) r5();
        else pf();
    }
    return 0;
}