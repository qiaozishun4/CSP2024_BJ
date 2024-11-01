#include<bits/stdc++.h>
using namespace std;
char sou[1010][1010];
int dp[1010][1010];
int ans = 0;
void s(int n,int m,int k,int x,int y,int d, char a[1010][1010]){
    if(ans == k){
        return;
    }
    if(d == 0){
        if(y+1 > m || a[x][y+1] == 'x'){
            ans++;
            s(n,m,k,x,y,(d+1)%4,a);
        }else{
            ans++;
            dp[x][y] = 1;
            dp[x][y+1] = 1;
            s(n,m,k,x,y+1,d,a);
        }
    }else if(d == 1){
        if(x+1 > n || a[x + 1][y] == 'x'){
            ans++;
            s(n,m,k,x,y,(d+1)%4,a);
        }else{
            ans++;
            dp[x][y] = 1;
            dp[x+1][y] = 1;
            s(n,m,k,x + 1,y,d,a);
        }
    }else if(d == 2){
        if(y-1 <= 0 || a[x][y - 1] == 'x'){
            ans++;
            s(n,m,k,x,y,(d+1)%4,a);
        }else{
            ans++;
            dp[x][y] = 1;
            dp[x][y - 1] = 1;
            s(n,m,k,x,y-1,d,a);
        }
    }else{
        if(x-1<=0 || a[x - 1][y] == 'x'){
            ans++;
            s(n,m,k,x,y,(d+1)%4,a);
        }else{
            ans++;
            dp[x][y] = 1;
            dp[x-1][y] = 1;
            s(n,m,k,x - 1,y,d,a);
        }
    }
}
int main(){
    int t,n1,m1,k1,x1,y1,d1;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i = 0;i<t;i++){
        ans = 0;
        cin >> n1 >> m1>> k1 >> x1 >> y1 >>d1;
        dp[x1][y1] = 1;
        for(int j = 1;j<=n1;j++){
            for(int k = 1;k<=m1;k++){
                cin >> sou[j][k];
            }
        }
        s(n1,m1,k1,x1,y1,d1,sou);
        int num = 0;
        num = 0;
        for(int j = 1;j<=n1;j++){
            for(int k = 1;k<=m1;k++){
                if(dp[j][k] == 1){
                    num++;
                }
            }
        }
        cout <<num <<endl;
    }
    return 0;
}
