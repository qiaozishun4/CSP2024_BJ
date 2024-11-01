#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, a[100010];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int ans=n, minn=0;
    for(int i=1; i<n; i++){
        if(a[i]>a[minn]){
            ans--;
            minn++;
        }
    }
    printf("%d", ans);
    return 0;
}
