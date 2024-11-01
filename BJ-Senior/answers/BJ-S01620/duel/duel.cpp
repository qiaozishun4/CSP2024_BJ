#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    int id,r;
}a[N];
bool cmp(node x,node y)
{
    return x.r<y.r;
}
queue<node> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].r;
        a[i].id=1;
    }
    sort(a+1,a+n+1,cmp);
    q.push(a[1]);
    for(int i=2;i<=n;i++)
    {
        if(a[i].r>q.front().r)
        {
            q.pop();
            q.push(a[i]);
        }
        else if(a[i].r==q.front().r)
        {
            q.push(a[i]);

        }
    }
    cout<<q.size();
    return 0;
}

