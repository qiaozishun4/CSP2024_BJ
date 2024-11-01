#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int l[100010];
int n,k,q;
int s[200010],a[200010],f[200010];
vector<int> v[200010];
int ans[110][200010];
struct node{
    int l,f,x;
};
void bfs(){
    queue<node> q;
    for(int x:v[1]){
        q.push(node{x,0,0});
    }
    while(!q.empty()){
        int nl=q.front().l,nf=q.front().f,nx=q.front().x;
        q.pop();
        if(nx>10)return;
        if(nf)ans[nx][a[nl]]=1;
        if(nf){
            for(int x:v[a[nl]]){
                if(s[x]==s[nl])continue;
                q.push(node{x,0,nx});
            }
        }
        else{
            for(int i=nl+1;i<nl+k;i++){
                if(s[i]!=s[nl])continue;
                q.push(node{i,1,nx+1});
            }
        }
    }
    return;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=2e5;i++){
            v[i].clear();
        }
        memset(ans,0,sizeof ans);
        int cnt=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int ss;
                cin>>ss;
                a[++cnt]=ss;
                s[cnt]=i;
                v[ss].push_back(cnt);
            }
        }
        bfs();
        for(int i=1;i<=q;i++){
            memset(f,0,sizeof f);
            int r,c;
            cin>>r>>c;
            cout<<ans[r][c]<<"\n";
        }
    }
    return 0;
}
