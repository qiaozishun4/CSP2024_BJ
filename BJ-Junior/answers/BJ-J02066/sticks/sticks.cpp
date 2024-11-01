#include<iostream>
#include<cstdio>
using namespace std;
int T,n,sz[]={0,-1,1,7,4,2,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n<7)
        {
            cout<<sz[n]<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
                cout<<"8";
        }
        else if(n%7==1)
        {
            cout<<"10";
            for(int i=1;i<=n/7-1;i++)
                cout<<"8";
        }
        else if(n%7==2)
        {
            cout<<"1";
            for(int i=1;i<=n/7;i++)
                cout<<"8";
        }
        else if(n%7==3)
        {
            if(n==10) cout<<"22";
            else
            {
                cout<<"200";
                for(int i=1;i<=n/7-2;i++)
                    cout<<"8";
            }
        }
        else if(n%7==4)
        {
            cout<<"20";
            for(int i=1;i<=n/7-1;i++)
                cout<<"8";
        }
        else if(n%7==5)
        {
            cout<<"2";
            for(int i=1;i<=n/7;i++)
                cout<<"8";

        }
        else if(n%7==6)
        {
            cout<<"6";
            for(int i=1;i<=n/7;i++)
                cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}
