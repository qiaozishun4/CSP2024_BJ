#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","r",stdout);
    cin >> n;
    ans=n;
    for(int i=1;i<=n;i++)cin >> r[i];
    sort(r+1,r+n+1);
    int sum=0,willdie=2;
    for(int i=2;r[i]==r[i-1];i++)willdie++;
    for(int i=willdie;i<=n;i++)
    {
        sum++;
        if(r[i+1]!=r[i])
        {
            if(willdie<=sum)ans-=willdie;
            else ans-=sum;
            if(willdie<=sum)willdie=sum;
            sum=0;
        }
    }
    cout << ans;
    return 0;
}
