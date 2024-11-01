#include<bits/stdc++.h>
using namespace std;
void s(int n)
{
    if(n=0)
    {
        return ;
    }
    if(n=1)
    {
        cout<<-1;
        return ;
    }
    if(i!=0)
    {
        if(n>43||n==42)
        {
            cout<<888888;
            s[n-42];
        }
        if((n>7&&n<42)||n==6)
        {
            cout<<0;
            s[n-6];
        }
        if(n=7) cout<<8;
        if(n=5) cout<<2;
        if(n=4) cout<<4;
        if(n=3) cout<<7;
        if(n=2) cout<<1;
        return ;
    }
    else
    {
        if(n>43||n==42)
        {
            cout<<888888;
            i++;
            s[n-42];
        }
        if((n>31&&n<42)||(n==30))
        {
            cout<<60000;
            i++;
            s[n-30];
        }
        else
        {
            cout<<2;
            i++;
            s[n-5];
        }
    }
}
int main()
{
    freopen("explore","r",stdin);
    freopen("explore","w",stdout);
    int n;
    int i=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s[a];
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}