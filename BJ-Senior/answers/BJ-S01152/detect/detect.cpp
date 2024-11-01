#include <bits/stdc++.h>
using namespace std;
int p[100005];
int t;
int n;
struct car{
    int d,u,a;
};
struct q{
    int L,R;
};
q qj[100005];
car c[100005];
int flag=1;
double sssd(int x,int s){
    double tt=sqrt(c[x].u*c[x].u+2*c[x].a*s);
    flag=(tt*tt==c[x].u*c[x].u+2*c[x].a*s);
    return tt;

}
bool cmp(q x,q y){
    if(x.R==y.R){
        return x.L<y.L;
    }
    return x.R<y.R;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //next_permutation();

    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
             cin>>c[i].d>>c[i].u>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++){
            int ans=0;
            int l=1,r=m;
            while(l<=r){
                int mid=l+r>>1;
                if(p[mid]>=c[i].d){
                    r=mid-1;
                    ans=mid;
                }
                else{
                    l=mid+1;

                }
            }
            if(p[ans]>=c[i].d && sssd(i,p[ans]-c[i].d)>v || p[m]>=c[i].d && sssd(i,p[m]-c[i].d)>v){
                cnt++;
                //cout<<int(p[ans]>=c[i].d && sssd(i,p[ans]-c[i].d)>v)<<" "<<int(p[m]>=c[i].d && sssd(i,p[m]-c[i].d)>v)<<" --- ";
                if(p[ans]>=c[i].d && sssd(i,p[ans]-c[i].d)>v){
                    qj[cnt].L=ans;
                    if(p[m]>=c[i].d && sssd(i,p[m]-c[i].d)>v){
                        qj[cnt].R=m;
                        //cout<<"123  ";
                    }
                    else{
                        int ans2=0;
                        int l=ans,r=m;
                        while(l<=r){
                            int mid=l+r>>1;
                            if(p[mid]>=c[i].d && sssd(i,p[mid]-c[i].d)>v){
                                l=mid+1;
                                ans2=mid;
                            }
                            else{
                                r=mid-1;

                            }
                        }
                        qj[cnt].R=ans2;
                    }

                }
                else{
                    qj[cnt].R=m;
                    int ans2=0;
                    int l=ans,r=m;
                    while(l<=r){
                        int mid=l+r>>1;
                        if(p[mid]>=c[i].d && sssd(i,p[mid]-c[i].d)>v){
                            r=mid-1;
                            ans2=mid;
                        }
                        else{
                            l=mid+1;

                        }
                    }
                    qj[cnt].L=ans2;
                }
                //cout<<qj[cnt].L<<" "<<qj[cnt].R<<" --- "<<endl;
            }


        }
        sort(qj+1,qj+cnt+1,cmp);
        int ppp=-1;
        int cnt2=0;
        for(int i=1;i<=cnt;i++){

            if(qj[i].L<=ppp && qj[i].R>=ppp){
                continue;
            }
            cnt2++;
            ppp=qj[i].R;


        }
        cout<<cnt<<" "<<m-cnt2<<endl;
    }



    return 0;
}
