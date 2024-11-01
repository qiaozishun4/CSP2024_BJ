#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int x,m,pd;
        cin>>x;
        m=x/7;
        pd=x%7;
        if(x<2)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(x<8)
        {
            if(x==2) cout<<"1";
            else if(x==3) cout<<"7";
            else if(x==4) cout<<"4";
            else if(x==5) cout<<"2";
            else if(x==6) cout<<"6";
            else if(x==7) cout<<"8";
        }
        else if(pd==0) for(int i=1;i<=m;i++) cout<<"8";
        else if(pd==1)
        {
            cout<<"10";
            for(int i=1;i<=m-1;i++) cout<<"8";
        }
        else if(pd==2)
        {
            cout<<"1";
            for(int i=1;i<=m;i++) cout<<"8";
        }
        else if(pd==3)
        {
            cout<<"22";
            for(int i=1;i<=m-1;i++) cout<<"8";
        }
        else if(pd==4)
        {
            cout<<"20";
            for(int i=1;i<=m-1;i++) cout<<"8";
        }
        else if(pd==5)
        {
            cout<<"2";
            for(int i=1;i<=m;i++) cout<<"8";
        }
        else if(pd==6)
        {
            cout<<"6";
            for(int i=1;i<=m;i++) cout<<"8";
        }
        cout<<endl;
    }
}
