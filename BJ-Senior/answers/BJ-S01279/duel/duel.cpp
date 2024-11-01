#include<bits/stdc++.h>
using namespace std;
int r[100010];
bool check[100010];

int read(){
    int f = 1, x = 0;
    char s = getchar();
    while((s < '0') || (s > '9')){
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while((s >= '0') && (s <= '9')){
        x = x * 10 + s - '0';
        s = getchar();
    }

    return x * f;
}

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    n = read();
    for (int i = 1; i <= n; i++)
        r[i] = read();
    sort(r + 1, r + 1 + n);
    memset(check, false, sizeof(check));
    int ans = n;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++)
            if ((r[j] > r[i]) && !check[j]){
                check[j] = true;
                ans--;
                break;
            }
    }
    cout << ans;

    return 0;
}