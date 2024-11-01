#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,mx=-1e9;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        mx=max(mx,tmp);
        arr[tmp]++;
    }
    int num=0;
    for(int i=1;i<=mx;i++)
    {
        if(arr[i]>0)
        {
            int cnt=arr[i]-num;
            if(cnt<0)
                num=abs(cnt)+arr[i];
            else
                num=arr[i];
        }
    }
    cout<<num;
    return 0;
}
