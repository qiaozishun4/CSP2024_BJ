#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        if(n<=21)
        {
            if(n==1) cout<<-1<<endl;
            if(n==2) cout<<1<<endl;
            if(n==3) cout<<7<<endl;
            if(n==4) cout<<4<<endl;
            if(n==5) cout<<2<<endl;
            if(n==6) cout<<6<<endl;
            if(n==7) cout<<8<<endl;
            if(n==8) cout<<10<<endl;
            if(n==9) cout<<18<<endl;
            if(n==10) cout<<22<<endl;
            if(n==11) cout<<20<<endl;
            if(n==12) cout<<28<<endl;
            if(n==13) cout<<68<<endl;
            if(n==14) cout<<88<<endl;
            if(n==15) cout<<108<<endl;
            if(n==16) cout<<188<<endl;
            if(n==17) cout<<200<<endl;
            if(n==18) cout<<208<<endl;
            if(n==19) cout<<288<<endl;
            if(n==20) cout<<688<<endl;
            if(n==21) cout<<888<<endl;
        }
        else
        {
            long long k=n/7-2;
            long long x=n-k*7;
            if(x==12) cout<<28;
            if(x==13) cout<<68;
            if(x==14) cout<<88;
            if(x==15) cout<<108;
            if(x==16) cout<<188;
            if(x==17) cout<<200;
            if(x==18) cout<<208;
            if(x==19) cout<<288;
            if(x==20) cout<<688;
            if(x==21) cout<<888;
            for(long long i=1;i<=k;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
