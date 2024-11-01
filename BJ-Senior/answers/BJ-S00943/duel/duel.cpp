#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, cnt;
int x;
int a[N], ans;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;

    x = n;
    while (n --){
        scanf("%d", &m);
        a[m] ++;
    }

    int t = 0;
    for (int i = 0; i < N && cnt < x; i++){
        if (a[i] != 0){
            cnt += a[i];

            t = max(t - a[i], 0);
            t += a[i];
        }
    }

    cout << t << '\n';

    return 0;
}
