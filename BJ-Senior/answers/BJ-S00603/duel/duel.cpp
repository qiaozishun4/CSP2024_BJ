#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int r[N],cnt[N];
bool safe[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>r[i];
        safe[i]=1;
    }
    sort(r+1,r+n+1);
    int left=1,res=0;
    for (int i=2;i<=n;i++)
        if (r[i]>r[left])
        {
            safe[left]=0;
            while (!safe[left])
                left++;
        }
    for (int i=1;i<=n;i++)
        if (safe[i])
            res++;
    cout<<res<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
