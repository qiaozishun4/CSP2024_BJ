#include<iostream>
#include<algorithm>
using namespace std;
struct car{
    long long d,v,a;
    long long l,r;
    long long f;
    friend bool operator <(car X,car Y){
        if(X.l!=Y.l){
            return X.l<Y.l;
        }
        else{
            return X.r>Y.r;
        }
    }
    friend bool operator >(car X,car Y){
        if(X.l!=Y.l){
            return X.l>Y.l;
        }
        else{
            return X.r<Y.r;
        }
    }
}b[100005];
int n,m,L,V;
long long p[100005];
inline int lower(long long tar,long long mu){
    long long l=1,r=m;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(p[mid]*mu>=tar){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
inline int upper(long long tar,long long mu){
    long long l=1,r=m;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(p[mid]*mu>tar){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(register int i=1;i<=n;i++){
            cin>>b[i].d>>b[i].v>>b[i].a;
        }
        for(register int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(register int i=1;i<=n;i++){
            b[i].f=(lower_bound(p+1,p+1+m,b[i].d)-p);
        }
        int t=n;
        for(register int i=1;i<=n;i++){
            if(b[i].a==0){
                if(b[i].v>V){
                    b[i].l=b[i].f,b[i].r=m;
                }
                else{
                    b[i].l=1e18,b[i].r=1e18;
                    t--;
                }
            }
            else if(b[i].a<0){
                if(b[i].v<=V){
                    b[i].l=1e18,b[i].r=1e18;
                    t--;
                }
                else{
                    int k=lower((b[i].d)*(-2)*(b[i].a)+(b[i].v)*(b[i].v)-V*V,-2*(b[i].a))-1;
                    b[i].l=b[i].f,b[i].r=k;
                }
            }
            else{
                if(b[i].v>V){
                    b[i].l=b[i].f,b[i].r=m;
                }
                else{
                    int k=upper((b[i].d)*2*(b[i].a)+V*V-(b[i].v)*(b[i].v),2*(b[i].a));
                    b[i].l=k,b[i].r=m;
                }
            }
            if(b[i].l>b[i].r){
                b[i].l=b[i].r=1e18;
                t--;
            }
        }
        sort(b+1,b+1+n);
        n=t;
        cout<<t<<' ';
        long long minr=1e18;
        for(register int i=n;i>=1;i--){
            if(b[i].r>=minr){
                b[i].l=b[i].r=1e18;
                t--;
            }
            else{
                minr=b[i].r;
            }
        }
        long long last=-1e18;
        long long cnt=0;
        for(int i=1;i<=n;i++){
           // cout<<b[i].l<<' '<<b[i].r<<'\n';
            if(b[i].l==1e18)continue;
            if(b[i].l>last){
                last=b[i].r;
                cnt++;
                //cout<<last<<'\n';
            }
        }
        cout<<m-cnt<<'\n';
    }
    return 0;
}
