#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005],cnt[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],cnt[a[i]]++;
    sort(a+1,a+n+1);
    int m=unique(a+1,a+n+1)-a-1;
    int ans=0,sum=0;
    for(int i=1;i<=m;i++)
    {
        //a[i] to attack a[i-1]
        int num=cnt[a[i]];
        if(sum>=num)
            sum-=num,num=0;
        else
            num-=sum,sum=0;
        sum+=num;
    }
    cout<<sum<<endl;
    return 0;
}
