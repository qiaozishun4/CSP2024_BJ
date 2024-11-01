#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b[100000]={0},a1=0,a2=0,a3=0,b1=0,c[100000]={0};

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
        if(b[i]==1)
            a1++;
        else if(b[i]==2)
            a2++;
        else
            a3=1;
        c[b[i]]++;
    }
    if(a3==0)
    {
        cout<<abs(a1-a2);
        return 0;
    }
    sort(b,b+a);
    for(int i=0;i<a-1;i++)
    {
        if(b[i]==b[i+1])
        {
            b1++;
            b[i]=0;
        }

    }

    cout<<a%2;
    return 0;
    

    return 0;
}
