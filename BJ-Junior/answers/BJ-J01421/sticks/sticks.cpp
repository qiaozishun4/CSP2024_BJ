#include <bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int a[21];
    a[0]=-1;
    a[1]=-1;
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=6;
    a[7]=8;
    a[8]=10;
    a[9]=18;
    a[10]=22;
    a[11]=20;
    a[12]=28;
    a[13]=68;
    a[14]=88;
    a[15]=108;
    a[16]=188;
    a[17]=200;
    a[18]=208;
    a[19]=288;
    a[20]=688;

    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        cin>>n;
        if(n%7==0&&n>20)
        {
            int w=n/7;
            for(int i=0;i<w;i++){cout<<8;}
            cout<<endl;
        }
        else if(n%7==1&&n>20)
        {
            cout<<10;
            int w=n/7-1;
            for(int i=0;i<w;i++){cout<<8;}
        }
        else if(n<=20)
        {
            cout<<a[n]<<endl;
        }
        else{cout<<-1<<endl;}

    }
    return 0;
}