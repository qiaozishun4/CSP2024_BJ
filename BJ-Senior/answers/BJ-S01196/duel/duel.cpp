#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int r[N];
queue <int> q;
int n;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        if(q.size()){
            if(r[i]>q.front()) q.pop();
        }
        q.push(r[i]);
    }
    printf("%d\n",q.size());
    return 0;
}
