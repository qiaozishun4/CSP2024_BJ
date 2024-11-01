#include <iostream>
#include <map>
using namespace std;
map<char, int> pp;
int n, a[15][15], ans;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    pp['D'] = 1, pp['C'] = 2, pp['H'] = 3, pp['S'] = 4;
    pp['A'] = 1, pp['2'] = 2, pp['3'] = 3, pp['4'] = 4, pp['5'] = 5, pp['6'] = 6, pp['7'] = 7, pp['8'] = 8, pp['9'] = 9, pp['T'] = 10, pp['J'] = 11, pp['Q'] = 12, pp['K'] = 13;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        char c, p;
        cin >> c >> p;
        a[pp[c]][pp[p]] = 1;
    }
    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= 13; j ++)
            if (a[i][j] == 0) ans ++;
    cout << ans << endl;
    return 0;
}
