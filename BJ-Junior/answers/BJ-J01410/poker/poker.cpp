#include<iostream>
#include<string>
using namespace std;
freopen(poker.in,"r",stdin);
freopen(poker.out,"w",stdout);
int main()
{
    int a,cnt=0;
    int l[54];
    char n[3][55];
    cin>>a;
    for(int i=0;i<a;i++)
    {
        string t;
        cin>>t;
        n[0][i]=t[0];
        n[1][i]=t[1];
    }
    for(int i=0;i<a;i++)
    {
        int r;
        if(n[0][i]='C') r+=13;
        if(n[0][i]='H') r+=26;
        if(n[0][i]='S') r+=39;

        if(n[1][i]='A') r+=1;
        if(n[1][i]='2') r+=2;
        if(n[1][i]='3') r+=3;
        if(n[1][i]='4') r+=4;
        if(n[1][i]='5') r+=5;
        if(n[1][i]='6') r+=6;
        if(n[1][i]='7') r+=7;
        if(n[1][i]='8') r+=8;
        if(n[1][i]='9') r+=9;
        if(n[1][i]='T') r+=10;
        if(n[1][i]='J') r+=11;
        if(n[1][i]='Q') r+=12;
        if(n[1][i]='K') r+=13;

        l[r]=1;
    }
    for(int i=0;i<53;i++)
    {
        if(l[i]=1) cnt++;
    }
    cout<<52-cnt;
    return 0;
}
