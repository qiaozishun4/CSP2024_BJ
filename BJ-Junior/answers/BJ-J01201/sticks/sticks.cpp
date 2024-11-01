#include<bits/stdc++.h>
using namespace std;
int f[10]={10,-1,1,7,4,2,0,8,-1,-1};
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }else if(n%7==6)
        {
            if(n>7){
                cout<<80;
                for(int i=1;i<=n/7-1;i++)
                {
                    cout<<8;
                }
            }else if(n<7)
            {
                cout<<6;
            }
        }else if(n%7==1&&n>7)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
        }else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }else if(n%7==3)
        {
            if(n<7){
                cout<<7;
            }else if(n>7){
                cout<<22;
                for(int i=1;i<=n/7-1;i++)
                {
                    cout<<8;
                }
            }
        }else if(n%7==4){
            if(n<7){
                cout<<4;
            }else if(n>7){
                cout<<20;
                for(int i=1;i<=n/7-1;i++)
                {
                    cout<<8;
                }
            }
        }else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }

        }else{
            cout<<-1;
        }
        cout<<"\n";
    }
    return 0;
}
