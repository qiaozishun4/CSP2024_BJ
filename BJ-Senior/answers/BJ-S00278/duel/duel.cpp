#include<bits/stdc++.h>
using namespace std;
int cnt[100005];
vector<int> v;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        if(cnt[tmp]==1)v.emplace_back(tmp);
        cnt[tmp]++;
    }
    sort(v.begin(),v.end());
    int left=0;
    for(int i:v)
    {
        left-=cnt[i];
        left=max(left,0);
        left+=cnt[i];
    }
    printf("%d\n",left);
}
