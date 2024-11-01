#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> s[100005];
vector<pair<int,int>> a[400005];
const int P=200001;
bool vis[400005][105],vis2[105][200005],ok[400005];
int n,k,Q;
struct qwq{
    int p,now,r;
};
queue<qwq> q;
void bfs(){
    while(!q.empty()){
        int p=q.front().p,now=q.front().now,r=q.front().r;
        q.pop();
        if(r>100){
            return;
        }
        if(p>=P){
            vis2[r][p-P]=1;
        }
        for(int i=0;i<a[p].size();i++){
            if(p<P){
                if(a[p][i].second>now&&a[p][i].second<now+k&&!vis[a[p][i].first][r]){
                    vis[a[p][i].first][r]=1;
                    q.push((qwq){a[p][i].first,p,r});
                }else if(a[p][i].second>now&&a[p][i].second<now+k){
                    ok[a[p][i].first]=1;
                }
                if(a[p][i].second>=now+k)
                    break;
            }else{
                if((a[p][i].first!=now||ok[p])&&r<100){
                    q.push((qwq){a[p][i].first,a[p][i].second,r+1});
                }
            }
        }
        ok[p]=0;
    }
}
vector<pair<int,int>> bg;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>Q;
        memset(vis,0,sizeof(vis));memset(vis2,0,sizeof(vis2));
        bg.clear();
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            s[i].clear();
            for(int j=1;j<=l;j++){
                int tmp;
                cin>>tmp;
                if(tmp==1){
                    bg.push_back(make_pair(i,j-1));
                }
                s[i].push_back(tmp);
                a[tmp+P].push_back(make_pair(i,j-1));
                a[i].push_back(make_pair(tmp+P,j-1));
            }
        }
        for(int i=0;i<bg.size();i++){
            q.push((qwq){bg[i].first,bg[i].second,1});
        }
        bfs();
        for(int i=1;i<=Q;i++){
            int r,c;
            cin>>r>>c;
            cout<<vis2[r][c]<<endl;
        }
        for(int i=1;i<400005;i++){
            a[i].clear();
        }
    }
    return 0;
}
