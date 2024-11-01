#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, a[100005];
int vis[100005];
int main(){
   freopen("duel.in", "r",stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1,  a + n + 1);
    //greedy
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j < i; j ++){
            if(vis[i] == 0 &&vis[j] != -1){ //hunter whether available  /  still alive?
                if(a[i] > a[j]){
                    vis[i] = 1;
                    vis[j] = -1;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(vis[i] == 0 || vis[i] == 1){
            ans ++;
        }

    }
    cout << ans;

return 0;
}




