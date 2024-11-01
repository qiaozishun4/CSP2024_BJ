#include<bits/stdc++.h>
using namespace std;

int T,n,m,L,V,chaosu=0,panfa=0;
int main()
{
    freopen("detect2.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    scanf("%d %d %d %d",&n,&m,&L,&V);
    //cout << n<<m<<L<<V;
    int d[L+10]={},v[n+10]={},a[n+10]={},p[m+10]={};
    int is_look[n+5][m+5]={};
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&d[i],&v[i],&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int iii=1;iii<=T;iii++)
    {
        chaosu=0;
        for(int che=1;che<=n;che++)
        {
            //cout << che<<" " << endl;
            if(a[che]==0)
            {
                if(v[che]<=V)
                {
                    continue;
                }
                else
                {
                    chaosu++;
                }
            }
            else if(a[che]>0)
            {

                double chaosuweizhi=( (  (1.0*V*V)  -  (v[che]*v[che]*1.0)  )  /  (2.0*a[che])  )+d[che];
                //cout << chaosuweizhi<<" "<< che <<endl;
                if(!(chaosuweizhi > L || chaosuweizhi>p[m]))
                {
                    chaosu++;
                }
                else
                {
                    continue;
                }

                int l=1,r=m,mid=m/2,last_mid,tuichu=0;
                while(l<=r)
                {
                    if(p[mid]<chaosuweizhi)
                    {
                        l=mid+1;
                        //cout <<" l "<<l<<" r "<<r <<" p " <<p[mid]<<" cswz " <<chaosuweizhi<<endl;
                    }
                    else if(p[mid]==chaosuweizhi)
                    {
                        break;
                    }
                    else
                    {
                        r=mid-1;
                        //cout <<" l "<<l<<" r "<<r <<" p " <<p[mid]<<" cswz " <<chaosuweizhi<<endl;
                    }
                    last_mid=mid;
                    mid=(l+r)/2;
                    if(last_mid==mid)tuichu++;
                    else
                    {
                        tuichu=0;
                        continue;
                    }
                    if(tuichu>=3)break;
                }
                //cout <<"ccc    "<< chaosuweizhi << " " << p[mid] <<endl<<endl<<endl;

                //if(chaosuweizhi<=p[mid])cout <<"ans "<<m-mid+1 <<" " << che<<endl;
                //else if(chaosuweizhi>p[mid])cout <<"ans "<<m-mid <<" " << che<<endl;
            }
            else if(a[che]<0)
            {
                double chaosuweizhi=( (  (1.0*V*V)  -  (v[che]*v[che]*1.0)  )  /  (2.0*a[che])  )+d[che];
                //cout <<chaosuweizhi<<" " <<che << endl;
                if(!(chaosuweizhi < d[che] || chaosuweizhi<p[1]))
                {
                    chaosu++;
                }
                else
                {
                    continue;
                }

                int l=1,r=m,mid=m/2,last_mid,tuichu=0;
                while(l<=r)
                {
                    if(p[mid]<chaosuweizhi)
                    {
                        l=mid+1;
                        //cout <<" l "<<l<<" r "<<r <<" p " <<p[mid]<<" cswz " <<chaosuweizhi<<endl;
                    }
                    else if(p[mid]==chaosuweizhi)
                    {
                        break;
                    }
                    else
                    {
                        r=mid-1;
                        //cout <<" l "<<l<<" r "<<r <<" p " <<p[mid]<<" cswz " <<chaosuweizhi<<endl;
                    }
                    last_mid=mid;
                    mid=(l+r)/2;
                    if(last_mid==mid)tuichu++;
                    else
                    {
                        tuichu=0;
                        continue;
                    }
                    if(tuichu>=3)break;
                }
                //cout <<"ccc    "<< chaosuweizhi << " " << p[mid] <<endl<<endl<<endl;

                //if(chaosuweizhi<p[mid])cout <<"ans "<<mid-1 <<" " << che<<endl;
                //else if(chaosuweizhi>=p[mid])cout <<"ans "<<mid <<" " << che<<endl;
            }
        }
    cout <<chaosu<< " " << 10 <<endl;
    }

    fclose(stdin);
    //fclose(stdout);
    return 0;
}
