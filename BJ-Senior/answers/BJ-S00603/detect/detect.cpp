#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
struct Car
{
    int plc_comein;
    long long fst_veloci;
    long long add_veloci;
};
Car car[N];
int cam[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n,m,L,res1=0;
        long long lim_veloci;
        cin>>n>>m>>L>>lim_veloci;
        lim_veloci*=lim_veloci;
        for (int i=1;i<=n;i++) cin>>car[i].plc_comein>>car[i].fst_veloci>>car[i].add_veloci;
        for (int i=1;i<=m;i++) cin>>cam[i];
        sort(cam+1,cam+m+1);
        for (int i=1;i<=n;i++)
        {
            long long fst=car[i].fst_veloci,add=car[i].add_veloci;
            int plc=car[i].plc_comein,j=1;
            while (cam[j]<plc) j++;
            bool higher=0;
            for (;j<=m;j++)
            {
                long long dist=cam[j]-plc;
                long long now_veloci=fst*fst+2*add*dist;
                if (now_veloci>lim_veloci)
                {
                    higher=1;
                    break;
                }
            }
            if (higher) res1++;
        }
        cout<<res1<<' '<<n-1<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
