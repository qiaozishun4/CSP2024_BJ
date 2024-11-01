#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
int sum=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;

    while(t--){

        sum=0;

        cin>>n>>m>>k;
        cin>>x>>y>>d;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>a[i][j];
            while(k--){
                if(d==0)  if(a[x][y+1]!='x'&&1<=x&&x<=n&&1<=(y+1)&&(y+1)<=m) {y=y+1; sum++;}
                else d=(d+1)%4;
                if(d==1)  if(a[x+1][y]!='x'&&1<=(x+1)&&(x+1)<=n&&1<=y&&y<=m) {x=x+1; sum++;}
                else d=(d+1)%4;
                if(d==2)  if(a[x][y-1]!='x'&&1<=x&&x<=n&&1<=(y-1)&&(y-1)<=m) {y=y-1; sum++;}
                else d=(d+1)%4;
                if(d==3)  if(a[x-1][y]!='x'&&1<=(x-1)&&(x-1)<=n&&1<=y&&y<=m) {x=x-1; sum++;}
                else d=(d+1)%4;
            }
        cout<<sum<<endl;

    }
    return 0;
}
