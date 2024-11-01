#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, d, x, y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char a[1010][1010];
int main(){
    fropen("explore.in","r",stdin);
    fropen("explore.out","w",stdout);
    int cnt=1;
    cin >> t;
    while (t--){
        cin >> n >> m >> k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<k;i++){
            if(x+dx[d]>=0&&x+dx[d]<m&&y+dy[d]>=0&&y+dy[d]<m&&a[y+dy[d]][x+dx[d]]=='.'){
                x=x+dx[d];
                y=y+dy[d];
                cnt++;
            }else{
                d=(d+1)%4;
            }
        }
    }
    cout << cnt;
    return 0;
}
