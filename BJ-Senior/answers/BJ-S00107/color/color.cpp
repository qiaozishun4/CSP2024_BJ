#include <iostream>
#include <bitset>
#include <cstring>
#define int long long
using namespace std;
constexpr int N=1e5+2,A=1e6+3;
int a[N];
int n;
int maxc=-1;
bitset<N> state;
bool operator>(const bitset<N> x,const bitset<N> y)
{
    for (int i=1;i<N;i++)
    {
        if (x[i]!=y[i])
        {
            return x[i]>y[i];
        }
    }
    return false;
}
void dfs(int i,int c)
{
    //cout<<i<<" "<<c<<" "<<state[i]<<" "<<n<<endl;


    for (int j=i-1;j>=1;j--)
    {
        if (state[j]==state[i])
        {
            //cout<<"matched"<<endl;
            if (a[i]==a[j])
            {
                //cout<<"matched"<<endl;
                c+=a[i];
                //cout<<c<<endl;
            }
            break;
        }
    }
    if (i==n)
    {
        maxc=max(maxc,c);
        //cout<<maxc<<" "<<c<<endl;
        //cout<<state.to_string()<<" "<<c<<endl;
        return;
    }
    state[i+1]=1;
    dfs(i+1,c);
    state[i+1]=0;
    bitset<N> flipstate(state);
    flipstate.flip();
    if (flipstate>state)
    {
        return;
    }
    dfs(i+1,c);
}
bool vis[A];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        state.reset();
        cin>>n;
        maxc=-1;
        bool uniq=true;
        memset(vis,0,sizeof vis);
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (vis[a[i]])
            {
                uniq=false;
            }
            vis[a[i]]=true;
        }
        if (uniq)
        {
            cout<<'0'<<endl;
            continue;
        }
        dfs(0,0);
        cout<<maxc<<endl;
    }
    return 0;
}
