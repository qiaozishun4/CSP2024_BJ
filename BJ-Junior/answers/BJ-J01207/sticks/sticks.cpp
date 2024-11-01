#include<bits/stdc++.h>
using namespace std;
// 6 2 5 5 4 5 6 3 7 6
int sticks[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x,k;
    cin>>n;
    while (n--)
    {
        cin>>x;
        if (x%7==0)
        {
            k=x/7;
            while (k--) cout<<8;
            cout<<"\n";
        }
        else if (x%7==1)
        {
            k=(x-1)/7-1;
            if (k==0)
            {
                cout<<16<<"\n";
                continue;
            }
            while (k--) cout<<8;
            cout<<"07\n";
        }
    }
    return 0;
}
