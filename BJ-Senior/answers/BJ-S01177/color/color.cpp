#include<bits/stdc++.h>
using namespace std;
int a[105] , flag[105] , sum = 0;

void dfs(int c , int n){
    if(c > n){
        int lastr = 0 , lastb = 0 , cnt = 0;
        for(int i = 1;i <= n;i ++){
            if(flag[i]){
                if(a[lastb] == a[i])cnt += a[i];
                lastb = i;
            }
            else{
                if(a[lastr] == a[i])cnt += a[i];
                lastr = i;
            }
        }
        sum = max(sum , cnt);
        return ;
    }
    flag[c] = 0;
    dfs(c + 1 , n);
    flag[c] = 1;
    dfs(c + 1 , n);
}
signed main(){

    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--){
        memset(a , 0 , sizeof(a));
        memset(flag , -1 , sizeof(flag));
        sum = 0;
        int n;
        cin >> n;
        for(int i = 1;i <= n;i ++)cin >> a[i];
        dfs(1 , n);
        cout << sum << "\n";
    }


    return 0;
}