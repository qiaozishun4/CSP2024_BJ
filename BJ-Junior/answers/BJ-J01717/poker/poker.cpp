#include<iostream>
using namespace std;
int pu[52];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int a1,b1;
        if(a=='D') a1=0;
        else if(a=='C') a1=1;
        else if(a=='H') a1=2;
        else if(a=='S') a1=3;
        if(b=='A') b1=1;
        else if(b=='2') b1=2;
        else if(b=='3') b1=3;
        else if(b=='4') b1=4;
        else if(b=='5') b1=5;
        else if(b=='6') b1=6;
        else if(b=='7') b1=7;
        else if(b=='8') b1=8;
        else if(b=='9') b1=9;
        else if(b=='T') b1=10;
        else if(b=='J') b1=11;
        else if(b=='Q') b1=12;
        else if(b=='K') b1=13;
        b1=(b1-1)*4;
        int num=b1+a1;
        pu[num]++;
    }
    int sum=0;
    for(int i=0;i<52;i++)
    {
        if(!pu[i]) sum++;
    }
    cout<<sum;
    return 0;
}
