#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
int sa[1000005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int n,m,ll,vm,car=0;
        cin>>n>>m>>ll>>vm;
        for (int l=1;l<=n;l++)cin>>d[l]>>v[l]>>a[l];
        for (int l=1;l<=m;l++)cin>>p[l];
        for (int l=1;l<=m;l++)sa[ll-p[l]]=1;
        for (int l=1;l<=n;l++)
        {
            if (v[l]>vm && a[l]>=0)
            {
                bool qw=0;
                for (int j=ll-d[l];j>=0;j--)
                {
                    if (sa[j]==1)
                    {
                        car++;
                        break;
                    }
                }
                for (int j=ll-d[l];j>=0;j--)
                {
                    if (sa[j]==1)sa[j]=2;
                    else if (sa[j]==2)qw=1;
                    else sa[j]=3;
                }
                if (qw=1)
                {
                    for (int j=ll-d[l]+1;j<=ll;j++)
                    {
                        if (sa[j]==1 || sa[j]==1)break;
                        if (sa[j]==2)sa[j]=1;
                        if (sa[j]==3)sa[j]=0;
                    }
                }
            }
            else if (v[l]>vm && a[l]<0)
            {
                int x=(vm*vm-v[l]*v[l])/(2*a[l]);
                if (ll-d[l]-x<0)x=ll-d[l];
                bool qw=0;
                for (int j=ll-d[l];j>=ll-d[l]-x;j--)
                {
                    if (sa[j]==1)
                    {
                        car++;
                        break;
                    }
                }
                for (int j=ll-d[l];j>=ll-d[l]-x;j--)
                {
                    if (sa[j]==1)sa[j]=2;
                    else if (sa[j]==2)qw=1;
                    else sa[j]=3;
                }
                if (qw==1)
                {
                    for (int j=ll-d[l]+1;j<=ll;j++)
                    {
                        if (sa[j]==1 || sa[j]==0)break;
                        if (sa[j]==2)sa[j]=1;
                        if (sa[j]==3)sa[j]=0;
                    }
                    for (int j=ll-d[l]-x-1;j>=0;j--)
                    {
                        if (sa[j]==1 || sa[j]==0)break;
                        if (sa[j]==2)sa[j]=1;
                        if (sa[j]==3)sa[j]=0;
                    }
                }
            }
            else if (v[l]<vm && a[l]>0)
            {
                int x=int((v[l]*v[l]-vm*vm)/(2*a[l])+0.999999);
                bool qw=0;
                for (int j=ll-d[l]-x;j>=0;j--)
                {
                    if (sa[j]==1)
                    {
                        car++;
                        break;
                    }
                }
                for (int j=ll-d[l]-x;j>=0;j--)
                {
                    if (sa[j]==1)sa[j]==2;
                    else if (sa[j]==2)qw=1;
                    else sa[j]=3;
                }
                if (qw==1)
                {
                    for (int j=ll-d[l]-x+1;j<=ll;j++)
                    {
                        if (sa[j]==1 || sa[j]==0)break;
                        if (sa[j]==2)sa[j]=1;
                        if (sa[j]==3)sa[j]=0;
                    }
                }
            }
        }
        int sum=0;
        for (int l=0;l<=ll;l++)
        {
            if (sa[l]==2)sum++;
        }
        cout<<car<<" "<<m-sum;
    }
    return 0;
}
