#include <bits/stdc++.h>

using namespace std;

int main ()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n < 2){
            cout << "-1" << endl;
            continue;
        }

        if(n % 7 == 0)
        {
            for(int i = 1;i<= n / 7 ; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        if(n % 7 == 1)
        {
            cout << "10";
            for(int i = 1;i<=n / 7 - 1;i++)
                cout << '8';
            cout << endl;
            continue;
        }
    }
    return 0;
}
