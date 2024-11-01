#include <bits/stdc++.h>
using namespace std;

int n,a[105],c[105],v[105];
long long ans;
void dfs(int x){
    if (x > n){
        long long sum = 0;
        for (int i = 1 ; i <= n ; i++){
            sum += v[i];
        }
        ans = max(ans,sum);
        return ;
    }
    c[x] = 0; v[x] = 0;
    for(int i = x - 1 ; i >= 1 ; i--){
        if (c[i] == c[x]){
            if (a[i] == a[x]){
                v[x] = a[x];
            }
            break;
        }
    }
    dfs(x+1);
    c[x] = 1; v[x] = 0;
    for(int i = x - 1 ; i >= 1 ; i--){
        if (c[i] == c[x]){
            if (a[i] == a[x]){
                v[x] = a[x];
            }
            break;
        }
    }
    dfs(x+1);
    return ;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> n;
        for (int i = 1 ; i <= n ; i++){
            cin >> a[i];
            v[i] = 0; c[i] = -1;
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
