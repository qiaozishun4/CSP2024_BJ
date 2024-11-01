#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long mg[] = {6,2,5,5,4,5,6,3,7,6};
void teshu1(long long n)
{
    long long i;
    for (i = 1;1;i++)
    {
        long long j = i,sum = 0;
        while (j)
        {
            sum += mg[j%10];
            j /= 10;
        }
        if (sum == n) break;
    }
    cout << i << "\n";
}
void teshu2(long long n)
{
    for (long long i = 1;i <= n / 7;i++) cout << 8;
    cout << "\n";
}
void teshu3(long long n)
{
    cout << "10";
    for (long long i = 1;i < n / 7;i++) cout << 8;
    cout << "\n";
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        if (n <= 1)
        {
            cout << "-1\n";
        }
        else if (n <= 50)
        {
            teshu1(n);
        }
        else if (n % 7 == 0 && n >= 7)
        {
            teshu2(n);
        }
        else if (n % 7 == 1 && n >= 15)
        {
            teshu3(n);
        }
        else
        {
            teshu1(n);
        }
    }
    return 0;
}
