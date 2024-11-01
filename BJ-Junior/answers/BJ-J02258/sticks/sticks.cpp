#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[100005];


int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        if (n == 1)
        {
            cout <<"-1" <<endl;
            continue;
        }
        if (n < 7)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (n == num[i])
                {
                    cout << i << endl;
                    break;
                }
            }
            continue;
        }
        if (n % 7 == 0)
        {
            while (n > 0)
            {
                cout <<"8";
                n %= 7;
            }
        }
        if (n % 7 == 1)
        {
            cout << 
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (n == num[i])
                {
                    cout << i;
                    break;
                }
            }
            while (n > 0)
            {
                for (int i = 9; i >= 0; i--)
                {
                    if (n == num[i])
                    {
                        cout << i;
                        break;
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
