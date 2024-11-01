#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 +5;
ll a[N];
int n;
int main() {
    freopen("duel.in","r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    int j = 2;
    for(int i = 1; i <= n; i++) {
        bool flag = false;
        for(; j <= n; j++) {
            if(a[i] < a[j]){
                j++;
                flag = true;
                ans++;
                break;
            }
        }
        if(!flag ) {
           break;
        }
    }
    cout << n - ans;
    return 0;
}
