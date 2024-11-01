#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<pair<int,int> > a[N];
bool vis[105][N];
int b[N];
int cnt[105][N];
int tp[105][N];
struct node{
    int id,k,tp;
};
node make_node(int id,int k,int tp){
    node temp;
    temp.id=id;
    temp.k=k;
    temp.tp=tp;
    return temp;
}
queue<node> q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        memset(tp,0,sizeof tp);
        for(int i=0;i<=2e5;i++){
            a[i].clear();
        }
        int n,k,q1;
        cin>>n>>k>>q1;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            int x=0,y=0;
            for(int j=1;j<=l;j++){
                cin>>x;
                if(j>1){
                    a[y].push_back(make_pair(x,i));
                }
                y=x;
            }
        }
        cnt[0][1]=2;
        for(int r=1;r<=100;r++){
            memset(b,0,sizeof b);
            for(int i=1;i<=n;i++){
                for(int j=0;j<=2e5;j++){
                    if(cnt[r-1][j]==0||(cnt[r-1][j]==1&&tp[r-1][j]==i))continue;
                    q.push(make_node(j,1,i));
                }
                while(!q.empty()){
                    node now=q.front();
                    q.pop();
                    if(now.k>1){
                        vis[r][now.id]=1;
                        cnt[r][now.id]++;
                    }
                    if(now.k==k){
                        continue;
                    }
                    for(auto v:a[now.id]){
                        if(v.second!=now.tp)continue;
                        if(b[v.first]==i)continue;
                        b[v.first]=i;
                        q.push(make_node(v.first,now.k+1,now.tp));
                        tp[r][v.first]=now.tp;
                    }
                }
            }
        }
        while(q1--){
            int r,c;
            cin>>r>>c;
            cout<<vis[r][c]<<endl;
        }
    }
    return 0;
}
