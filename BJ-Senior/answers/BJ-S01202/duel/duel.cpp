#include <bits/stdc++.h>
using namespace std;
int n, r[100005], a, b, cnt = 0;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &r[i]);
    }
    sort(r + 1, r + 1 + n);
    a = 1;
    b = n - 1;
    for(int i = n; i >= 1 && b > 0; i--){
        while(b > 0){
            if(r[b] < r[i]){
                cnt++;
                b--;
                break;
            } else{
                b--;
            }
        }
    }
    printf("%d", (n - cnt));
    return 0;
}
