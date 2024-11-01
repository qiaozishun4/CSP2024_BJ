#include <bits/stdc++.h>
using namespace std;
string a[55];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i)
        for (int j=0; j<i; ++j)
            if (a[i] == a[j])
            --n;
    cout << 52-n;
    return 0;
}