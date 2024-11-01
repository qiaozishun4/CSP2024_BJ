#include<bits/stdc++.h>
using namespace std;
int a[60];
int tz[10]={6,2,5,5,4,5,6,3,7,6};
long long ans[100010]={-1,-1,1,7,4,2,6,8,10,18,24,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cout<<-1<<endl;
        }
        else if(a[i]<30)
        {
            cout<<ans[a[i]]<<endl;
        }
        else
        {
            int c,s,y;
            c=a[i]-14;
            s=c/7;
            y=c%7;
            cout<<ans[14+y];
            for(int k=0;k<s;k++)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    /*for(int i=50;i<=100000;i++)
    {
        ans[i]=ans[i-7]*10+8;
        cout<<ans[i]<<",";
    }*/
    return 0;
}

