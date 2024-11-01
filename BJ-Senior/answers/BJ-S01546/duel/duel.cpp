#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#define endl '\n'
using namespace std;

int n,box[100005],maxn=0,minn=2e9;
int cnt=0,ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        maxn=max(maxn,x);
        minn=min(minn,x);
        box[x]++;
    }
    for(int i=minn;i<=maxn;i++)
    {
        if(box[i]==0) continue;
        int tot=box[i];
        if(tot>=cnt)
        {
            ans+=cnt;
            cnt=tot;
        }
        else
        {
            ans+=tot;
        }
    }
    cout<<n-ans<<endl;
    return 0;
}

