#include<bits/stdc++.h>
using namespace std;
char pl[1005][1005];
bool oop[1005][1005];
int f[8]={1,0,-1,0,
          0,1,0,-1};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        int ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>pl[i][j];
            }
        }
        while(k!=0){
            if((x+f[d]<1||x+f[d]>n)||(y+f[d+4]<1||y+f[d+4]>m)||pl[x+f[d]][y+f[d+4]]=='x'){
                d=(d+1)%4;
            }else {
                x+=f[d];
                y+=f[d+4];
                if(!oop[x][y]){ans++;oop[x+f[d]][y+f[d+4]]=1;}
            }
            k--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
