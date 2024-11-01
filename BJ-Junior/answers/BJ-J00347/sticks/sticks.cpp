#include <iostream>
#include <queue>
using namespace std;
int t;
int n;
long long ans;
struct ss
{
    int last;
    int val;
    int len;
};
void bfs()
{
    queue <ss> q;
    q.push({n,0,0});
    while(!q.empty())
    {
        int la=q.front().last;
        int va=q.front().val;
        int le=q.front().len;
        q.pop();
        if(la==0)
        {
            if(va<ans)
            {
                ans=va;
            }
        }
        if(la-5>=0)
        {
            q.push({la-5,va*10+2,le+1});
        }
        if(la-6>=0)
        {
            if(le==0)
            {
                q.push({la-6,va*10+6,le+1});
            }
            else
            {
                q.push({la-6,va*10+0,le+1});
            }
        }
        if(la-2>=0)
        {
            q.push({la-2,va*10+1,le+1});
        }
        if(la-3>=0)
        {
            q.push({la-3,va*10+7,le+1});
        }
        if(la-4>=0)
        {
            q.push({la-4,va*10+4,le+1});
        }
        if(la-7>=0)
        {
            q.push({la-7,va*10+8,le+1});
        }
    }
    return;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        ans=0x7fffffff;
        bfs();
        if(ans==0x7fffffff)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}
