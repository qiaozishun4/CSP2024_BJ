#include<bits/stdc++.h>
using namespace std;
char win[1010][1010];
long long won[1010][1010]={ };
int main()
{
    freopen("explore.in","r",stdin);
    freopen("esplore.out","w",stdout);
    int t,num[10]={ },sum;
    cin>>t;
    for(int i=0;i<t;i++){
       int n,m,k;
       cin>>n>>m>>k;
       int x,y,d;
       cin>>x>>y>>d;
       won[x][y]=1;
       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             cin>>win[i][j];
          }
       }
       for(int p=0;p<k;p++){
          if(d==0){
             if((y+1)<m)
             if(win[x][y+1]!='x'){
                y++;
                won[x][y]=1;
             }
             else d=(d+1)%4;
          }
          if(d==1){
             if((x+1)<n)
             if(win[x+1][y]!='x'){
                x++;
                won[x][y]=1;
             }
             else d=(d+1)%4;
          }
          if(d==2){
             if((y-1)>=0)
             if(win[x][y-1]!='x'){
                y--;
                won[x][y]=1;
             }
             else d=(d+1)%4;
          }
          if(d==3){
             if((x-1)>=0)
             if(win[x-1][y]!='x'){
                x--;
                won[x][y]=1;
             }
             else d=(d+1)%4;
          }
       }
       for(int t=0;t<n;t++){
          for(int v=0;v<m;v++){
          if(won[t][v]==1)
             sum++;
          }
       }
       num[i]=sum;
       sum=0;
    }
    for(int i=0;i<t;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
