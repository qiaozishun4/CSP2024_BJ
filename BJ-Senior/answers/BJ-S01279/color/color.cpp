#include<bits/stdc++.h>
using namespace std;
int a[200010], b[1000010];

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
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    t = read();
    for (int i = 1; i <= t; i++){
        int n;
        n = read();
        for (int j = 1; j <= n; j++){
            a[j] = read();
            b[a[j]]++;
        }
        int maxn = 0;
        for (int j = 1; j <= 1000000; j++)
            if (b[j] > maxn)
                maxn = b[j];
        int ans = a[1];
        while(maxn--){
            for (int j = 1; j <= 1000000; j++)
                if (b[j] == maxn)
                    ans += ((b[j] - 1) * j);
        }
        cout << ans << '\n';
    }

    return 0;
}