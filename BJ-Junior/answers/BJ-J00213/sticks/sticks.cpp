#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int T,n;

int main()
{
    freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n<=35)
        {
            if(n==1)cout<<-1<<"\n";
            if(n==2)cout<<1<<"\n";
            if(n==3)cout<<7<<"\n";
            if(n==4)cout<<4<<"\n";
            if(n==5)cout<<2<<"\n";
            if(n==6)cout<<6<<"\n";
            if(n==7)cout<<8<<"\n";
            if(n==8)cout<<10<<"\n";
            if(n==9)cout<<18<<"\n";
            if(n==10)cout<<22<<"\n";
            if(n==11)cout<<20<<"\n";
            if(n==12)cout<<28<<"\n";
            if(n==13)cout<<80<<"\n";
            if(n==14)cout<<88<<"\n";
            if(n==15)cout<<108<<"\n";
            if(n==16)cout<<188<<"\n";
            if(n==17)cout<<200<<"\n";
            if(n==18)cout<<208<<"\n";
            if(n==19)cout<<288<<"\n";
            if(n==20)cout<<808<<"\n";
            if(n==21)cout<<888<<"\n";
            if(n==22)cout<<1088<<"\n";
            if(n==23)cout<<1888<<"\n";
            if(n==24)cout<<2008<<"\n";
            if(n==25)cout<<2088<<"\n";
            if(n==26)cout<<2888<<"\n";
            if(n==27)cout<<8088<<"\n";
            if(n==28)cout<<8888<<"\n";
            if(n==29)cout<<10888<<"\n";
            if(n==30)cout<<18888<<"\n";
            if(n==31)cout<<20088<<"\n";
            if(n==32)cout<<20888<<"\n";
            if(n==33)cout<<28888<<"\n";
            if(n==34)cout<<80888<<"\n";
            if(n==35)cout<<88888<<"\n";

            continue;
        }
        int k=n/7;
        if(n%7!=0)k++;

        if((n-2)>7*(k-1))
        {
            if((n-5)>7*(k-1))
            {
                cout<<8;
                n-=7;
                k-=1;
            }
            else
            {
                cout<<2;
                n-=5;
                k-=1;
            }
        }
        else
        {
            cout<<1;
            n-=2;
            k-=1;
        }
        int a=n/7,b=n%7;
        if(b!=0)a++;
        for(int i=1;i<=(7-b)%7;i++)
        {
            cout<<0;
        }
        for(int i=1;i<=a-((7-b))%7;i++)
        {
            cout<<8;
        }

    }

    return 0;
}
