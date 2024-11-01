#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int m, n, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d", min(n * m, k));
    return 0;
}