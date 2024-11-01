#include <iostream>
#include <cmath>
#include <random>
#include <string>
using namespace std;
int a[100005];
int two = 0,one = 0,z = 0,n;
int small[100005],big,sheng = 0;
void special(int k)
{
    if(k == 1)
    {
        one++;
    }
    else two++;
}
int common()
{
    small[0] = 0;
    for(int q = 1;q<100005;q++)
    {
        for(int p = 0;p < n;p++)
        {
            if(a[p]<=q)
            {
                z++;
            }
            small[q] = z;
        }
            if(z == 0)
            {
                small[q] = small[q-1];
            }
            else
            {
                big = small[q] - small[q-1];
                if(big >= sheng)
                {
                    sheng = big;
                }
                z = 0;
            }
    }
    return sheng;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int c = 0;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
        if ((a[i]==2)||(a[i]==1))
        {
            c++;
        }
    }
    if(c==n)
    {
        for(int j = 0;j<n;j++)
        {
            special(a[j]);
        }
        if(two >= one)
        {
            cout<<two<<endl;
        }
        else
        {
            cout<<one-two<<endl;
        }
    }
    else{
         cout<<common()<<endl;
    }
    return 0;
}
