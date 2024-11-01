#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, maxn=0, have, now=0;
    cin >> n;
    have = n;
    for (int i=0; i<n; ++i){
        int num;
        cin >> num;
        maxn = max(maxn, num);
        ++a[num];
    }
    for (int i=0; i<=maxn&&have>0; ++i){
        if (have>=2*a[i]){
            n-=a[i];
            have-=2*a[i];
        }else{
            have-=max(0, a[i]-(n-have));
            if (a[i] > have-a[i])
            n-=have;
            break;
        }
    }cout << n;
    return 0;
}