#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m,L,V,ans1,ans2,p[100010],d[100010],v[100010],a[100010],cnt;
struct DET
{
    int x,y;
};
DET q[100010];//chaosu qujian
bool cmp(DET xx,DET yy)
{
    return xx.y < yy.y;
}

//chaosu 1,buchao 0
bool check(int now,int mid)//dijiliangche dijigecesuyi
{
    //shifoutingzhi
    //printf("C%d %d ",now,mid);
    if(a[now] < 0 && (0-1ll*v[now]*v[now]) > 1ll*(p[mid]-d[now])*2*a[now]) return false;
    long long vtf = 1ll*v[now]*v[now]+1ll*2*a[now]*(p[mid]-d[now]);
    //printf("C %d %d %lld   ",now,mid,vtf);
    if(vtf > 1ll*V*V) return true;
    else return false;
}

void ji(int now)
{
    //zhao diyige celiangdian
    int l = 1,r = m,qi;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(p[mid] >= d[now]) r = mid;
        else l = mid+1;
    }
    if(d[now] > p[l])
    {
        ans1--;
        return;
    }
    qi = l;
    if(a[now] == 0)
    {
        if(v[now] <= V) ans1--;
        else{
            q[++cnt].x = qi;
            q[cnt].y = m;
        }
    }
    else if(a[now] < 0)
    {
        //zhao zuihouyige chao
        l = qi,r = m;
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(check(now,mid)) l = mid;
            else r = mid-1;
        }

        if(check(now,l)) {
            q[++cnt].x = qi;
            q[cnt].y = l;
        }
        else ans1--;
    }
    else
    {
        //zhao diyige chao
        l = qi,r = m;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(check(now,mid)) r = mid;
            else l = mid+1;
        }

        if(check(now,l)) {
            q[++cnt].x = l;
            q[cnt].y = m;
        }
        else ans1--;
    }
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        cnt = 0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        ans1 = n;ans2 = m;
        for (int i = 1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for (int i = 1;i<=m;i++)
            scanf("%d",&p[i]);
        for (int i = 1;i<=n;i++)
            ji(i);
        sort(q+1,q+1+cnt,cmp);
        int lst = 0;
        for (int i = 1;i<=cnt;i++)
        {
            //printf("%d %d  ",q[i].x,q[i].y);
            if(q[i].x > lst)
            {
                ans2--;
                lst = q[i].y;
            }
            //if(q[i].x > q[i].y) printf("W %d %d ",q[i].x,q[i].y);
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}