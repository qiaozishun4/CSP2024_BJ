#include<bits/stdc++.h>
using namespace std;
string p[10]={"-1","-1","1","7","4","2","6","7","-1","-1"};
int n;
string s;
int t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=7)
            cout<<p[n]<<endl;
        else
        {
            if(n%7==0)
            {
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==1)
            {
                cout<<"10";
                n-=8;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==2)
            {
                cout<<1;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==3)
            {
                cout<<200;
                n-=17;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==4)
            {
                cout<<20;
                n-=11;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==5)
            {
                cout<<2;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(n%7==6)
            {
                cout<<6;
                for(int i=1;i<=n/7;i++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
