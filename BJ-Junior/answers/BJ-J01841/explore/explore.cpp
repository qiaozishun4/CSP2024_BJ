#include<bits/stdc++.h>
using namespace std;
string s[1005];
int ans[10];
int ji[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for (int z=1;z<=t;z++){
        int sum=1;
        int n,m,k;
        cin>>n>>m>>k;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ji[i][j]=0;
            }
        }
        int x,y,d;
        cin>>x>>y>>d;
        y-=1;
        x-=1;
        ji[x][y]=1;
        for (int i=0;i<n;i++){
            cin>>s[i];
        }
        for (int i=1;i<=k;i++){
            int x1,y1;
            if (d==0){
                x1=x;
                y1=y+1;
            }
            if (d==1){
                x1=x+1;
                y1=y;
            }
            if (d==2){
                x1=x;
                y1=y-1;
            }
            if (d==3){
                x1=x-1;
                y1=y;
            }
            if (x1>=0&&x1<n&&y1>=0&&y1<m&&(s[x1][y1]=='.')){
                x=x1;
                y=y1;
                if (ji[x][y]==0){
                    sum++;
                }
                ji[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        ans[z]=sum;
    }
    for (int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
