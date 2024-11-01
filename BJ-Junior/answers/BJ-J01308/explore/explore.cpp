#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int n,m,k,x,y,ch;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&ch);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                scanf("%c",&a[i][j]);
            }
        }
        a[x][y] = '1';
        for(int i = 0;i < k;i++){
            if(ch == 0){
                if(a[x][y + 1] == 'x' || a[x][y + 1] == 0){
                    ch++;
                }else{
                    y++;
                    a[x][y] = '1';
                }
            }else if(ch == 1){
                if(a[x + 1][y] == 'x' || a[x + 1][y] == 0){
                    ch++;
                }else{
                    x++;
                    a[x][y] = '1';
                }
            }else if(ch == 2){
                if(a[x][y - 1] == 'x' || a[x][y - 1] == 0){
                    ch++;
                }else{
                    y--;
                    a[x][y] = '1';
                }
            }else{
                if(a[x - 1][y] == 'x' || a[x - 1][y] == 0){
                    ch = 0;
                }else{
                    x--;
                    a[x][y] = '1';
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(a[i][j] == '1'){
                    ans++;
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
