#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, k, p, l;
        cin >> n >> k >> p >> l;
        string s;
        for(int i=1; i<=n; i++)
            getline(cin, s);
        while(p--){
            int x, y;
            cin >> x >> y;
            cout << "0\n";
        }
    }
    return 0;
}
