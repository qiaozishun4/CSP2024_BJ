#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int cnt[N], k;
int c;
int ans;
int ma;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    sort(a+1, a+n+1);

    c = 1;
    for(int i=2; i<=n; i++){
        if(a[i]==a[i-1]){
            c++;
        }else{
            cnt[++k] = c;
            c = 1;
        }
    }
    cnt[++k] = c;

    ma = cnt[1];
    for(int i=2; i<=k; i++){
        if(cnt[i]>ma){
            ans += ma;
            ma = cnt[i];
        }else{
            ans += cnt[i];
        }
    }

    printf("%d", n-ans);

    return 0;
}
