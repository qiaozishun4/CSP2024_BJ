#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,ans=0;
char a[100][1000];
int ct[100][1000];
int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
   cin>>t;
   for(int c=0;c<t;c++){
       ans=0;
       cin>>n>>m>>k;
       cin>>x>>y>>d;
       ct[x][y]++;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               cin>>a[i][j];
            }
        }
        for(int i=0;i<k;i++){
            if(d==0&&a[x][y+1]=='.'&&1<=x&&x<=n&&1<=y+1&&y+1<=m){
                y++;
                ct[x][y]++;

            }
            else if(d==1&&a[x+1][y]=='.'&&1<=x+1&&x+1<=n&&1<=y&&y<=m){
                x++;
                ct[x][y]++;
            }
            else if(d==2&&a[x][y-1]=='.'&&1<=x&&x<=n&&1<=y-1&&y-1<=m){
                y--;
                ct[x][y]++;
            }
            else if(d==3&&a[x-1][y]=='.'&&1<=x-1&&x-1<=n&&1<=y&&y<=m){
                x--;
                ct[x][y]++;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ct[i][j]>0)ans++;
                ct[i][j]=0;
            }
        }
        cout<<ans<<endl;
   }
   return 0;
}
