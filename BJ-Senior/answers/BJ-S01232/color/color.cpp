#include <iostream>
#include <string.h>
using namespace std;
int T, n ,a[100000], d[100000], res = 0, ans = 0;//1 blue   0 red
void dfs(int t, int l){
    if(t == l + 1){
            ans = 0;
        for(int i = 1; i <= l; i ++){
            for(int j = i - 1; j >=1; j --){
                if(d[i] == d[j] && a[i] == a[j]){
                    ans += a[i];
                    break;
                }
            }
        }
    res = max(ans, res);
        return ;
    }
    for(int i = 0;i <= 1; i ++){
        if(d[t] == -1){
        d[t] = i;
        dfs(t + 1,l);
        d[t] = -1;
        }
    }
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out","w",stdout);

    cin >> T;
    while(T --){
        cin >>n;
        for(int i = 1; i <= n; i ++){
                cin >> a[i];
                d[i] = -1;
        }
        res = 0;
        dfs(1, n);

        cout << res << endl;
    }




return 0;
}
