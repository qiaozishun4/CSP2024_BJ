#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[256][256];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch1,ch2;
        cin>>ch1>>ch2;
        if(ch2<='9'&&ch2>='2')
        {
            a[int(ch1)][ch2-'0']++;
        }
        if(ch2=='T')
        {
            a[int(ch1)][10]++;
        }
        if(ch2=='J')
        {
            a[int(ch1)][11]++;
        }
        if(ch2=='Q')
        {
            a[int(ch1)][12]++;
        }
        if(ch2=='K')
        {
            a[int(ch1)][13]++;
        }
        if(ch2=='A')
        {
            a[int(ch1)][1]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=13;i++)
    {
        if(a['D'][i]==0)
        {
            cnt++;
        }
        if(a['C'][i]==0)
        {
            cnt++;
        }
        if(a['H'][i]==0)
        {
            cnt++;
        }
        if(a['S'][i]==0)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
