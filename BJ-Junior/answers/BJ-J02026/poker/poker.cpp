#include<bits/stdc++.h>
using namespace std;
int a[53]={0};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    string m;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        if(m[0]=='D')
        {
            if(m[1]>='2')
            {
                if(m[1]<='9')a[m[1]-'0']=1;
                else
                {
                    if(m[1]=='T')a[10]=1;
                    if(m[1]=='J')a[11]=1;
                    if(m[1]=='Q')a[12]=1;
                    if(m[1]=='K')a[13]=1;
                }
            }
            else
            {
                a[1]=1;
            }
        }
        if(m[0]=='H')
        {
            if(m[1]>='2')
            {
                if(m[1]<='9')a[m[1]-'0'+13*2]=1;
                else
                {
                    if(m[1]=='T')a[10+13*2]=1;
                    if(m[1]=='J')a[11+13*2]=1;
                    if(m[1]=='Q')a[12+13*2]=1;
                    if(m[1]=='K')a[13+13*2]=1;
                }
            }
            else
            {
                a[1+26]=1;
            }
        }
        if(m[0]=='C')
        {
            if(m[1]>='2')
            {
                if(m[1]<='9')a[m[1]-'0'+13]=1;
                else
                {
                    if(m[1]=='T')a[10+13]=1;
                    if(m[1]=='J')a[11+13]=1;
                    if(m[1]=='Q')a[12+13]=1;
                    if(m[1]=='K')a[13+13]=1;
                }
            }
            else
            {
                a[1+13]=1;
            }
        }
        if(m[0]=='S')
        {
            if(m[1]>='2')
            {
                if(m[1]<='9')a[m[1]-'0'+13*3]=1;
                else
                {
                    if(m[1]=='T')a[10+39]=1;
                    if(m[1]=='J')a[11+39]=1;
                    if(m[1]=='Q')a[12+39]=1;
                    if(m[1]=='K')a[13+39]=1;
                }
            }
            else
            {
                a[1+39]=1;
            }
        }
    }
    int b=52;
    for(int i=1;i<=52;i++)b-=a[i];
    cout<<b;
    return 0;
}
