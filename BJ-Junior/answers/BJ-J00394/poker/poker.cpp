#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    string a;
    int num=0;
    bool card[53];
    for(int i=0;i<=52;i++)
    {
        card[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a;
        int papernum=0;
        if(a[0]=='D')papernum+=0;
        if(a[0]=='C')papernum+=13;
        if(a[0]=='H')papernum+=26;
        if(a[0]=='S')papernum+=39;
        if(a[1]>='2'&&a[1]<='9')papernum+=a[1]-'0';
        if(a[1]=='A')papernum+=1;
        if(a[1]=='T')papernum+=10;
        if(a[1]=='J')papernum+=11;
        if(a[1]=='Q')papernum+=12;
        if(a[1]=='K')papernum+=13;

        if(card[papernum]==0)
        {
            card[papernum]=1;
            num++;
        }
    }
    cout<<52-num;
    return 0;

}
