#include <iostream>
#include <algorithm>
using namespace std;

long long a[100005], b[100005];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    sort(a+1, a+n+1);
    long long last = 0;
    for (int i = 1; i <= 100000; i++){
        last = max(1ll*0, last - b[i]);
        last += b[i];
    }
    cout << last << endl;
return 0;}
