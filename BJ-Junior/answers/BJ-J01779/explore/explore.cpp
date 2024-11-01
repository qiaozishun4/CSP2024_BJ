#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
   int n,x,y,sx,sy,k,d,sum=1;
    cin>>n;
    for(int i=1;i<=n;i++){
            char c[1001][1001];
        cin>>x>>y>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>c[i][j];
            }
        }
        if(k==1){

            if(d==0){
            if(c[sx][sy+1]=='.'){
                sum++;
            }
        }else if(d==1){
            if(c[sx+1][sy]=='.'){
                sum++;
            }
        }else if(d==2){
            if(c[sx][sy-1]=='.'){
                sum++;
            }
        }else if(d==3){
            if(c[sx-1][sy]=='.'){
                sum++;
            }
        }
        }
        else{
            if(d==0){
                for(int j=1;j<=min(y-1,k);j++){
                    sum++;
                }
            }else if(d==1){
                for(int j=1;j<=min(y-1,k-3);j++){
                    sum++;
                }
            }else if(d==2){
                for(int j=1;j<=min(y-1,k-2);j++){
                    sum++;
                }
            }else{
                for(int j=1;j<=min(y-1,k-1);j++){
                    sum++;
                }
            }
        }

        cout<<sum<<endl;
        sum=1;
    }





    fclose(stdin);
    fclose(stdout);


    return 0;
}
