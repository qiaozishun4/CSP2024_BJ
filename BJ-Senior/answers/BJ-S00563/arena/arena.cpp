#include<iostream>
#include<vector>
using namespace std;

const int MXN=1e5+10;

int ap[MXN],a[MXN],c[MXN];
vector<int> v[35];
int lg[MXN];

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ap[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    cout<<"HI\n"<<endl;cout<<c[m]<<endl;
    for(int i=1;i<=lg[n]+1;i++)
    {
        v[i].push_back(0);
        // cout<<i<<' '<<(1<<(lg[n]+1-i))<<endl;
        for(int j=1;j<=(1<<(lg[n]+1-i));j++)
        {
            char c;cin>>c;cout<<c<<' ';
            v[i].push_back(c-'0');
        }cout<<endl;
        // cout<<i<<' '<<(1<<(lg[n]+1-i))<<endl;
    }
    int T;cin>>T;
    // cout<<"Yippie!"<<' '<<T<<endl;
    while(T--)
    {
        int x[4];
        for(int i=0;i<=3;i++) cin>>x[i];
        int ret=0;
        for(int i=1;i<=n;i++) a[i]=ap[i]^x[i%4];
        for(int kk=1;kk<=m;kk++)
        {
            int ppl=c[kk];
            // cout<<ppl<<' '<<kk<<endl;
            for(int _=1;_<=lg[c[kk]]+1;_++)
            {
                if(ppl==1) break;
                for(int i=1;i<=ppl/2;i++)
                {
                    int c1=2*i-1,c2=2*i;
                    if(v[_][i]==0) a[i]=a[c1];
                    else a[i]=a[c2];
                }ppl/=2;
            }ret^=a[1];
        }cout<<ret<<endl;
    }
}
// caca save me!
// zyh save me!
// zch save me!
// lqy save me!