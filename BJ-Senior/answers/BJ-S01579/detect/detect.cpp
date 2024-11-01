/*• 1 ≤ T ≤ 20;
• 1 ≤ n, m ≤ 10^5 ,1 ≤ L ≤ 10^6 ,1 ≤ V ≤ 10^3 ;
• 0 ≤ d i < L,1 ≤ v i ≤ 10^3 ,|a i | ≤ 10^3 ;
• 0 ≤ p 1 < p 2 < · · · < p m ≤ L*/
#include<bits/stdc++.h>
using namespace std;//from north to south
struct ca
{
    int d;//south destance
    int v;//chusudu
    int a;//jiasudu
    bool ne=0;
}ca[22][100010];
int ce[22][100010];//cesu south destance
bool ke[22][100010];//cesu meiyong

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int w=0;w<T;w++)
    {
        int n,m,L,V;
        int cnt=0;
        int ans=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++)
        {
            cin>>ca[w][i].d>>ca[w][i].v>>ca[w][i].a;
        }
        for(int i=0;i<m;i++)
        {
            cin>>ce[w][i];
            for(int j=0;j<n;j++)
            {
                /*if(ca[w][j].ne==0&&(ce[w][i]>=ca[w][j].d&&sqrt(ca[w][j].v*ca[w][j].v+2*ca[w][j].a*(ce[w][i]-ca[w][j].d))>V))//chaosu
                {
                    cnt++;
                    ca[w][j].ne=1;
                    ke[w][i]=1;

                }*/
                if(ca[w][j].ne==0)
                {
                    if(ce[w][i]>=ca[w][j].d&&sqrt(ca[w][j].v*ca[w][j].v+2*ca[w][j].a*(ce[w][i]-ca[w][j].d))>V)//chaosu
                    {
                        ke[w][i]=1;
                        cnt++;
                        ca[w][j].ne=1;
                    }
                }
            }
            if(ke[w][i]==0)
            {
                ans++;
            }
          // cout<<i<<" "<<cnt<<" "<<ans<<endl;
        }
        cout<<cnt<<" "<<ans<<endl;
    }
    return 0;
}
