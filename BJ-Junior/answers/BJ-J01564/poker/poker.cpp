#include<iostream>
#include<set>
#define ll long long
using namespace std;
ll n;
string x;
set <string> s;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> x;
        s.insert(x);
    }
    cout << 52 - s.size();
    return 0;
}
