#include <iostream>
#include <set>
using namespace std;
const int N=1e3+3,L=2000+3,S=2e5+3;
int s[N][L];
int l[N];
set<int> app_in[N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++)
        {
            cin>>l[i];
            for (int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
                app_in[s[i][j]].insert(i);
            }
        }
        while (q--)
        {
            int r,c;
            cin>>r>>c;
            if (app_in[c].size()==0)
            {
                cout<<'0'<<endl;
                continue;
            }
            bool flag=false;
            for (auto x:app_in[c])
            {
                bool start_find_a=false;
                int c_pos=2147483647;
                int min_c1_dis=2147483647;
                for (int i=l[x];i>=1;i--)
                {
                    if (s[x][i]==c)
                    {
                        c_pos=i;
                        start_find_a=true;
                    }
                    if (s[x][i]==1&&start_find_a)
                    {
                        min_c1_dis=min(min_c1_dis,c_pos-i+1);
                    }
                }
                if (min_c1_dis<=k)
                {
                    flag=true;
                    break;
                }
            }
            if (flag)
            {
                cout<<'1'<<endl;
            }
            else
            {
                cout<<'0'<<endl;
            }
        }
    }
return 0;
}
