#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct car
{
    double d;
    double v;
    double a;
}arr[N];
struct node
{
    int num;
    int ccnt;

}cnt[N];
bool cmp(node a,node b)
{
    return a.ccnt>b.ccnt;
}
int dis[N],mp[N][N];
bool flag[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,l,limit;
        cin>>n>>m>>l>>limit;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mp[i][j]=0;
                cnt[j].ccnt=0;
                cnt[j].num=0;
            }
        }
        for(int i=1;i<=n;i++)
            cin>>arr[i].d>>arr[i].v>>arr[i].a;
        for(int i=1;i<=m;i++)
            cin>>dis[i];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            bool flag3=false;
            for(int j=1;j<=m;j++)
            {
                if(dis[j]<=arr[i].d)
                    continue;
                double num=arr[j].d-arr[i].d;
                double vv=sqrt(arr[i].v+2*arr[i].a*num);
                if(vv>limit)
                {
                    mp[i][j]=100;
                    cnt[j].ccnt++;
                    flag3=true;
                }
            }
            if(!flag3)
                ans++;
        }
        for(int i=1;i<=m;i++)
        {
            cnt[i].num=i;
            if(cnt[i].ccnt==0)
                flag[i]=true;
        }
        sort(cnt+1,cnt+1+m,cmp);
        int cnt2=0;
        while(1)
        {
            bool flag2=false;
            for(int i=1;i<=n;i++)
            {
                if(!flag[i])
                {
                    flag2=true;
                    break;
                }
            }
            cout<<1;
            if(!flag2)
                break;
            cnt2++;
            for(int i=1;i<=n;i++)
            {
                if(mp[i][cnt[cnt2].num]!=0)
                {
                    flag[i]=true;
                    mp[i][cnt[cnt2].num]=0;
                }
            }
        }
        cout<<ans<<" "<<m-cnt2<<endl;
    }
    return 0;
}
