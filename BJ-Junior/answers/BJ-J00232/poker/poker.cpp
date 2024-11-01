#include <iostream>
#include <map>
using namespace std;
#define ll long long
ll n;
string ch;
string cd = "A23456789TJQK";
string cd1 = "DCHS";
map <string, ll> ma;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ch;
        ma[ch] = 1;
    }
    ll cc = 0;

    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 12; j++) {

            string tmp = (string){cd1[i]} + (string){cd[j]};
            if(ma[tmp] == 0) {
                cc++;
                ma[tmp] = 1;
            }
        }
    }
    cout << cc;
    return 0;
}
