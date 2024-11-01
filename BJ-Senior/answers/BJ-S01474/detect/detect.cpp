#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n, m, L, V;
int T;
int cs(int firstV, int jiaV)
{
    return (V*V-firstV * firstV) / (2 * jiaV);
}
int cv[MAXN];
int jvq[MAXN];
int lk[1000005];
int jsd[MAXN], d[MAXN];
int poil(float num)
{
    if(num-(int)num==0) return num;
    return num+1;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>T;
    while(T--)
    {

        //printf("...\n");
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i=1; i<=n; i++)
        {
            int v, a;
            scanf("%d%d%d", &d[i], &v, &a);
            jsd[i]=a;
            if(a==0)
            {
                cv[i]=v>V?MAXN:0;
                continue;
            }
            float cnt=cs(v, a);
            if(a>0) cv[i]=cnt;
            else cv[i]=cnt;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &jvq[i]);
        }
        int cnt=1;
        for(int i=1; i<=L; i++)
        {
            lk[i]=lk[i-1];
            if(i==jvq[cnt])
            {
                lk[i]++;
                cnt++;
            }
        }
        int ans=0;
        bool is_cv[MAXN];
        vector<int> fg[MAXN];
        for(int i=1; i<=n; i++)
        {
            if(jsd[i]>0)
            {
                if(m-lk[d[i]+cv[i]])ans++, is_cv[i]=1;

            }
            else if(jsd[i]<0)
            {
                if(lk[d[i]+cv[i]]!=lk[d[i]-1]) ans++, is_cv[i]=1;
                else if(d[i]+cv[i]>L) ans++, is_cv[i]=1;

            }
            else
            {
                if(cv[i]==MAXN&&m-lk[d[i]-1]) ans++, is_cv[i]=1;

            }
            //printf("cv[i]=%d, lk[d[i]+cv[i]]=%d, lk[d[i]-1]=%d\n",cv[i], lk[d[i]+cv[i]], lk[d[i]-1]);
        }
        printf("%d ", ans);

        ans=0;
        int te[MAXN]={0};
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(is_cv[j]==0) {continue;}
                if(jsd[i]>0)
                {
                    if(jvq[i]>=d[j]+cv[j]&&jvq[i]<=L) fg[i].push_back(j), te[i]++;
                }
                else if(jsd[i]<0)
                {

                    if(jvq[i]>=d[j]&&jvq[i]<=(d[j]+cv[j])) fg[i].push_back(j), te[i]++;
                }
                else
                {
                    fg[i].push_back(j), te[i]++;
                }
            }
        }
        bool flag[MAXN]={0};
        for(int i=1; i<=n; i++)
        {
            if(!is_cv[i]) sum++;
        }
        int nm=n-sum;
        while(nm)
        {
            int maxn=-1e9, maxi;
            for(int i=1; i<=m; i++)
            {
                if(maxn<te[i]) maxn=te[i], maxi=i;
            }
            int falg=0;
            //cout<<maxn<<" ";
            nm-=maxn;
            for(int i=0; i<=fg[i].size(); i++)
            {
                if(!flag[fg[maxi][i]])
                {
                    flag[fg[maxi][i]]=1;
                    ans++;
                }
            }
        }
        printf("%d\n", m-ans);
    }
}
