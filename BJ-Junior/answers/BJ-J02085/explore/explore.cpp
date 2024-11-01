#include<bits/stdc++.h>
using namespace std;
int t;
char a[1003][1003];
bool f[1003][1003];
int n,m,k;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=0;
            }
        }
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                a[i][j+1]=s[j];
            }
        }
        int sum=1;
        while(k--){
            int x1,y1;
            if(d==0){
                x1=x;
                y1=y+1;
            }
            if(d==1){
                x1=x+1;
                y1=y;
            }
            if(d==2){
                x1=x;
                y1=y-1;
            }
            if(d==3){
                x1=x-1;
                y1=y;
            }
            if(a[x1][y1]=='x'||x1<1||x1>n||y1<1||y1>m){
                d=(d+1)%4;
                continue;
            }
            if(f[x1][y1]==0){
                sum++;
                f[x1][y1]=1;
            }
            x=x1;
            y=y1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
