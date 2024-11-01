#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#define endl '\n'
using namespace std;
int T,n;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int chose[15]={0,-1,1,7,4,2,6,8,10,18,22};
void solve()
{
    int cnt8=0,cnt0=0,fst=0;
    cin>>n;
    if(n<=10)
    {
        cout<<chose[n]<<endl;
        return;
    }
    cnt8=n/7;
    int mol=n%7;
    if(mol==0)
    {
        fst=8;
        cnt8--;
    }
    else if(mol==1)
    {
        cnt0++;
        cnt8--;
        fst=1;
    }
    else if(mol==2)
    {
        fst=1;
    }
    else if(mol==3)
    {
        cnt8-=2;
        cnt0+=2;
        fst=2;
    }
    else if(mol==4)
    {
        cnt8--;
        cnt0++;
        fst=2;
    }
    else if(mol==5)
    {
        fst=2;
    }
    else if(mol==6)
    {
        fst=6;
    }
    cout<<fst;
    for(int i=1;i<=cnt0;i++) cout<<0;
    for(int i=1;i<=cnt8;i++) cout<<8;
    cout<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}


