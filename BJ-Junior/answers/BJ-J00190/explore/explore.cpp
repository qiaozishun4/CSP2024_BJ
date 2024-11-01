#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x2,y2,d2,x,y,d,x3,y3,ans;
char c[1005][1005];
int v[1005][1005];
int a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        n=m=k=x2=y2=d2=x=y=d=x3=y3=0;
        ans=0;
        cin>>n>>m>>k;
        cin>>x2>>y2>>d2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
                if(c[i][j]=='x')a[i][j]=1;
                else a[i][j]=0;
            }
        }
        x=x2;
        y=y2;
        d=d2;
        for(int j=1;j<=k;j++){
            if(d==0){y3=y+1;x3=x;}
            if(d==1){x3=x+1;y3=y;}
            if(d==2){y3=y-1;x3=x;}
            if(d==3){x3=x-1;y3=y;}
            //cout<<"debug values: x3="<<x3<<"  y3="<<y3<<"  c[x3][y3]="<<c[x3][y3]<<"  d="<<d<<endl;
            if(x3>0&&x3<=n&&y3>0&&y3<=m&&a[x3][y3]==0){
                x=x3;
                y=y3;
                if(!v[x][y]){
                    ans++;
                    v[x][y]=1;
                }
            }else{
                d=(d+1)%4;
            }
        }
        if(v[x2][y2])ans--;
        cout<<ans+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}