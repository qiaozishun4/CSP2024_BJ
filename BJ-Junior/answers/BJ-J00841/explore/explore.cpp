#include <bits/stdc++.h>
using namespace std;
long long t;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++){
        long long n,m,k,x,y,d,sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        string ma[n+5];
        long long as[n+5][m+5]={0};
        /*for(int asa=0;asa<n+5;asa++){
            for(int asb=0;asb<=m+5;asb++){
                as[asa][asb]=0;
            }
        }//turn to 0
*/
        for(int o=1;o<=n;o++){
            for(int p=1;p<=m;p++){
                cin>>ma[o][p];
            }
        }//cin ma

        for(int kk=1;kk<=k;kk++){
            if(d==0){
                if(ma[x][y+1]=='.'){
                    as[x][y]++;
                    y++;
                    as[x][y]++;
                    //cout<<x<<","<<y;
                }else{
                    d=(d+1)%4;
                    as[x][y]++;
                }
                //cout<<" "<<d<<endl;
            }else if(d==1){
                if(ma[x+1][y]=='.'){
                    as[x][y]++;
                    x++;
                    as[x][y]++;
                    //cout<<x<<","<<y;
                }else{
                    d=(d+1)%4;
                    as[x][y]++;
                }
                //cout<<" "<<d<<endl;
            }else if(d==2){
                if(ma[x][y-1]=='.'){
                    as[x][y]++;
                    y=y-1;
                    as[x][y]++;
                    //cout<<x<<","<<y;
                }else{
                    d=(d+1)%4;
                    as[x][y]++;
                }
                //cout<<" "<<d<<endl;
            }else if(d==3){
                if(ma[x-1][y]=='.'){
                    as[x][y]++;
                    x=x-1;
                    as[x][y]++;
                    //cout<<x<<","<<y;
                }else{
                    d=(d+1)%4;
                    as[x][y]++;
                }
                //cout<<" "<<d<<endl;
            }
        }//go step

        for(int ana=1;ana<=n;ana++){
            for(int anb=1;anb<=m;anb++){
                if(as[ana][anb]!=0)sum++;
                //cout<<ana<<" "<<anb<<"="<<as[ana][anb]<<endl;
            }
        }//check

        cout<<sum<<endl;
    }
    return 0;
}