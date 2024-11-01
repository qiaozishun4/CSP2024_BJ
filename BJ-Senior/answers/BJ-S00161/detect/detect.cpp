#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0,f=1;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c*f;
}

int n,m,L,V;

int d[100005],v[100005],a[100005],p[100005],ans[100005],ans1=0,ans2=100005;

bool check(int d0,int v0,int a,int p){
    if(p<d0){
        return 0;
    }else{
        return sqrt((double)v0*(double)v0+2.0*(p-d0)*a)>V;
    }
}

int fj(int m){
    int ans=0;
    while(m!=0){
        ans+=m%2;
        m/=2;
    }
    return ans;
}

int f(int d0){
    int l=1,r=m,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(p[mid]>=d0){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T=read();

    while(T--){
        n=read(),m=read(),L=read(),V=read();

        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(ans,0,sizeof(ans));

        for(int i=1;i<=n;i++){
            d[i]=read(),v[i]=read(),a[i]=read();
        }

        for(int i=1;i<=m;i++){
            p[i]=read();
        }

        if(n<=10&&m<=10){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(check(d[i],v[i],a[i],p[j])){
                        ans[i]=1;
                        break;
                    }
                }
            }

            for(int i=1;i<=n;i++){
                if(ans[i]){
                    ans1++;
                }
            }

            for(int i=0;i<=(1<<m)-1;i++){
                if(fj(i)>ans2){
                    continue;
                }

                int i1=i,ans3=0,t=1;
                memset(ans,0,sizeof(ans));

                while(i1!=0){
                    if(i1%2){
                        for(int j=1;j<=n;j++){
                            if(check(d[j],v[j],a[j],p[t])){
                                ans[j]=1;
                            }
                        }
                    }

                    t++;
                    i1/=2;
                }

                for(int j=1;j<=n;j++){
                    if(ans[j]){
                        ans3++;
                    }
                }

                if(ans1==ans3){
                    ans2=min(ans2,fj(i));
                }
            }

            cout<<ans1<<" "<<m-ans2<<"\n";
        }else if(a[1]>=0){
            for(int i=1;i<=n;i++){
                if(check(d[i],v[i],a[i],p[m])){
                    ans[i]=1;
                    ans1++;
                }
            }

            ans2=1;

            if(ans1==0){
                ans2=0;
            }

            cout<<ans1<<" "<<m-ans2<<"\n";
        }else if(a[1]<0){
            for(int i=1;i<=n;i++){
                if(check(d[i],v[i],a[i],p[f(d[i])])){
                    ans[i]=1;
                    ans1++;
                }
            }

            ans2=0;

            cout<<ans1<<" "<<m-ans2<<"\n";
        }
        ans1=0,ans2=100005;
    }
    return 0;
}
