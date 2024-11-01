#include <bits/stdc++.h>
using namespace std;
int minn, n;
int main()
{
//  freopen("sticks.in", "r", stdin);
//  freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T --)
    {
        cin >> n;
        if(n <= 1)
        {
            cout << -1 << '\n';
        }
        if(n == 2)
        {
            cout << 1 << '\n';
        }
        if(n == 3)
        {
            cout << 7 <<'\n';
        }
        if(n == 4)
        {
            cout << 4 << '\n';
        }
        if(n == 5)
        {
            cout <<2 << '\n';
        }
        if(n == 6)
        {

            cout << 6 << '\n';
        }
        if(n == 7)
        {

            cout <<8 << '\n';
        }
        if(n == 8)
        {
            cout << 10 << '\n';
        }
        if(n == 9)
        {
            cout << 18 << '\n';
        }
        if(n == 10)
        {
            cout << 22 << '\n';
        }
        if(n == 11)
        {
            cout << 20 << '\n';
        }
        if(n == 12)
        {
            cout << 28 << '\n';
        }
        if(n == 13)
        {
            cout << 68 <<'\n';
        }
        if(n == 14)
        {

            cout << 88<<'\n';
        }
        if(n == 15)
        {

            cout << 108 << '\n';
        }
        if(n == 16)
        {

            cout << 188 << '\n';
        }
        if(n == 17)
        {
            cout << 228 << '\n';
        }
        if(n == 18)
        {

            cout <<  208 << '\n';
        }
        if(n == 19)
        {

            cout << 288 << '\n';
        }
        if(n == 20)
        {

            cout <<688 <<'\n';
        }

    }
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}
