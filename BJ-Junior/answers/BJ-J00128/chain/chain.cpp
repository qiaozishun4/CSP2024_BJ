#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int N=1e3+5;
int n,T,k,q,mp[N][N],cnt;
vector <int> a[N],lis[N];//lis[i][j-1]j对应的数
vector <int>dy[N][N];//dy 离散化对应,mp[i]第i个人的离散化 priority_
queue <int>las[N];
bool flag;
void dfs(int x,int r,int c,int p){
    if(r==1){
        if(mp[x][c]==0)return;
        for(int po=0;po<dy[x][mp[x][p]].size();po++){
            if(lis[x][dy[x][mp[x][p]][po]-1]==c){
                flag=true;
                break;
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        for(int po=0;po<dy[x][mp[x][p]].size();po++){
            if(mp[i][lis[x][dy[x][mp[x][p]][po]-1]]!=0){
                dfs(i,r-1,c,lis[x][dy[x][mp[x][p]][po]-1]);
            }
        }
    }
}
void solve(){
    cin >>n>>k>>q;
    memset(mp,0,sizeof(mp));
    for(int i=1,x;i<=n;i++){
        a[i].resize(0);
        lis[i].resize(0);
        cnt=0;
        cin >>x;
        for(int j=1;j<=x;j++)while(!las[i].empty())las[i].pop();
        for(int j=1,y;j<=x;j++){
            dy[i][j].resize(0);
            cin >> y;
            a[i].push_back(y);
            if(mp[i][y]==0){
                lis[i].push_back(y);
                mp[i][y]=++cnt;
                //cout <<y<<" "<<cnt<<endl;
            }
            las[mp[i][y]].push(j);
        }
        for(int j=1;j<=x;j++){
            for(int u=1;u<=cnt;u++){
                while(!las[u].empty()&&las[u].front()<=j)las[u].pop();
                //cout <<i<<" "<<lis[i][u-1]<<" "<<j<<" "<<u<<" "<<las[u].front()<<endl;
                if(las[u].empty())continue;
                if(las[u].front()-k+1<=j)dy[i][mp[i][a[i][j-1]]].push_back(u);
            }
        }
    }
    for(int i=1,r,c;i<=q;i++){
        cin >> r >> c;
        if(r==1){
            for(int j=1;j<=n;j++){
                flag=0;
                if(mp[i][1]==0)continue;
                for(int k=0;k<dy[j][mp[j][1]].size();k++){
                    if(lis[j][dy[j][mp[j][1]][k]-1]==c){
                        //cout << j<<" "<<k<<" "<<lis[j][dy[j][mp[j][1]][k]-1]<<endl;
                        cout <<1<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(!flag)cout << 0 << endl;
        }else{
            flag=0;
            for(int j=1;j<=n;j++){
                if(mp[j][1]!=0)dfs(j,r,c,1);
                if(flag){
                    cout <<1<<endl;
                    break;
                }
            }
            if(!flag)cout << 0<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
