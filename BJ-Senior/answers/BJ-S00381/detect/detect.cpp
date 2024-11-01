#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 100005

int T,n,m,V,L;
int tant[N];

struct tantou{
    int pos,id;
};
struct qj{
    int l,r;
}q[N],qn[N];

int twofen(int d,int v,int a)
{
    int l=d,r=L+1,mid;
    while(r-l>0)
    {
        mid=(l+r)/2;
        int v2=2*a*(mid-d)+v*v;
        if(v2<=V*V)//meichaosu
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return mid;

}

int twofen2(int d,int v,int a)
{
    int l=d,r=L+1,mid;
    while(r-l>0)
    {
        mid=(l+r)/2;
        int v2=2*a*(mid-d)+v*v;
        if(v2>V*V)//chaosu
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return mid;

}


bool cmp(qj x,qj y)
{
    if(x.l==y.l)return x.r<y.r;
    else return x.l<y.l;
}

int main()
{

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;

        //get the chaoshu qujian.
        for(int i=1;i<=n;i++)
        {
            int d,v,a;
            cin>>d>>v>>a;
            if(a>0)
            {
                if(v>V)//yongyuanchaosu
                {
                    q[i]={d,L};
                }
                else
                {
                    int t=twofen(d,v,a);
                    if(t==L+1)q[i]={0,0};
                    else q[i]={t,L};
                }
            }
            if(a<0)
            {
                if(v<=V)//buchaosu
                {
                    q[i]={0,0};
                }
                else
                {
                    int t=twofen2(d,v,a);
                    if(t==L+1)q[i]={d,L};
                    else q[i]={d,t};
                }
            }
            if(a==0)//yunsu
            {
                if(v>V)
                {
                    q[i]={d,L};
                }
                else
                {
                    q[i]={0,0};
                }
            }
        }


        for(int i=1;i<=m;i++)cin>>tant[i];
        for(int i=1;i<=n;i++){
            if(q[i].l==0 && q[i].r==0)continue;

            int p1=lower_bound(tant+1,tant+m+1,q[i].l)-(tant+1);//baohan
            int p2=upper_bound(tant+1,tant+m+1,q[i].r)-(tant+1);//bubaohan
            q[i].l=p1;
            q[i].r=p2;
            if(q[i].r<=q[i].l)
            {
                q[i].l=q[i].r=0;
            }
        }

        int tot=1;
        for(int i=1;i<=n;i++)
        {
            if(q[i].l==0 && q[i].r==0)continue;
            qn[tot++]=q[i];
        }
        tot--;
        cout<<tot<<" ";

        sort(qn+1,qn+tot+1,cmp);

        int pos=1,lim=qn[1].r-1;
        int cnt=0;
        for(;pos<=tot;)
        {
            while(qn[pos].l<=lim && pos<=tot)pos++;
            lim=qn[pos].r-1;
            cnt++;
        }
        cout<<m-cnt<<endl;

    }




    return 0;
}
