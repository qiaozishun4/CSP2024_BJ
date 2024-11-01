#include<bits/stdc++.h>
using namespace std;

long long t;
long long n,m,L,V;
long long d,v,a;
long long input;
long long ans_1;
long long maxm=0;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(long long i_j=1;i_j<=t;i_j++)
    {

        ans_1=0;
        cin>>n>>m>>L>>V;
        for(long long i=1;i<=n;i++)
        {
            cin>>d>>v>>a;
            if(a>0)
            {
                if(v>=V)ans_1++;
                else if((V-v)*(V-v)+2*(V-v)*v+d*a*2<a*2*L)
                {
                    ans_1++;
                }
            }
            else if(a==0)
            {
                if(v>V)
                {
                    ans_1++;
                }
            }
        }
        for(long long i=1;i<=m;i++)
        {
            cin>>input;
            maxm=max(maxm,input);
        }
        cout<<ans_1<<" "<<m-1<<endl;

    }

    return 0;
}
