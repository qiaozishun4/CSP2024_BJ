#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

#define MY_TEST

int main() {
    #ifdef MY_TEST
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    #else
    ios::sync_with_stdio(1);
    freopen("poker3.in", "r", stdin);
    freopen("poker3.out", "w", stdout);
    #endif

    int n;
    string str, wanted[52] = {
        "DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
        "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK",
        "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
        "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"
    };
    map<string, bool> app;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> str;
        app[str] = true;
    }
    int ans = 0;
    for (int i = 0; i < 52; ++i)
        if (!app[wanted[i]])
            ++ans;
    cout << ans << '\n';

    return 0;
}