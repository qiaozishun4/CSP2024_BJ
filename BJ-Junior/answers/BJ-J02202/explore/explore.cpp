#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool a1[1010][1010];
struct robot{
    long long x,y,d;
}rob;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k,ans=1;
        cin>>n>>m>>k;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                a1[i][j]=0;
            }
        }
        cin>>rob.x>>rob.y>>rob.d;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        a1[rob.x][rob.y]=1;
        for(long long i=1;i<=k;i++){
            if(rob.d==0&&a[rob.x][rob.y+1]!='x'&&rob.y+1<=m){
                rob.y++;
                if(!a1[rob.x][rob.y]){
                    ans++;
                    //cout<<rob.x<<" "<<rob.y<<" "<<rob.d<<endl;
                    a1[rob.x][rob.y]=1;
                }
            }else if(rob.d==1&&a[rob.x+1][rob.y]!='x'&&rob.x+1<=n){
                rob.x++;
                if(!a1[rob.x][rob.y]){
                    ans++;
                    //cout<<rob.x<<" "<<rob.y<<" "<<rob.d<<endl;
                    a1[rob.x][rob.y]=1;
                }
            }else if(rob.d==2&&a[rob.x][rob.y-1]!='x'&&rob.y-1>0){
                rob.y--;
                if(!a1[rob.x][rob.y]){
                    ans++;
                    //cout<<rob.x<<" "<<rob.y<<" "<<rob.d<<endl;
                    a1[rob.x][rob.y]=1;
                }
            }else if(rob.d==3&&a[rob.x-1][rob.y]!='x'&&rob.x-1>0){
                rob.x--;
                if(!a1[rob.x][rob.y]){
                    ans++;
                    //cout<<rob.x<<" "<<rob.y<<" "<<rob.d<<endl;
                    a1[rob.x][rob.y]=1;
                }
            }else{
                rob.d=(rob.d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}