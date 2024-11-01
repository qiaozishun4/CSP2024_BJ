#include<bits/stdc++.h>
using namespace std;
int a[100007];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(a[i]==3)
        {
            cout<<"7"<<endl;
            continue;
        }
        if(a[i]==4)
        {
            cout<<"4"<<endl;
            continue;
        }
        if(a[i]%7==0)
            for(int j=1;j<=a[i]/7;j++)
                cout<<"8";
        if(a[i]%7==1)
        {
            cout<<"10";
            for(int j=2;j<=a[i]/7;j++)
                cout<<"8";
        }
        if(a[i]%7==2)
        {
            cout<<"1";
            for(int j=1;j<=a[i]/7;j++)
                cout<<"8";
        }
        if(a[i]%7==3)
        {
            cout<<"22";
            for(int j=2;j<=a[i]/7;j++)
                cout<<"8";
        }
        if(a[i]%7==4)
        {
            cout<<"20";
            for(int j=2;j<=a[i]/7;j++)
                cout<<"8";
        }
        if(a[i]%7==5)
        {
            cout<<"2";
            for(int j=1;j<=a[i]/7;j++)
                cout<<"8";
        }
        if(a[i]%7==6)
        {
            cout<<"6";
            for(int j=1;j<=a[i]/7;j++)
                cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}
