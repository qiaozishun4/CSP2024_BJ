#include <iostream>
#include <string>
using namespace std;
int st[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T --){
        int n, t;
        cin >> n;
        string ans = "";
        t = n;
        if (n % 7 == 0){
            for (int i = 1; i <= n / 7; i ++)
                cout << "8";
            cout << "\n";
            continue;
        }
        while (t > 14)
            ans = "8" + ans, t -= 7;
        for (int i = 0; i <= 9; i ++)
            for (int j = 0; j <= 9; j ++){
                if (st[j] == t && i == 0 && !(ans == "" && j == 0)) {
                    t = 0;
                    ans = (char)(j + '0') + ans;
                }
                if (st[i] + st[j] == t && i != 0) {
                    t = 0;
                    ans = (char)(j + '0') + ans;
                    ans = (char)(i + '0') + ans;
                }
            }
        if (t == 0)
            cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
