#include<bits/stdc++.h>
using namespace std;
int T,m,n,k,x,y,d,pss[1010][1010],ans;
char a[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k>>x>>y>>d;
        ans=0;
        x--;
        y--;
        for(int j=0;j<n;j++) cin>>a[j];
        for(int j=1;j<=k;j++){
            if(pss[x][y]!=i){
                pss[x][y]=i;
                ans++;
            }
            if(d==0){
                if(a[x][y+1]=='x'||y+1>=m) d=1;
                else y++;
            }
            else if(d==1){
                if(a[x+1][y]=='x'||x+1>=n) d=2;
                else x++;
            }
            else if(d==2){
                if(a[x][y-1]=='x'||y-1<0) d=3;
                else y--;
            }
            else if(d==3){
                if(a[x-1][y]=='x'||x-1<0) d=0;
                else x--;
            }
        }
        if(pss[x][y]!=i){
            pss[x][y]=i;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}