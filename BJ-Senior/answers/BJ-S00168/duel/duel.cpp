#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    int f[n+1];
    int flag[n+1];
    for (int i = 1; i <= n; i++){
        cin >> f[i];
        flag[i] = 0;
    }
    sort(f+1,f+n+1);
    int x = 0;
    for (int i = 1; i <= n; i++){
        if(f[i-1]!=f[i]){
            x++;
        }
        flag[x]++;
    }
    int ans = 0;
    for (int i = 1 ; i <= x; i++){
        ans =max(ans,flag[i]);
    }
    cout << ans;
    return 0;
}
