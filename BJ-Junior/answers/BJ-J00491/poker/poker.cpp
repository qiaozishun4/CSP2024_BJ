#include <iostream>
using namespace std;

int d[15],c[15],h[15],s[15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
       char a,b;
       cin >> a>>b;
       int x=0;
       switch(b)
       {
           case 'A':x=1;break;
           case '2':x=2;break;
           case '3':x=3;break;
           case '4':x=4;break;
           case '5':x=5;break;
           case '6':x=6;break;
           case '7':x=7;break;
           case '8':x=8;break;
           case '9':x=9;break;
           case 'T':x=10;break;
           case 'J':x=11;break;
           case 'Q':x=12;break;
           case 'K':x=13;break;
       }
       if(a=='D')d[x]++;
       if(a=='C')c[x]++;
       if(a=='H')h[x]++;
       if(a=='S')s[x]++;
    }

    int ans = 0;

    for(int i =1 ;i<= 13;i++)
    {
        if(d[i]==0)ans++;
        if(c[i]==0)ans++;
        if(h[i]==0)ans++;
        if(s[i]==0)ans++;
    }
    cout << ans;
    return 0;
}
