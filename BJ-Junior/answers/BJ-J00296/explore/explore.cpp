#include<bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,d;
char mp[1001][1001];
int main(){
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int e=1;e<=t;e++){
        cin>>n>>m>>k>>sx>>sy>>d;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mp[i][j]='-999';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mp[i][j];
            }
        }
        if(mp[sx+1][sy]=='x'||mp[sx+1][sy]=='-999'&&mp[sx][sy+1]=='x'||mp[sx][sy+1]=='-999'&&mp[sx][sy-1]=='x'||mp[sx][sy-1]=='-999'&&mp[sx-1][sy]=='x'||mp[sx-1][sy]=='-999') cout<<1;
        else cout<<2;
    }
    return 0;
}
