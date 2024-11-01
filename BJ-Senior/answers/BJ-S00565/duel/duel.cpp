#include <bits/stdc++.h>
using namespace std;

int mon[100001], m[100001], n;
int fight[100001];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    sort(m, m + n);
    int l = -1, t = 0;
    for (int i = 0; i < n; i++){
        if (m[i] != t)
            l++, t = m[i];
        mon[l]++;
    }
    for (int i = 0; i <= l; i++)
        fight[i] = mon[i];
    int x = 0, r = 1;
    while (x <= l && n && r <= l){
        while (r <= l && n){
            if (mon[x] < fight[r]){
                n -= mon[x], fight[r] -= mon[x];
                break;
            }
            else
                mon[x] -= fight[r], n -= fight[r], fight[r] = 0, r++;
        }
        x++, r = x + 1;
    }
    cout << n << endl;
}