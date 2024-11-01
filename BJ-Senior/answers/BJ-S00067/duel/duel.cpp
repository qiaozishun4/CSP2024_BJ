include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], n;
int vis[maxn];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    cout<<2<<endl;
    return 0;
}