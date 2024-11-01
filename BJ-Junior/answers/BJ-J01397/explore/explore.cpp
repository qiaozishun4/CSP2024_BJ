#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
long long sum=0;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        sum=1;
        int x1=x,y1=y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                y1++;
            }
            else if(d==1){
                x1++;
            }
            else if(d==2){
                y1--;
            }
            else if(d==3){
                x1--;
            }

            if((x1!=0 && y1!=0) && a[x1][y1]!='x'){
                sum++;
                x=x1;
                y=y1;
            }
            else{
                x1=x;
                y1=y;
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}