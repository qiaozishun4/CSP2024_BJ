#include<bits/stdc++.h>
using namespace std;
bool b[54];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.ans","w",stdout);
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        cin >> a;
        int x;
        if(a[1]=='A') x=1;
        if(a[1]=='2') x=2;
        if(a[1]=='3') x=3;
        if(a[1]=='4') x=4;
        if(a[1]=='5') x=5;
        if(a[1]=='6') x=6;
        if(a[1]=='7') x=7;
        if(a[1]=='8') x=8;
        if(a[1]=='9') x=9;
        if(a[1]=='T') x=10;
        if(a[1]=='J') x=11;
        if(a[1]=='Q') x=12;
        if(a[1]=='K') x=13;
        if(a[0]=='S') b[x]=1;
        if(a[0]=='H') b[x+13]=1;
        if(a[0]=='D') b[x+26]=1;
        if(a[0]=='C') b[x+39]=1;
    }
    int cnt=0;
    for(int i = 1; i <= 52; i++)
    {
        if(b[i]==0) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}
