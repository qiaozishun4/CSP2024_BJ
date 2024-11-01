#include <bits/stdc++.h>

using namespace std;

bool b[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,S=52;
    cin>>n;
    while(n--)
    {
        string a;
        cin>>a;
        int i,j;
        if(a[1]=='A') i=1;
        else if(a[1]=='T') i=10;
        else if(a[1]=='J') i=11;
        else if(a[1]=='Q') i=12;
        else if(a[1]=='K') i=13;
        else i=a[1]-'0';
        if(a[0]=='D') j=1;
        else if(a[0]=='C') j=2;
        else if(a[0]=='H') j=3;
        else j=4;
        if(!b[j][i])
        {
            b[j][i]=1;
            S--;
        }
    }
    cout<<S;
    return 0;
}

