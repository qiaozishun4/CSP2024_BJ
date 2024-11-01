#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100010],v2[100010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,q;
        cin >> n >>k >>q;
        for(int i=1; i<=n; i++)
        {
            int l;
            cin >> l;
            for(int i=1; i<=l; i++)
            {
                int x;
                cin >> x;
                v[l].push_back(x);
            }
        }
        for(int i=1; i<=n; i++)
        {
            int kp=-1e6;
            for(int j=0; j<v[i].size(); j++)
            {
                if(j-kp<k) v2[i].push_back(j);
                if(v[i][j]==1) kp=j;
            }
        }
        while(q--)
        {
            int ri,ci;
            cin >> ri >> ci;
            if(ri==1)
            {
                bool ff=0;
                for(int i=1; i<=n; i++)
                {
                    for(auto it:v2[i])
                        if(it==ci)
                        {
                            cout << 1 << endl;
                            ff=1;
                            break;
                        }
                    if(ff) break;
                }
                if(!ff) cout << 0 << endl;
            }

        }
    }
    return 0;
}