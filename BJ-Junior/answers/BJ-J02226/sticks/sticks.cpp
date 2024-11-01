#include <iostream>
using namespace std;

int stick[10] = {6,2,5,5,4,5,6,3,7,6};
int number[10] = {0,1,2,3,4,5,6,7,8,9};


int w[7] = {0,6,2,5,4,3,7};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout  << -1 << endl;
            break;
        }
        if(n % 7 == 0)
        {
            for(int i = 1;i <= n / 7;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        if(n % 7 == 1)
        {
            cout << 10;
            for(int i = 1;i <= n / 7 - 1;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        if(n % 7 == 2)
        {
            cout << 1;
            for(int i = 1;i <= n / 7;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
