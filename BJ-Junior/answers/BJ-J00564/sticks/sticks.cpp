#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int n;
    cin >> n;
    int t;
    while(n--)
    {
        cin >> t;
        if(t == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(t % 7 == 1)
        {
            cout << 10;
            t -= 8;
        }
        else if(t % 7 == 2)
        {
            cout << 1;
            t -= 2;
        }
        else if(t % 7 == 3)
        {
            if(t >= 17)
            {
                cout << 200;
                t -= 17;
            }
            else if(t == 3)
            {
                cout << 7 << endl;
                continue;
            }
            else
            {
                cout << 78 << endl;
                continue;
            }
        }
        else if(t % 7 == 4)
        {
            if(t >= 11)
            {
                cout << 20;
                t -= 11;
            }
            else
            {
                cout << 4 << endl;
                continue;
            }
        }
        else if(t % 7 == 5)
        {
            cout << 2;
            t -= 5;
        }
        else if(t % 7 == 6)
        {
            cout << 6;
            t -= 6;
        }
        int s = t / 7;
        if(s < 0)
        {
            s = 0;
        }
        while(s--)
        {
            cout << 8;
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
