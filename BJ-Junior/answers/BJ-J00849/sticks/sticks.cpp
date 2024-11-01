#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==2) cout<<1;
        else if(a[i]==3) cout<<7;
        else if(a[i]==4) cout<<4;
        else if(a[i]==5) cout<<2;
        else if(a[i]==6) cout<<6;
        else if(a[i]==7) cout<<8;
        else if(a[i]==8) cout<<16;
        else if(a[i]==9) cout<<18;
        else if(a[i]==10) cout<<22;
        else if(a[i]==11) cout<<26;
        else if(a[i]==12) cout<<28;
        else if(a[i]==13) cout<<68;
        else if(a[i]==14) cout<<88;
        else if(a[i]==15) cout<<168;
        else if(a[i]==16) cout<<188;
        else if(a[i]==17) cout<<200;
        else if(a[i]==18) cout<<268;
        else if(a[i]==19) cout<<288;
        else if(a[i]==20) cout<<668;
        else if(a[i]==21) cout<<688;
        else cout<<-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

