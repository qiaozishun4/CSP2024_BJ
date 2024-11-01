#include <bits/stdc++.h>

using namespace std;

int fx[4]={0,1, 0,-1};
int fy[4]={1,0,-1, 0};
char mp[1005][1005];
bool vis[1005][1005];
int n,m,k;

bool check(int x,int y){
    if(x<1||x>n||y<1||y>m)return false;
    if(mp[x][y]=='x')return false;
    return true;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        int x,y,d;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            scanf("%s",mp[i]+1);
        }
        vis[x][y]=true;
        int cnt=1;
        while(k--){
            if(check(x+fx[d],y+fy[d])){
                x+=fx[d];
                y+=fy[d];
                if(!vis[x][y]){
                    vis[x][y]=true;
                    cnt++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
