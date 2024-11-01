#include<bits/stdc++.h>
using namespace std;
int a[1009][1009]={0};//0=障碍 1=通路 2=走过的路
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t,n,m,k,x,y,d,ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int j=1;j<=n;j++){
            string s;
            cin >> s;
            for(int i=0;i<s.size();i++){
                if(s[i]=='x') a[j][i+1]=0;
                if(s[i]=='.') a[j][i+1]=1;
            }
        }
        ans=1;
        a[x][y]=2;
        for(int i=1;i<=k;i++){
            if(a[x+dx[d]][y+dy[d]]==0){
                d++;
                d%=4;
            }
            else if(a[x+dx[d]][y+dy[d]]==1){
                x+=dx[d];
                y+=dy[d];
                a[x][y]=2;
                ans++;
            }else{//=2
                x+=dx[d];
                y+=dy[d];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
   