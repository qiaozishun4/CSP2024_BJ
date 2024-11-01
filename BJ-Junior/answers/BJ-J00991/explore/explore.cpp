#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, cnt=0;
    cin>>t;
    while(t--){
        //重置//
        cnt=0;
        //定义&输入//
        int n, m, k, x, y, d;
        char c[1005][1005];
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        //模拟//
        while(k--){
            if(d==0&&c[x][y+1]=='.'&&x>=1&&x<=n&&y>=1&&y<=m){
                    cnt++;
                    y++;
            }
            else if(d==1&&c[x+1][y]=='.'&&x>=1&&x<=n&&y>=1&&y<=m){
                    cnt++;
                    x++;
            }
            else if(d==2&&c[x][y-1]=='.'&&x>=1&&x<=n&&y>=1&&y<=m){
                    cnt++;
                    y--;
            }
            else if(d==3&&c[x-1][y+1]=='.'&&x>=1&&x<=n&&y>=1&&y<=m){
                    cnt++;
                    x--;
            }
            else d=(d+1)%4;
        }
        cout<<cnt+1<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}

