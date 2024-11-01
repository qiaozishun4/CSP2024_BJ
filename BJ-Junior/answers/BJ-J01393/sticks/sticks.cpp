#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
ll cnt=14;
string ans[N]={"0","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
int main()
{
    for(int i=1;i<=1000;i++)
    {
        string x="",y="";
        for(int k=1;k<=i;k++)
        {
            x.push_back('8');
        }
        for(int k=1;k<i;k++)
        {
            y.push_back('8');
        }
        ans[++cnt]="10"+x;
        ans[++cnt]="18"+x;
        ans[++cnt]="200"+y;
        ans[++cnt]="20"+x;
        ans[++cnt]="28"+x;
        ans[++cnt]="68"+x;
        ans[++cnt]="88"+x;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n>14)
        {
            if(n%7==0)
            {
                for(int i=1;i<=n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==1)
            {
                cout<<10;
                for(int i=1;i<n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==2)
            {
                cout<<18;
                for(int i=1;i<n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==3)
            {
                cout<<200;
                for(int i=2;i<n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==4)
            {
                cout<<20;
                for(int i=1;i<n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==5)
            {
                cout<<28;
                for(int i=1;i<n/7;i++)
                {
                    cout<<8;
                }
            }
            else if(n%7==6)
            {
                cout<<68;
                for(int i=1;i<n/7;i++)
                {
                    cout<<8;
                }
            }
        }
        else
        {
            cout<<ans[n]<<endl;
        }
    }
}
