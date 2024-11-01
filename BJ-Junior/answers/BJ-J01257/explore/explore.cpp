#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,k,x,y,d;
string s;
char c[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++) c[i][j]=s[j-1];
        }
        c[x][y]='*';
        for(int i=0;i<k;i++){
            if(d==0){
                if(c[x][y+1]=='x'||y+1>m) d=1;
                else{
                    y++;
                    if(c[x][y]!='*') ans++;
                    c[x][y]='*';
                }
            }
            else if(d==1){
                if(c[x+1][y]=='x'||x+1>n) d=2;
                else{
                    x++;
                    if(c[x][y]!='*') ans++;
                    c[x][y]='*';
                }
            }
            else if(d==2){
                if(c[x][y-1]=='x'||y-1<1) d=3;
                else{
                    y--;
                    if(c[x][y]!='*') ans++;
                    c[x][y]='*';
                }
            }
            else if(d==3){
                if(c[x-1][y]=='x'||x-1<1) d=0;
                else{
                    x--;
                    if(c[x][y]!='*') ans++;
                    c[x][y]='*';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
