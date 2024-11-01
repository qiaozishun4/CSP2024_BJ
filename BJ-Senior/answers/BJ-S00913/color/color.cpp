#include<bits/stdc++.h>
using namespace std;
int t, n;
int a[200005], tong[1000005], eq[200005], c[200005];
char color[200005];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while(t--){
        cin >> n;
        memset(tong, 0xff, sizeof(tong));
        memset(c, 0, sizeof(c));
        memset(color, '\0', sizeof(color));
        long long ans = 0, r = -1, b = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            eq[i] = tong[a[i]];
            tong[a[i]] = i;
        }
        for(int i = n; i >= 1; i--){
            if(color[i] == '\0'){
                color[i] = color[i + 1] == '\0' ? 'b' : color[i + 1] == 'b' ? 'r' : 'b';
                if(eq[i] != -1){
                    color[eq[i]] == color[i];
                    c[eq[i]] += a[i];
                }
            }else{
                if(eq[i] != -1){
                    color[eq[i]] == color[i];
                    c[eq[i]] += a[i];
                }
                if(color[i] != color[i + 1]) continue;
                if(eq[i + 1] != i){
                    if(eq[i + 1] == -1) continue;
                    if(a[i] < a[i + 1]){
                        c[i] -= a[i];
                        color[i] = color[i + 1] == 'b' ? 'r' : 'b';
                    }else{
                        c[eq[i + 1]] -= a[i + 1];
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            ans += c[i];
        }
        cout << ans << endl;
    }
    return 0;
}
