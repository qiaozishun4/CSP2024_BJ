
#include <bits/stdc++.h>
using namespace std;
string biao[] = {"", "-1","1","7","4","2","6","8"
"10","18","22","20","28","68","88"
"108","188","200","208","288","688","888"
"1088","1888","2008","2088","2888","6888","8888"
"10888","18888","20088","20888","28888","68888","88888"
"108888","188888","200888","208888","288888","688888","888888"
"1088888","1888888","2008888","2088888","2888888","6888888","8888888"
"10888888","18888888","20088888","20888888","28888888","68888888","88888888"
"108888888","188888888","200888888","208888888"};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n <= 50) cout << biao[n] << endl;
        else {
            if (n % 7 == 1) {
                cout << "10";
                for (int i = 1; i <= n / 7 - 1; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 2) {
                cout << "18";
                for (int i = 1; i <= n / 7 - 1; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 3) {
                cout << "200";
                for (int i = 1; i <= n / 7 - 2; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 4) {
                cout << "20";
                for (int i = 1; i <= n / 7 - 1; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 5) {
                cout << "2";
                for (int i = 1; i <= n / 7; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 6) {
                cout << "6";
                for (int i = 1; i <= n / 7; ++i) putchar('8');
                putchar('\n');
            }
            if (n % 7 == 0) {
                for (int i = 1; i <= n / 7; ++i) putchar('8');
                putchar('\n');
            }
        }
    }
    return 0;
}

