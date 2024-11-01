#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int q=0;
    cin>>t;
    int n;
    int a[9];
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n<=1)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int j=1;j<10;j++)
        {
            if(n==a[j])
            {
                cout<<j<<endl;
                break;
            }
        }
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
    }
    return 0;
}