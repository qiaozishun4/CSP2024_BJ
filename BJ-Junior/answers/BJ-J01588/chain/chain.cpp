#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int MAXK=2e5+5;
int t,n,k,q,vis[MAXK],l[MAXN],last[MAXN],last_st;
struct node{
    int r,c;
    bool operator<(node _){
        return r<_.r;
    }
}que[MAXN];
vector<int> a[MAXN];
bool chk(int l1,int r1,int l2,int r2,int id){
    if(r1-l1!=r2-l2) return 0;
    for(int i=0;i<=r1-l1;i++){
        if(a[id-1][i+l1]!=a[id][i+l2]) return 0;
    }
    return 1;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++) cin>>que[i].r>>que[i].c;
        sort(que+1,que+q+1);
        int now=0;
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        for(int i=1;i<=100;i++){
            int id=(i-1)%n+1,st=1e9;
            for(int j=0;j<l[i];j++){
                if(vis[a[i][j]]){
                    st=j;
                    break;
                }
            }
            bool ok=0;
            memset(vis,0,sizeof(vis));
            for(int j=st+1;j<l[i];j++){
                if(last[a[i][j]]){
                    if(chk(last_st,last[a[i][j]],st,j,i)) continue;
                }
                vis[a[i][j]]=1;
                if(ok==0) last[a[i][j]]=j;
                if(vis[a[i][j]]) ok=1;
            }
            last_st=st;
            while(que[now].r<i) now++;
            while(que[now].r==i){
                cout<<vis[que[now].c]<<endl;
                now++;
            }
        }
    }
    return 0;
}
