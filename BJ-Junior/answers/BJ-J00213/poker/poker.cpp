#include<bits/stdc++.h>
using namespace std;

char s[2];
int a[60];
int n,ans;


int main()
{
    freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[0]>>s[1];
        int k;
        if(s[0]=='C')k+=13;
        if(s[0]=='H')k+=26;
        if(s[0]=='S')k+=39;

        if(s[1]=='A')k+=1;
        if(s[1]=='2')k+=2;
        if(s[1]=='3')k+=3;
        if(s[1]=='4')k+=4;
        if(s[1]=='5')k+=5;
        if(s[1]=='6')k+=6;
        if(s[1]=='7')k+=7;
        if(s[1]=='8')k+=8;
        if(s[1]=='9')k+=9;
        if(s[1]=='T')k+=10;
        if(s[1]=='J')k+=11;
        if(s[1]=='Q')k+=12;
        if(s[1]=='K')k+=13;
        a[k]=1;
        k=0;
    }
    for(int i=1;i<=52;i++)
    {
        if(a[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}