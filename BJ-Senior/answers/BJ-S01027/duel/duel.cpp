#include<iostream>
using namespace std;
int n,tp;
int num[100005],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tp;
        num[tp]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(num[i]>num[ans])
            ans=i;
    }
    cout<<num[ans]<<endl;
    return 0;
}
