#include <bits/stdc++.h>
using namespace std;

int n,vis[205][205],cnt;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        char color,num;
        cin >> color >> num;
        if (!vis[color][num]) {
            vis[color][num] = 1;
            cnt++;
        }
    }
    cout << max(0,52-cnt);
    return 0;
}
