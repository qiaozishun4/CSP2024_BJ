#include<bits/stdc++.h>
using namespace std;
int T,n;
int num[10];
void f(int n)
{
    num[8]=n/7;
    int a=n%7;
    if(a==0) return ;
    if(a==1)
    {
        num[8]--;
        num[0]++;
        num[1]++;
    }
    if(a==2) num[1]++;
    if(a==3) num[7]++;
    if(a==4) num[4]++;
    if(a==5) num[2]++;
    if(a==6) num[6]++;
    return ;
}
void pri()
{
    if(num[0])
    {
        cout<<"1"<<"0";
    }else
    {
        for(int i=1;i<8;i++)
        {
            if(num[i]) cout<<i;
        }
    }
    for(int i=0;i<num[8];i++)
    {
        cout<<"8";
    }
    cout<<endl;
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        f(n);
        pri();
        memset(num,0,sizeof(num));
    }
    return 0;
}
