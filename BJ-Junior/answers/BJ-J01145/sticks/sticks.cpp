#include <bits/stdc++.h>
using namespace std;
int t,n,a[25];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    a[2]=1,a[3]=7,a[4]=4,a[5]=2,a[6]=6,a[7]=8,a[8]=10,a[9]=18,a[10]=22,a[11]=20,a[12]=28,a[13]=68,a[14]=88;
    while(t--)
    {
        cin >> n;
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }
        int ei=n/7,qd=n%7,kl=0;

        if(n<=14)
        {
            cout << a[n] << endl;
            continue;
        }

        if(qd==1)
        {
            ei--;
            kl++;
            qd++;
        }
        else if(qd<5 and qd>2)
        {
            ei=ei-5+qd;
            kl=kl+5-qd;
            qd=5;
        }
        if(qd==2)
        {
            cout << 1;
        }
        else if(qd==5)
        {
            cout << 2;
        }
        else if(qd==6)
        {
            cout << 6;
        }
        for(int i=0;i<kl;i++)
        {
            cout << 0;
        }
        for(int i=0;i<ei;i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}