#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,xx,yy,dd;
char aa[1099][1099];
int zong[9];
bool gg[1099][1099]={};
int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){

    cin>>n>>m>>k;
    cin>>xx>>yy>>dd;
    gg[xx][yy]=1;
    for(int j=1;j<=n;j++)
    for(int o=1;o<=m;o++){
    cin>>aa[j][o];
    }
    for(int j=1;j<=k;j++){
       //     cout<<xx<<" "<<yy<<" "<<dd<<endl;
        if(dd==0){
        if(aa[xx][yy+1]!='x' and xx>=1 and xx<=n and yy+1>=1 and yy+1<=m){
        gg[xx][yy+1]=1;yy=yy+1;
        }else{dd=(dd+1)%4;continue;}


        }
        if(dd==1){
        if(aa[xx+1][yy]!='x' and xx+1>=1 and xx+1<=n and yy>=1 and yy<=m){
        gg[xx+1][yy]=1;xx=xx+1;
        }else{dd=(dd+1)%4;continue;}


        }

        if(dd==2){
        if(aa[xx][yy-1]!='x' and xx>=1 and xx<=n and yy-1>=1 and yy-1<=m){
        gg[xx][yy-1]=1;yy=yy-1;
        }else{dd=(dd+1)%4;//cout<<dd<<endl;
        continue;}


        }
        if(dd==3){
        if(aa[xx-1][yy]!='x' and xx-1>=1 and xx-1<=n and yy>=1 and yy<=m){
        gg[xx-1][yy]=1;xx=xx-1;
        }else{dd=(dd+1)%4;continue;}


        }

    }int uuu=0;
    for(int j=1;j<=n;j++)
    for(int l=1;l<=m;l++){
    if(gg[j][l]==1){
    uuu++;//cout<<j<<" "<<l<<" "<<uuu<<endl;
    gg[j][l]=0;
    }}

    zong[i]=uuu;
    uuu=0;

    }

    for(int i=1;i<=t;i++)
    cout<<zong[i]<<endl;
   fclose(stdin);
  fclose(stdout);
    return 0;
}