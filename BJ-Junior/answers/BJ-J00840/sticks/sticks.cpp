#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,i;
    string s="";
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<7)
        {
            if(n==0||n==1)cout<<"-1";
            else if(n==2)cout<<"1";
            else if(n==3)cout<<"7";
            else if(n==4)cout<<"4";
            else if(n==5)cout<<"2";
            else if(n==6)cout<<"6";
            cout<<endl;
        }
        else if(n%7==0)
        {
            s="";
            for(i=1;i<=n/7;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==1)
        {
            s="10";
            for(i=1;i<=n/7-1;i++)
            {
                 s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==2)
        {
            s="1";
            for(i=1;i<=n/7;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==3)
        {
            s="22";
            for(i=1;i<=n/7-1;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==4)
        {
            s="20";
            for(i=1;i<=n/7-1;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==5)
        {
            s="2";
            for(i=1;i<=n/7;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else if(n%7==6)
        {
            s="6";
            for(i=1;i<=n/7;i++)
            {
                s+='8';
            }
            cout<<s<<endl;
        }
        else
        {
            cout<<100;
        }
    }
    return 0;
}
