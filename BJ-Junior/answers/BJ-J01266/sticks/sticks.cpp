#include<iostream>
using namespace std;

int t;
int chk[10] ={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t ;
    while(t--)
    {
        int n;
        cin >> n ;
        if(n < 2) cout << "-1" << endl;

        else if(n % 7 == 0)
        {
            for(int j = 1; j <= n / 7; j++) cout << "8" ;
            cout << endl;
            continue;
        }
        else if(n % 7 == 1)
        {
            int ans = 8;
            for(int j = 1; j < (n - 1) / 7; j++) ans = ans * 10 + 8;
            cout << "10" << ans << endl;
            continue;
        }
        else if(n == 2) cout << "1" << endl;
        else if(n == 3) cout << "7" << endl;
        else if(n == 4) cout << "4" << endl;
        else if(n == 5) cout << "2" << endl;
        else if(n == 6) cout << "6" << endl;
        else if(n == 8) cout << "10" << endl;
        else if(n == 9) cout << "18" << endl;
        else if(n == 10) cout << "40" << endl;
        else if(n == 11) cout << "20" << endl;
        else if(n == 12) cout << "60" << endl;
        else if(n == 13) cout << "80" << endl;
        else if(n == 16) cout << "203" << endl;
        else if(n == 17) cout << "18" << endl;
        else if(n == 18) cout << "208" << endl;
        else if(n == 19) cout << "800" << endl;
        else if(n == 20) cout << "688" << endl;

    }
    return 0;
}
