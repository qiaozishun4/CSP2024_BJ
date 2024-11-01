#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,a[4][2] = {{0,1},{1,0},{0,-1},{-1,0}},x,y;
char c[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>c[i][j];
            }
        }
        for(int i = 0;i<k;i++){
            c[x][y] = '#';
            int x1 = x+a[d][0];
            int y1 = y+a[d][1];
            if(x1<n&&1>=0&&y1<m&&y1>=0&&c[x1][y1]!='x'){
                x = x1;
                y = y1;
            }else{
                d+=1;
                d%=4;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(c[i][j] == '#'){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
