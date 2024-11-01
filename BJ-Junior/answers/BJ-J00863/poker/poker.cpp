#include<bits/stdc++.h>
using namespace std;

long long n;
set<string> a;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        string x;
        cin >> x;
        a.insert(x);
    }

    cout << 52-a.size();
    return 0;
}
