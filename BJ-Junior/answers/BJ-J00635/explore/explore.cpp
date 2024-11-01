#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string s[1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        while(k--){
            int tx=x+dx[d],ty=y+dy[d];
            if(tx<=0||tx>n||ty<=0||ty>m||s[x][y-1]=='x'){
                d++;
                d%=4;
            }else{
                x=tx;
                y=ty;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
