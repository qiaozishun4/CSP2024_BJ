#include<bits/stdc++.h>
using namespace std;
int n, id = 1, cnt;
int r[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; i++){
        if(r[id] < r[i]){
            cnt++;
            id++;
        }
    }
    cout << n - cnt;
    return 0;
}
