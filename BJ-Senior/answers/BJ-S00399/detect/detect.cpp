#include<bits/stdc++.h>
using namespace std;
struct {
    int d;
    int v;
    int a;
}a[1000005];
int n,m,l,v;
int p[1000001][2];
int ans;
void pd(int c)
{
    if(a[c].a>0)
    {
        for(int i=d,j=a[c].v;i<=l;i+=j,j+=a[c].a)
        {
            if(d>=p[m-1][0])
            {
                if(j>v){p[m-1][1]=1;return;}
            }
        }
    }
    else
    {
        for(int i=d,j=a[c].v;i<=l,j>0;i+=j,j-=a[c].a)
        {
            for(int k=0;p[k]>=d&&p[k]<=i;k++)
            {
                if(j>v){p[k][1]=1;return;}
            }
        }
    }
}
int main()
{
    ifstream fin("detect.in",ios::in);
    ofstream fout("detect.out",ios::out);
    fin>>n>>m>>l>>v;
    //cin>>n>>m>>l>>v;
    for(int i=0;i<n;i++)
        fin>>a[i].d>>a[i].v>>a[i].a;
    for(int i=0;i<m;i++)
    {
        fin>>p[i][0];
    }
    for(int i=0;i<n;i++)pd(i);
    for(int i=0;i<m;i++)if(p[i][1]==0)ans++;
    fout<<ans;
    //cout<<ans;
    fin.close();
    fout.close();
    return 0;
}