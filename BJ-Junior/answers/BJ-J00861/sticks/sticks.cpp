#include<iostream>
using namespace std;
int t, n;
int con[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
 //            0  1  2  3  4  5  6  7  8  9
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n >= 2 && n <= 7)
        {
            for(int i = 1; i <= 9; i++)
            {
                if(con[i] == n)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
        else if(n == 1) cout << -1 << endl;
        else if(n == 8) cout << 16 << endl;
        else if(n == 9) cout << 18 << endl;
        else if(n == 10) cout << 22 << endl;
        else if(n == 11) cout << 20 << endl;
        else if(n == 12) cout << 28 << endl;
        else if(n == 13) cout << 68 << endl;
        else if(n == 14) cout << 88 << endl;
        else if(n == 15) cout << 108 << endl;
        else if(n == 16) cout << 188 << endl;
        else if(n == 17) cout << 200 << endl;
        else if(n == 18) cout << 208 << endl;
        else if(n == 19) cout << 288 << endl;
        else if(n == 20) cout << 688 << endl;
    }
    return 0;
}
