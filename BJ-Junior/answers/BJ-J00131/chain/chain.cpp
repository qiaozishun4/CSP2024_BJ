#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mkp make_pair
#define ins insert
#define endl '\n'
using namespace std;
struct Node{
    int x,y,st;
};
const int N=1e5+5;
int T,n,k,q,l[N],r,c,cnt;
vector<int> s[N];
map<int,vector<pair<int,int> > > mp;
map<pair<int,int>,bool>vis[105];
bool bfs(int bx,int by){
    FOR(i,1,100)vis[i].clear();
    queue<Node> q;
    q.push({bx,by,0});
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        if(now.st==r){
            if(s[now.x][now.y]==c)return 1;
            continue;
        }
        set<pair<int,int> >st;
        for(auto i:mp[(now.st==0?1:s[now.x][now.y])]){
            int nx=i.first,ny=i.second;
            if(nx==now.x)continue;
            FOR(j,1,k-1){
                if(ny+j>=l[nx])break;
                if(!vis[now.st+1][mkp(nx,ny+j)])
                    st.insert(mkp(nx,ny+j));
            }
        }
        for(auto i:st){
            q.push({i.first,i.second,now.st+1});
            vis[now.st+1][i]=1;
        }
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        FOR(i,1,n)s[i].clear();
        mp.clear();
        map<int,bool> v[N];
        FOR(i,1,n){
            cin>>l[i];
            FOR(j,0,l[i]-1){
                int t;
                cin>>t;
                s[i].pb(t);
                mp[t].pb(mkp(i,j));
            }
        }
        FOR(i,1,n){
            FOR(j,0,l[i]-1){
                if(s[i][j]==1){
                    FOR(q,j+1,j+k-1)
                        if(q<l[i]) v[i][s[i][q]]=1;
                }
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                bool ans=0;
                FOR(i,1,n)
                    if(v[i][c]){ans=1;break;}
                cout<<ans<<endl;
            }
            else cout<<bfs(0,0)<<endl;
        }
    }
    return 0;
}
/*
luogu uid=923403
XD
*/
