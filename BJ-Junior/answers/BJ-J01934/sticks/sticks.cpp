#include<bits/stdc++.h>
using namespace std;
int sn[10]={6,2,5,5,4,5,6,3,7,6};
int n;
bool stn(int _i,int _m)
{
    string num;
    while(_i/10>0)
    {
        num=num+(char)(_i%10+'0');
        _i/=10;
    }
    num=num+(char)(_i%10+'0');
    int sum=0;
    for(int i=0;i<num.size();i++)
        sum+=sn[(num[i]-'0')];
    if(sum==_m)return true;
    return false;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        if(m<2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(m%7==0)
        {
            for(int i=0;i<m/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        else if(m%7==1)
        {
            cout<<10;
            for(int i=0;i<m/7-1;i++)cout<<8;
            cout<<endl;
            continue;
        }
        for(int i=0;;i++)
        {
            if(stn(i,m)==true&&i!=0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
