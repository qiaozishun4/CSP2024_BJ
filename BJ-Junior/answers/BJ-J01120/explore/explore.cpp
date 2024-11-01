#include<bits/stdc++.h>
using namespace std;
 char a[1010][1010];
int t,i,j,m,k,n,x,y,d,num;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(j=1;j<=k;j++){
            if(d==0){
               if(a[x][y+1]=='.'){
                    y=y+1;
                    num++;
               }
               else{
                    d=(d+1)%4;
               }
            }
            if(d==1){
                if(a[x+1][y]=='.'){
                    x++;
                    num++;
               }
               else{
                    d=(d+1)%4;
               }
            }
            if(d==2){
                if(a[x][y-1]=='.'){
                    y--;
                    num++;
               }
               else{
                    d=(d+1)%4;
               }
            }
            if(d==3){
                if(a[x-1][y]=='.'){
                    x--;
                    num++;
               }
               else{
                    d=(d+1)%4;
               }
            }
        }

            cout<<num<<endl;
            num=0;
    }

    return 0;
}