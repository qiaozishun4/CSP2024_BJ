#include <bits/stdc++.h>
using namespace std;
int a[1010] = {-1 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6 , 8 , 4 , 7 , 7 , 6 , 7 , 8 , 5 , 9 , 8 , 11 , 7 , 10 , 10 , 9 , 10 , 11 , 8 , 12 , 11 , 11 , 7 , 10 , 10 , 9 , 10 , 11 , 8 , 12 , 11 , 10 , 6 , 9 , 9 , 8 , 9 , 10 , 7 , 11 , 10 , 11 , 7 , 10 , 10 , 9 , 10 , 11 , 8 , 12 , 11 , 12 , 8 , 11 , 11 , 10 , 11 , 12 , 9 , 13 , 12 , 9  , 5 , 8 , 8 , 7 , 8 , 9 , 6 , 10 , 9 , 13 , 9 , 12 , 12 , 11 , 12 , 13 , 10 , 14 , 13 , 12 , 8 , 11 , 11 , 10 , 11 , 12 , 9 , 13 , 14 , 10 , 13 , 13 , 12 , 13 , 14 , 11 , 15 , 10 , 6 , 9 , 9 , 8 , };
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            if(n == 0) cout << -1 << endl;
            else
            {
                for(int i = 1; i <= n / 7; i++)
                {
                    cout << 8;
                }
                cout << endl;
            }

        }
        else if(n % 7 == 1)
        {
            if(n == 1) cout << -1 << endl;
            else if(n == 8)
            {
                cout << 10 << endl;
            }
            else
            {
                cout << 108;
                for(int i = 3; i <= n / 7; i++)
                {
                    cout << 8;
                }
                cout << endl;
            }
        }
        else if(n <= 14)
        {
            int i = 1;
            while(1)
            {
                if(n == a[i])
                {
                    cout << i << endl;
                    break;
                }
                i++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
