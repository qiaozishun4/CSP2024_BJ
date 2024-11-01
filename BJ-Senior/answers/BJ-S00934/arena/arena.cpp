#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,t,ans;
int a[100005];
int num[20][100005];
int c[100005];
bool win[25][25];
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    int k = ceil(log2(n*1.0));
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> c[i];
    }
    for(int i = 1;i <= k;i++){
        for(int j = 1;j <= (1<<i-1);j++){
            char ca;
            cin >> ca;
            win[i][j] = (ca-'0');
        }
    }
    int __;
    cin >> __;
    while(__--){
        int y[4];
        ans = 0;
        cin >> y[0] >> y[1] >> y[2] >> y[3];
        for(int xx = 1;xx <= m;xx++){
            k = ceil(log2(c[xx]*1.0));
            for(int i = 1;i <= (1<<k);i++){
                num[0][i] = i;
            }
            for(int x = 0;x < k;x++){
                for(int i = 1;i <= (1<<k-x-1);i++){
                    int wa = (i*2)*(1<<x),wb = (i*2)*(1<<x);
                    if(wa <= c[xx] && !win[x][i]){
                        num[x+1][wa] = (((a[num[x][wa]]^(y[num[x][wa]%4]))>x)?wa:wb);
                    }
                    if(wb <= c[xx] && win[x][i]){
                        num[x+1][wa] = (((a[num[x][wb]]^(y[num[x][wb]%4]))>x)?wb:wa);
                    }
                }
            }
            int an = 0;
            for(int i = 1;i <= (1<<k);i++){
                bool flag = 1;
                for(int j = 1;j <= k;j++){
                    int yy = i;
                    if((i-1)&(1<<j)){
                        yy = (i-1)^(1<<j)+1;
                    }
                    if(num[j][yy] && num[j][yy] != i){
                        flag = 0;
                        break;
                    }
                }
                an += flag*i;
            }
            ans ^= (an*xx);
        }
        cout << ans << endl;
    }
}
