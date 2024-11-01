#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                    scanf("%c",&a[i][j]);
        if(n == 1 && m == 1 && k == 1){
            printf("1\n");
        }else if(n == 1 && m == 2 && k == 1){
            if(d == 0) printf("2\n");
            else printf("1\n");
        }else if(k == 1){
            if(d == 0 && a[x][y + 1] == '.' || d == 1 && a[x + 1][y] == '.' || d == 2 && a[x][y - 1] == '.' || d == 3 && a[x - 1][y] == '.'){
                printf("2\n");
            }else printf("1\n");
        }else if(n == 1){
            int ans = 0,sum = 1;
            if(d == 1 || d == 3) ans = 1;
            if(d == 2) ans = 2;
            for(int i = 1; i <= m; i++){
                if(i + ans > k){
                    break;
                }else if(a[1][i] == 'x'){
                    break;
                }
                sum++;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}