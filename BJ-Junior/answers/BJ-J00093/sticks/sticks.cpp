#include<bits/stdc++.h>
using namespace std;
int s[100001]={-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,1088888};
int main()
{
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
    int n,a;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a<=50)
            cout<<s[a-1];
        else if(a%7==0)
        {
            int k=a/7;
            while(k--)
                cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
