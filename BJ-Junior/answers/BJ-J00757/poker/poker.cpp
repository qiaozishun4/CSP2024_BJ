#include <iostream>
#include <string>

using namespace std;

bool pokers[53];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, t = 0, ans = 0;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp[1] == 'T')
        {
            t = 10;
        }
        else if (temp[1] == 'J')
        {
            t = 11;
        }
        else if (temp[1] == 'Q')
        {
            t = 12;
        }
        else if (temp[1] == 'K')
        {
            t = 13;
        }
        else if (temp[1] == 'A')
        {
            t = 1;
        }
        else
        {
            t = temp[1] - '0';
        }
        if (temp[0] == 'D')
        {
            pokers[t] = true;
        }
        else if (temp[0] == 'C')
        {
            pokers[t + 13] = true;
        }
        else if (temp[0] == 'H')
        {
            pokers[t + 26] = true;
        }
        else
        {
            pokers[t + 39] = true;
        }
    }
    for (int i = 1; i <= 52; i++)
    {
        if (!pokers[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
