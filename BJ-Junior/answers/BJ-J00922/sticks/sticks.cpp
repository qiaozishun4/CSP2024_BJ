#include<bits/stdc++.h>
using namespace std;
int a[51]={0,-1,1,7,4,2,6,8,10,18,23,26,28,68,88,108,188,200,208,288,688,888,1088,1888,2088,2888,6088,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888},t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n<=50)
        {
            cout<<a[n]<<endl;
        }
        else if(n%7==0)
        {
            int h=n/7;
            while(h--)
            {
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
4
DQ
H3
DQ
DT
*/

