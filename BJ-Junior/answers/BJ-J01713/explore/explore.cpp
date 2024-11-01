#include<bits/stdc++.h>
using namespace std;
int n,m,k,b;
int d,x2,y2;
int s[5];
int ans;
void sum(int x){
    while(k!=0){
        if(a[s[1]][s[2]+1]!='x'&&x==0&&s[1]<=n&&s[1]>=1&&(s[2]+1)<=m&&(s[2]+1)>=1){
        s[2]++;g[s[1]][s[2]]=1;k--;}
        else
        x=(x+1)%4;
        if(a[s[1]+1][s[2]]!='x'&&x==1&&(s[1]+1)<=n&&(s[1]+1)>=1&&s[2]<=m&&s[2]>=1){
        s[1]++;g[s[1]][s[2]]=1;k--;}
        else
        x=(x+1)%4;
        if(a[s[1]][s[2]-1]!='x'&&x==2&&s[1]<=n&&s[1]>=1&&(s[2]-1)<=m&&(s[2]-1)>=1){
        s[2]--;g[s[1]][s[2]]=1;k--;}
        else
        x=(x+1)%4;
        if(a[s[1]-1][s[2]!='x'&&x==3&&(s[1]-1)<=n&&(s[1]-1)>=1&&s[2]<=m&&s[2]>=1){
        s[1]--;g[s[1]][s[2]]=1;k--;}
        else
        x=(x+1)%4;
}   }
int main(){
    freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    cin>>b;
    for(int i=1;i<=b;i++){
    cin>>n>>m>>k;
    char a[n][m];
    char g[n][m];
    cin>>x2>>y2>>d;
    for(int j=1;j<=n;j++)
    for(int i=1;i<=m;i++)
    cin>>a[j][i];
    s[1]=x2;
    s[2]=y2;
    sum(d);
    for(int j=1;j<=n;j++)
    for(int i=1;i<=m;i++){
    if(g[j][i]==1)ans++;
    cout<<ans<<endl;
    }}
    return 0;
}