#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,m,n,k,x,y,d,ans=1;
    char s[105][105];
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int t=1;t<=m;t++){
                cin>>s[j][t];
            }
        }
        for(int j=1;j<=n;j++){
            for(int t=1;t<=m;t++){
                if(d==1){
        x+=1;
        if(x>n){
            x-=1;
            d=2;
        }
        else{
            ans++;
        }
        k--;
    }
    else if(d==2){
        y-=1;
        if(y<m){
            y+=1;
            d=3;
        }
        else{
            ans++;
        }
        k--;
    }
    else if(d==3){
        x-=1;
        if(x<n){
            x+=1;
            d=0;
        }
        else {
            ans++;
        }
        k--;
    }
    else{
        y+=1;
        if(y>m){
            y-=1;
            d=1;
        }
        else{
            ans++;
        }
        k--;
    }
    if(k==0){
        cout<<ans;
        ans=1;
        continue;
    }
    }
            }
        }
    return 0;
}