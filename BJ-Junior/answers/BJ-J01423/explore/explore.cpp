#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int b[1010][1010];
int t;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d,x2,y2,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        x2=x;y2=y;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                b[j][k]=0;
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>a[j][k];
            }
        }
        for(int j=1;j<=k;j++){
            if(d==0){
                y2+=1;
            }else if(d==1){
                x2+=1;
            }else if(d==2){
                y2-=1;
            }else if(d==3){
                x2-=1;
            }
            if(a[x2][y2]=='x'){
                d=(d+1)%4;
            }else{
                b[x2][y2]=1;
                x=x2;y=y2;
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                ans+=b[j][k];
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}

