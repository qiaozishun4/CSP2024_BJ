#include <bits/stdc++.h>
using namespace std;
int T,n,num_of_8 = 0;
string st = "0";
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while (T--)
    {
        num_of_8 = 0;
        st = "0";
        cin >> n;
        if (n < 2)
        {
            cout << -1;
            continue;
        }
        while (n < 7)
        {
            n -= 7;
            num_of_8++;
        }
        if (n == 1)
        {
            st += "10";
            num_of_8--;
        }
        else if (n == 2)
        {
            st += "1";
        }
        else if (n == 3)
        {
            if (num_of_8)
            {
                st += "40";
                num_of_8--;
            }
            else
            {
                st += "7";
            }
        }
        else if (n == 4)
        {
            if (num_of_8)
            {
                st += "20";
                num_of_8--;
            }
            else
            {
                st += "4";
            }
        }
        else if (n == 5)
        {
            st += "2";
        }
        else if (n == 6)
        {
            st += "6";
        }
        for (int i = 1;i < st.size();i++)
        {
            cout << st[i];
        }
        for (int i = 1;i <= num_of_8;i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
