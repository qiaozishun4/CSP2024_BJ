#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    vector<string> a(52);
    int n=0, ans=0, ina=0;
    cin >> n;
    ans = n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        bool havea = false;

        for (int j=0; j<i; j++) {
            if (a[j] == a[i]) {
                havea = true;
                ans -= 1;
                break;
            }
        }
    }
    cout << 52-ans << endl;
    return 0;
}