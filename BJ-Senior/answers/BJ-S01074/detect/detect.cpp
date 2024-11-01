#include <bits/stdc++.h>

using namespace std;



int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int n,m,L,V;
    for(int i=0;i<T;i++)
    {
        cin>>n>>m>>L>>V;
        int d[n],v[n],a[n],p[m][2];
        bool chao[n]={0};
        for(int j=0;j<n;j++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int j=0;j<m;j++)
        {
            cin>>p[j][0];
        }
        for(int j=0;j<n;j++)
        {
            for(int i1=0;i1<m;i1++)
            {
                if(p[i1][0]-d[j]>0&&pow(v[j],2)+2*a[j]*(p[i1][0]-d[j])>0&&sqrt(pow(v[j],2)+2*a[j]*(p[i1][0]-d[j]))>V)
                {
                    chao[j]=1;
                    p[i1][1]=1;
                    break;
                }
            }
            if(chao[j])
                break;
        }
        int sum1=0,sum2=0;
        for(int j=0;j<n;j++)
        {
            if(chao[j])
                sum1++;
        }
        for(int j=0;j<m;j++)
        {
            if(p[j][1]==0)
                sum2++;
        }
        cout<<sum1<<" "<<sum2;
        cout<<endl;
    }
    return 0;
}
