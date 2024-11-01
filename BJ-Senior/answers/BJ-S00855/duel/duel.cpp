#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, maxr = -1;
int r[N], w[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        w[r[i]]++;
        maxr = max(r[i], maxr);
    }
    int los = 0;
    for(int i = 1; i <= maxr; i++){
        if(w[i] && los == 0) los = w[i];
        else if(w[i]){
            int k = w[i] + max(0, los - w[i]);
            los = k;
        }
    }
    cout << los;
    return 0;
}
