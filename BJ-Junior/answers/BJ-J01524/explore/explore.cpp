#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
bool mp[1005][1005],mpa[1005][1005];
char s;
void f(){
    int xz=x,yz=y;
    if(d==0)    yz++;
    if(d==1)    xz++;
    if(d==2)    yz--;
    if(d==3)    xz--;
    if(xz>=1&&xz<=n&&yz>=1&&yz<=m&&mp[xz][yz]){
        x=xz;
        y=yz;
        if(!mpa[x][y])  ans++;
        mpa[x][y]=1;
    }
    else{
        d++;
        if(d==4)    d=0;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s;
                if(s=='.')  mp[i][j]=1;
                else    mp[i][j]=0;
                mpa[i][j]=0;
            }
        }
        mpa[x][y]=1;
        while(k--)  f();
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}