#include <iostream>
using namespace std;

int a[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void sticks()
{
    int n;
    cin >> n;
    string s = "";
    if (n < 2)
    {
        s = "-1";
    }
    if (n == 6) 
    {
        s = "0";
    }
    s = "1";
    n -= 2;
    for (int i = 0; i <= 9; i++)
    {
        while (n >= a[i])
        {
            s += char(i + '0');
        }
    }
    cout << s << endl;
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        sticks();
    }
    return 0;
}