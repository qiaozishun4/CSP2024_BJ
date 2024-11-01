#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,cnt;
int cnt1[200],cnt2[200],cnt3[200],cnt4[200];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string tmp;
        char cha,cnum;
        cin>>tmp;
        cha=tmp[0];
        cnum=tmp[1];
        int num;
        if(cnum>='2'&&cnum<='9')
        {
            num=cnum-'0';
        }
        if(cnum=='A')num=1;
        if(cnum=='T')num=10;
        if(cnum=='J')num=11;
        if(cnum=='Q')num=12;
        if(cnum=='K')num=13;
        if(cha=='D')cnt1[num]++;
        if(cha=='C')cnt2[num]++;
        if(cha=='H')cnt3[num]++;
        if(cha=='S')cnt4[num]++;
    }
    for(int i=1;i<=13;i++)
    {
        if(cnt1[i]>=1)cnt++;
        if(cnt2[i]>=1)cnt++;
        if(cnt3[i]>=1)cnt++;
        if(cnt4[i]>=1)cnt++;
    }
    cout<<52-cnt;
    return 0;
}
