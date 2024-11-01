#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    set<string> s;
    cin>>n;
    for(int i = 0;i<n;i++){
        string t;
        cin>>t;
        s.insert(t);
    }
    cout<<52-s.size();

    return 0;
}
