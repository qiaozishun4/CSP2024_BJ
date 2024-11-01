#include <iostream>
#include <cmath>
#include <random>
#include <string>
using namespace std;
int t;
int w[1000005][1000005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    int n[t];
    for(int i = 0;i<t;i++)
    {
        cin>> n[i];
        for(int j = 0;j<n[t];j++)
        {
            cin >> w[i][j];

        }

    }
    return 0;
}
