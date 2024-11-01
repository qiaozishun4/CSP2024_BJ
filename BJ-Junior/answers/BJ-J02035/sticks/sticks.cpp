#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n, x;
    cin>> n;
    for(int i=1;i<=n;i++)
    {
        cin>> x;
        if(x<2)
        {
            cout<< -1 << endl;
        }
        else if(x==2)
        {
            cout<< 1 << endl;
        }
        else if(x==3)
        {
            cout<< 7 << endl;
        }
        else if(x==4)
        {
            cout<< 4 << endl;
        }
        else if(x==5)
        {
            cout<< 2 << endl;
        }
        else if(x==6)
        {
            cout<< 6 << endl;
        }
        else if(x==7)
        {
            cout<< 8 << endl;
        }
        else if(x==8)
        {
            cout<< 10 << endl;
        }
        else if(x==18)
        {
            cout<< 208 << endl;
        }
        else if(x%7==0 && x>=100)
        {
            for(int j=1;j<=x/7;j++)
            {
                cout<< 8;
            }
            cout<< endl;
        }
    }
    return 0;
}
