#include <iostream>
using namespace std;
int t,n;
int lo(int x)
{
    int sum = 0,xx = x;
    while(xx > 0)
    {
        sum++;
        xx/=10;
    }
    return sum;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i= 1;i <= t;i++)
    {
        cin >>n;
        int s = lo(n);
        if(n == 6)
        {
            cout << 14<<endl;
        }
        if(n % 7 == 0)
        {
            for(int i = 1;i <= s;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n % 5 == 0)
        {
            for(int i = 1;i <= s;i++)
            {

                cout << 2;
            }
            cout << endl;
        }
        else
        {
            cout << -1<<endl;
        }
    }
    return 0;
}
