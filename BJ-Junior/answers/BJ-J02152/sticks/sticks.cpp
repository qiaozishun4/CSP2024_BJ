#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T,n;

    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        if(n<=1) cout <<-1;
        else if(n==2) cout <<1;
        else if(n==3) cout <<7;
        else if(n==4) cout <<4;
        else if(n==5) cout <<2;
        else if(n==6) cout <<6;
        else if(n==8) cout <<10;
        else if(n==9) cout <<18;
        else if(n==10) cout <<40;
        else if(n==11) cout <<20;
        else if(n==12) cout <<60;
        else if(n==13) cout <<80;
        else if(n==15) cout <<108;
        else if(n==16) cout <<202;
        else if(n==17) cout <<200;
        else if(n==18) cout <<208;
        else if(n==19) cout <<800;
        else if(n==20) cout <<808;
        else if(n%7==0)
            for(int j=1;j<=n/7;j++)
                cout <<8;
        else if(n%7==1)
        {
            cout <<"10";
            for(int j=1;j<=n/7-1;j++)
                cout <<8;
        }
    }

    return 0;
}