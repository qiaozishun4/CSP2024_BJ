#include<bits/stdc++.h>

using namespace std;
int n,m,l,v,d[100005],V[100005],a[100005],p[100005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>l>>v;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>d[i]>>V[i]>>a[i];
        }
        for(int i = 0 ; i < m ; i ++)
        {
            cin>>p[i];
        }
        srand(time(0));
        cout<<rand()%n<<" "<<rand()%m;
    }
    while(1);
    return 0;
}
