#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool a[1005][1005], b[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        int n,m,k,x,y,d;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char s;
                cin >> s;
                if(s=='.')a[i][j]=1;
                if(s=='x')a[i][j]=0;
                b[i][j]=0;
            }
        }
        b[x][y]=1;
        while(k--){
            int xs=x+dx[d], ys=y+dy[d];
            if(1<=xs&&xs<=n&&1<=ys&&ys<=m&&a[xs][ys]){
                b[xs][ys]=1;
                x=xs,y=ys;
            }else d=(d+1)%4;
        }
        int c=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(b[i][j])c++;
            }
        }
        printf("%d\n", c);
    }
}
