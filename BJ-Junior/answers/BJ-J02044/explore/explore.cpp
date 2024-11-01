#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k;
char temp;

bool a[1005][1005]={0};
bool stampp [1005][1005]={0};
int x,y,d,sum,xn,ynn;
int main(){
 freopen("explore.in","r",stdin);
 freopen("explore.out","w",stdout);
cin>>T;
for(int i =1;i<=T;i++){
for(int iiii=1;iiii<=1004;iiii++){
    for(int jjjj=1;jjjj<=1004;jjjj++){
         a[iiii][jjjj]=0;
    }
}

        sum=0;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    stampp[x][y]=1;
    for (int j=1;j<=n;j++){
        for(int ji=1;ji<=m;ji++){
        cin>>temp;
        if(temp=='.'){
            a[j][ji]=0;
        }
        else{
            a[j][ji]=1;
        }
        }
    }
    for(int step =1;step<=k;step++){
        xn=x;ynn=y;
        if(d==0){

                ynn++;

        }
        else if(d==1){
            xn++;
        }
        else if(d==2){

            ynn--;
        }
        else{
            xn--;
        }


        if(a[xn][ynn]==0){
            if(xn>=1&&xn<=n&&ynn>=1&&ynn<=m){
                x=xn,y=ynn;
                stampp[x][y]=1;
                continue;
            }
            else{
                d=(d+1)%4;
            }
        }
        else{
            d=(d+1)%4;  continue;
        }


    }
    for(int ii=1;ii<=n;ii++){
        for(int jjj=1;jjj<=m;jjj++){
            if(stampp[ii][jjj]==1){
                stampp[ii][jjj]=0;
                sum++;
            }
        }
    }
    cout<<sum<<endl;
}

return 0;
}
