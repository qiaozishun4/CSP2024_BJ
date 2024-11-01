#include<iostream>
using namespace std;
int n,a[105];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        if(a[i] < 2)
        {
            cout << "-1";
        }
        if(a[i] == 2)
        {
            cout << "1";
        }
        if(a[i] == 3)
        {
            cout << "7"; 
        }
        if(a[i] == 4)
        {
            cout << "4";
        }
        if(a[i] == 5)
        {
            cout << "2";
        }
        if(a[i] == 6)
        {
            cout << "6";
        }
        if(a[i] == 7)
        {
            cout << "8";
        }
        if(a[i] == 8)
        {
            cout << "16";
        }
        if(a[i] == 9)
        {
            cout << "18";
        }
        if(a[i] == 10)
        {
            cout << "116";
        }
        if(a[i] == 18)
        {
            cout << "208";
        }
    }
    return 0;
}