#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
string s[1000005];
int dy[40]={1,0,-1,0},dx[40]={0,-1,0,1};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        int num=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
            cin>>s[j];
        int cs=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[x+dx[d]][y+dy[d]]=='.'&&x+dx[d]<=n&&y+dx[d]>=1&&x+dy[d]<=m&&y+dy[d]>=1){
                    x=x+dx[d];
                    y=y+dy[d];
                    num++;
                    cs++;
                    cout<<x<<" "<<y<<endl;
                }
                else{
                    d=(d+1)%4;
                    cs++;
                    cout<<d<<endl;
                }
                if(cs>k) break;
            }
        cout<<num<<'\n';
    }
    return 0;
}
