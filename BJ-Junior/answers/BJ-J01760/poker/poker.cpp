#include <iostream>
using namespace std;
int poker[53];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp=0;
        string a;
        cin>>a;
        if(a[0]=='S')
            tmp=1;
        if(a[0]=='D')
            tmp=2;
        if(a[0]=='H')
            tmp=3;
        tmp*=13;
        for(int j=2;j<10;j++)
        {
            if(a[1]==j+48)
                tmp+=j;
        }
        if(a[1]=='A')
            tmp++;
        if(a[1]=='T')
            tmp+=10;
        if(a[1]=='J')
            tmp+=11;
        if(a[1]=='Q')
            tmp+=12;
        if(a[1]=='K')
            tmp+=13;
        poker[tmp]++;
    }
    int cnt=0;
    for(int i=1;i<=52;i++)
    {
        if(!poker[i])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
