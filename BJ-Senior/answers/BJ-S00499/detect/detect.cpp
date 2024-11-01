#include <bits/stdc++.h>
using namespace std;

int T;
int n,m,L,V;
int cs;
int d[1005],v[1005],a[1005];
int p[100005];
double sum;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=T;i++){
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]-d[i]>0){
                    sum=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                }
                else{
                    continue;
                }
                //cout<<v[i]<<" "<<a[i]<<" "<<d[i]<<endl<<sum<<endl;
                    if(sum>V){
                        cs++;

                    }
                    break;
                }


        }
        cout<<cs<<cs<<endl;
        cs=0;
    }

    return 0;
}
