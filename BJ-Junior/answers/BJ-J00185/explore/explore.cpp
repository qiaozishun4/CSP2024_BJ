#include <bits/stdc++.h>
using namespace std;
int q;
int tmp=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>q;
    int m,n,k;
    int x,y,d;
    int ans;
    int flag=0;
    for(int i=0;i<q;i++){
        ans=0;
        cin>>m>>n>>k;
        cin>>x>>y>>d;
        char a[m][n];
        int b[m+1][n+1]={0};
        b[x][y]=1;
        for(int j=1;j<=m;j++){
            for(int l=1;l<=n;l++){
                cin>>a[j][l];
            }
        }
        for(int j=0;j<k;j++){
            flag=0;
            if(d==0 && flag==0){
                if(a[x][y+1]=='.' && y+1<=n){
                    b[x][y+1]=1;
                    y++;

                }else{
                    d++;
                    d=d%4;
                    flag=1;
                }
                //cout<<x<<" "<<y<<" "<<d<<" "<<0<<" "<<a[x][y+1]<<endl;
            }
            if(d==1 && flag==0){
                if(a[x+1][y]=='.' && x<=m){
                    b[x+1][y]=1;
                    x++;

                }else{
                    d++;
                    d=d%4;
                    flag=1;
                }
                //cout<<x<<" "<<y<<" "<<d<<" "<<1<<" "<<a[x+1][y]<<endl;
            }if(d==2 && flag==0){
                if(a[x][y-1]=='.' && y>=1){
                    b[x][y-1]=1;
                    y--;

                }else{
                    d++;
                    d=d%4;
                    flag=1;
                }
                //cout<<x<<" "<<y<<" "<<d<<" "<<2<<" "<<a[x][y-1]<<endl;
            }if(d==3 && flag==0){
                if(a[x-1][y]=='.' && x>=1){
                    b[x-1][y]=1;
                    x--;

                }else{
                    d++;
                    d=d%4;
                    flag=1;
                }
                //cout<<x<<" "<<y<<" "<<d<<" "<<3<<" "<<a[x-1][y]<<endl;
            }

        }
        for(int j=1;j<=m;j++){
            for(int l=1;l<=n;l++){
                if(b[j][l]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;


    }

    return 0;
}
