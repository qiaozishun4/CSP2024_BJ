#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
int t;
int n,  m;
ll L, V;
ll d[N], v[N], a[N], p[N];
int bucket[N];
int main() {
    freopen("color.in","r", stdin);
    freopen("color.out", "w", stdout);
    cin>>t;
    while(t--){
        ll sum  = 0 ;
        cin >> n;
        for(int i = 1 ;i <= n ;i++) {
            ll t ;
            cin >> t;
            sum = max(sum, t);
        }
        cout << sum << endl; ;
    }

    return 0;
}
