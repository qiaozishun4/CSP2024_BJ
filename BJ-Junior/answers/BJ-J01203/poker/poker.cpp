#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int arr[53];
int ch(string x)
{
    int p=0;
    if(x[0]=='D')
    {
        p=p+13;
    }
    if(x[0]=='H')
    {
        p=p+26;
    }
    if(x[0]=='S')
    {
        p=p+39;
    }

    if(x[1]=='T')
    {
        p=p+10;
        return p;

    }
    if(x[1]=='J')
    {
        p=p+11;
        return p;

    }
    if(x[1]=='Q')
    {
        p=p+12;
        return p;

    }
    if(x[1]=='K')
    {
        p=p+13;
        return p;

    }
    p=p+x[1]-48;
    return p;
}
int cou()
{
    int ans=0;
    for(int i=1;i<=52;i++)
    {
        if(arr[i]==0)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string d[n];
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
    }
    for(int i=0;i<n;i++)
    {
        int p=ch(d[i]);
        arr[p]=1;
    }
    int ans=cou();
    cout<<ans;
    return 0;
}

