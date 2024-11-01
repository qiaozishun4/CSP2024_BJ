#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,d;
char mp[1001][1001];
struct node{
    int x;int y;
};node start;
stack <node> s;
int bfs(int x,int y){
    int cnt=0;
    if(k==0) return cnt;
    int ex[5]={0,1,0,-1},ey[5]={1,0,-1,0};
    s.push(start);
    for(int i=1;i<=4;i++){
        int nx=x+ex[i];
        int ny=y+ey[i];
        if(mp[nx][ny]=='.' && k!=0 && nx>=1 && ny>=1 && nx<=n && ny<=m){
            node one;
            one.x=nx;
            one.y=ny;
            s.push(one);
            k--;
            cnt++;
        }
        else s.pop();
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>start.x>>start.y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        cout<<bfs(start.x,start.y);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
