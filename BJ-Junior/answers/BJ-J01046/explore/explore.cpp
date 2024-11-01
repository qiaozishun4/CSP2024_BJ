#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,n,m,k;
int d,sx,sy;
int vis[1005][1005];
int cnt=0;
char a[1005][1005];
bool run(int d){
    int dx=x,dy=y;
    if(d==0){dy++;}
    if(d==1){dx++;}
    if(d==2){dy--;}
    if(d==3){dx--;}
    if(dx>n||dx<1||dy>m||dy<1||a[dx][dy]=='x') return 0;
    else return 1;
}
void read(){
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[i][j+1]=s[j];
        }
    }
    return;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        read();
        cnt=0;
        memset(vis,0,sizeof vis);
        vis[sx][sy]=1;cnt++;
        x=sx;y=sy;
        for(int i=1;i<=k;i++){
            if(run(d)){
                if(d==0){y++;}
                if(d==1){x++;}
                if(d==2){y--;}
                if(d==3){x--;}
                if(!vis[x][y]){
                    vis[x][y]=1;
                    cnt++;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
