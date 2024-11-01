#include<iostream>
using namespace std;
int n,m,g,sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    sum = 52;
    for (int i = 1;i <= n;i++)
    {
        cin >> m;
        if(m == 'S')
        {
            cin >> g;
            
        }
        if(m == 'D')
        {
            cin >> g;

        }
    }
    cout << sum-n;
    return 0;
}