#include<bits/stdc++.h>
using namespace std;
long long T,n,m,L,V,d[100005],v[100005],a[100005],p;
set <long long>e;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
            long long cntr=0,cntl=0,cntt=0;
        long long tt=0,trr=1000007,ans=0;bool ll=1;
        scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);if(a[i]!=0)ll=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p);
            e.insert(p);
            tt=max(p,tt);
            trr=min(p,trr);
        }
        if(ll){

        for(int i=1;i<=n;i++){
            if(v[i]>V){

                if(d[i]<=tt){
                    ans++;
                }

            }

        }
        if(ans>0)
        cout<<ans<<" "<<m-1<<endl;
        else{cout<<0<<" "<<m<<endl;}


        }
        else{
                //cout<<tt<<endl;
                long long tans=0;
            for(int i=1;i<=n;i++){
                    if(a[i]==0){
                        if(v[i]>V){

                if(d[i]<=tt){//cout<<"ok";
                    tans++;
                    cntt=1;
                }

                     }
                    }
                else {
                    long double voo,Voo,aa,ttt,dii,ltt;ltt=tt;
                    voo=v[i];Voo=V;aa=a[i];dii=d[i];
                    ttt=(Voo-voo)/aa;//cout<<ttt<<" ";

                        long double soo=dii+voo*ttt+(aa*ttt*ttt)/2;
                        long long ins;
                        if(a[i]>0 ){



                        if( soo>=ltt or d[i]>tt){//cout<<d[i]<<" "<<x<<endl;
                        continue;}
                        tans++;
                        cntr=1;
                        }

                        if(a[i]<0){
                                if(soo<=d[i] or soo<trr)continue;
                        tans++;
                        cntl=1;


                        }


                }
            }
            if(cntt and (!cntl) and (!cntr))cntl=1;
            printf("%lld %lld\n",tans,m-cntl-cntr);
        }







    }


    return 0;
}
