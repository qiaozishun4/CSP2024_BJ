#include<bits/stdc++.h>

using namespace std;

int t;

void work()
{
    int n;
    cin>>n;
    if(n<2)
    {
        cout<<"-1\n";
        return;
    }
    if(n%7==0)
    {
        for(int i=0;i<n/7;i++)
        {
            cout<<'8';
        }
        cout<<'\n';
        return;
    }
    if(n%7==1)
    {
        cout<<"10";
        for(int i=1;i<n/7;i++)
        {
            cout<<'8';
        }
        cout<<'\n';
        return;
    }
    if(n%7==2)
    {
        cout<<"1";
        for(int i=0;i<n/7;i++)
        {
            cout<<'8';
        }
        cout<<'\n';
        return;
    }
    if(n%7==3)
    {
        if(n==3)
        {
            cout<<"7\n";
        }
        else if(n==10)
        {
            cout<<"22\n";
        }
        else
        {
            cout<<"200";
            for(int i=2;i<n/7;i++)
            {
                cout<<'8';
            }
            cout<<'\n';
        }
        return;
    }
    if(n%7==4)
    {
        if(n==4)
        {
            cout<<"4\n";
        }
        else
        {
            cout<<"20";
            for(int i=1;i<n/7;i++)
            {
                cout<<'8';
            }
            cout<<'\n';
        }
        return;
    }
    if(n%7==5)
    {
        cout<<"2";
        for(int i=0;i<n/7;i++)
        {
            cout<<'8';
        }
        cout<<'\n';
        return;
    }
    if(n%7==6)
    {
        cout<<"6";
        for(int i=0;i<n/7;i++)
        {
            cout<<'8';
        }
        cout<<'\n';
        return;
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
