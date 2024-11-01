#include<bits/stdc++.h>
using namespace std;
int a[]={0,0,1,7,4,2,0,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        if(k<2)
        {
            cout<<-1;
            
        }
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            
        }
        else
        {
            cout<<1;
            n-=2;
            if(n%6!=1)
            {
                for(int i=1;i<=n/6;i++) cout<<0;
                
                if(n%6!=0) cout<<a[n%6];
            }
        }
        cout<<endl;
    }


}
