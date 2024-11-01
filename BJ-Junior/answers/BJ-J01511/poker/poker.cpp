#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,s=52,c[60];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a[2];
        cin>>a;
        if(a[1]=='H')c[i]=1;
        else if(a[1]=='S')c[i]=2;
        else if(a[1]=='C')c[i]=3;
        else if(a[1]=='D')c[i]=4;
        if(a[2]=='A')c[i]=c[i]*10+1;
        else if(a[2]=='2')c[i]=c[i]*10+2;
        else if(a[2]=='3')c[i]=c[i]*10+3;
        else if(a[2]=='4')c[i]=c[i]*10+4;
        else if(a[2]=='5')c[i]=c[i]*10+5;
        else if(a[2]=='6')c[i]=c[i]*10+6;
        else if(a[2]=='7')c[i]=c[i]*10+7;
        else if(a[2]=='8')c[i]=c[i]*10+8;
        else if(a[2]=='9')c[i]=c[i]*10+9;
        else if(a[2]=='T')c[i]=c[i]*10+10;
        else if(a[2]=='J')c[i]=c[i]*10+11;
        else if(a[2]=='Q')c[i]=c[i]*10+12;
        else if(a[2]=='K')c[i]=c[i]*10+13;
        s--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)continue;
            if(c[i]==c[j])
            {
                s++;
                continue;
            }
        }
    }
    if(s>52)s=0;
    cout<<s;
    return 0;
}
