#include<bits/stdc++.h>
using namespace std;
const char nmb[14]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'},clr[5]={'0','D','C','H','S'};
int p[15][6],n,x,y,ans;
char m1,m2;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m1>>m2;
        for(int j=1;j<=4;j++) if(m1==clr[j]){
            y=j;
            break;
        }
        for(int j=1;j<=13;j++) if(m2==nmb[j]){
            x=j;
            break;
        }
        p[x][y]=1;
    }
    for(int i=1;i<=13;i++) for(int j=1;j<=4;j++) if(p[i][j]==0) ans++;
    cout<<ans;
    return 0;
}