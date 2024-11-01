#include<bits/stdc++.h>
using namespace std;
long long m,n,k,T,x,y,d,ans;char c[1005][1005];bool bk[1005][1005][4],bk2[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){

        cin>>n>>m>>k;//cout<<n<<" "<<m<<" "<<k<<" ";
        cin>>x>>y>>d;//cout<<"k";
        for(int ii=1;ii<=n;ii++){
            for(int j=1;j<=m;j++){
                cin>>c[ii][j];//cout<<ii<<" "<<j<<endl;
                bk2[ii][j]=0;
            for(int h=0;h<=3;h++){
                bk[ii][j][h]=0;
                }

            }
        }
        bool tt=1;
        bk2[x][y]=1;
        bk[x][y][d]=1;ans=1;
        while(tt and k>0){k--;//cout<<x<<" "<<y<<" "<<d<<endl;
            int nxtx=x,nxty=y;
            if(d==0){
                nxty++;
            }
            if(d==1){
                nxtx++;
            }
            if(d==2){
                nxty--;
            }
            if(d==3){
                nxtx--;
            }
            if(nxtx<=0 or nxtx>n or nxty<=0 or nxty>m or c[nxtx][nxty]=='x'){d=(d+1)%4; continue;}
            if(bk[nxtx][nxty][d]){
                tt=0;break;
            }
            x=nxtx,y=nxty;
            bk[x][y][d]=1;
            if(!bk2[x][y]){//cout<<x<<" "<<y<<endl;
                ans++;
                bk2[x][y]=1;
            }



        }cout<<ans<<endl;


    }


   return 0;


}