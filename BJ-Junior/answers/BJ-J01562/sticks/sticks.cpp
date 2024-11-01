#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("sticks.in","r",stdin);
    freopen ("sticks.out","w",stdout);
    long long T,n;
    int jieguo;
    int x;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        jieguo=0;
        cin>>n;
        x=(n-1)/7-1;
        if(n==1)
            jieguo=-1;
        else if(n==2)
            jieguo=1;
        else if(n==3)
            jieguo=7;
        else if(n==4)
            jieguo=4;
        else if(n==5)
            jieguo=2;
        else if(n==6)
            jieguo=6;
        else if(n==7)
            jieguo=8;
        else if(n%7==1)
            jieguo=10;
        else if(n%7==2)
            jieguo=18;
        else if(n%7==3)
            jieguo=22;
        else if(n%7==4)
            jieguo=20;
        else if(n%7==5)
            jieguo=28;
        else if(n%7==6)
            jieguo=80;
        else if(n%7==0)
            jieguo=88;
        cout<<jieguo;
        if(x!=0)
        {
            for(int j=0;j<x;j++)
            {
                cout<<8;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
