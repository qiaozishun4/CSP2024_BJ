#include<bits/stdc++.h>
using namespace std;
int n,m,l,v_;
int d[20][100005];
int v[20][100005];
int a[20][100005];
int p[20][100005];
int u[20][100005];
int main()
{   freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
    cin>>n>>m>>l>>v_;
    for(int j=0;j<n;j++)
    {
        cin>>d[q][j]>>v[q][j]>>a[q][j];
    }
    for(int f=0;f<m;f++)
    {
        cin>>p[q][f];
    }

    int h=0;
    for(int i=0;i<n;i++)
    {
        if(v[q][i]>v_&&d[q][i]<=p[q][m-1])
        {       u[q][i]=1;
                h++;
        }
    }
    int bigest=d[q][0];
    for(int i=1;i<n;i++)
    {
        if(d[q][i]>bigest&&v[q][i]>v_&&u[q][i]==1)
       {
            bigest=d[q][i];
        }
    }
    for(int i=0;i<m;i++)
    {
        if(bigest<=p[q][i]){cout<<h<<" "<<i;break;}
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}