#include<bits/stdc++.h>

using namespace std;
#define int long long
template<class T>void read(T &x){
    x=0;
    int f=0;
    char c=getchar();
    while(!isdigit(c)){
        f|=(c=='-');
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(f)x=-x;
    return;
}
const int N=1e6+5,M=1e6+5;
int cnt=0;
struct node{
    int l,r;
    bool operator <(const node &zzz)const{
        return r<zzz.r;
    }
}a[N],b[N];
int p[N],sp[M],f[N],c[M];
void add(int x,int y){
    for(int i=x;i<=M-4;i+=i&(-i)){
        c[i]+=y;
    }
    return;
}
int ask(int x){
    int ans=0;
    for(int i=x;i;i-=i&(-i)){
        ans+=c[i];
    }
    return ans;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    read(t);
    while(t--){
        cnt=0;
        int n,m,l,v;
        read(n);read(m);read(l);read(v);
        l++;
        for(int i=1;i<=n;i++){
            int x,y,z;
            read(x);read(y);read(z);
            x++;
            if(z>0){
                if(y>v)a[i].l=x,a[i].r=l;
                a[i].r=l;
                a[i].l=ceil((v*v-y*y)*1.0/2/z)+x;
               // if(ceil((v*v-y*y)*1.0/2/z)+x<0)return 1;
                if(2*z*a[i].l==v*v-y*y)a[i].l++;
            }else if(z==0){
                if(y>v)a[i].l=x,a[i].r=l;
                else a[i].l=l+1;
            }else {
                if(y<v)a[i].l=l+1;
                else{
                    a[i].l=x;
                    a[i].r=((y*y-v*v)/2/(-z))+x;
                    //if(ceil((v*v-y*y)*1.0/2/z)+x<0)return 1;
                   // puts("*");
                    a[i].r=min(l,a[i].r);
                }
            }
           // if(a[i].l<0)return 1;
           // printf("%d %d*\n",a[i].l,(y*y-v*v)/2/(-z)+x);
        }
        for(int i=1;i<=m;i++){
            read(p[i]);
            p[i]++;
            sp[p[i]]++;
            f[i]=0;
        }
        for(int i=1;i<=M-5;i++)sp[i]+=sp[i-1];
        for(int i=1;i<=n;i++){
            if(a[i].l>l)continue;
            if(sp[a[i].r]-sp[a[i].l-1])b[++cnt]=(node){a[i].l,a[i].r};
        }
        sort(b+1,b+1+cnt);
        int z=0,x=0,ans=m;

        int ad=0;
        //puts("@#%$#$5");
        for(int i=1;i<=m;i++){
            while((b[z+1].r<p[i])&&(z+1<=cnt)){

                //if(b[z+1].l<=0||b[z+1].l>l)return 0;
               // cout<<b[z+1].l<<endl;
                if(b[z+1].l>0)
                add(b[z+1].l,1);
                else ad++;
            //    cout<<b[z+1].l<<endl;
                z++;
            }
            while(ask(p[x])+ad<z){
                x++;
            }
            f[i]=f[x]+1;
            if(cnt==z)ans=min(ans,f[i]);
        }
        if(z+1<cnt){
             //   puts("******88");
            while(z+1<=cnt){
                   //cout<<b[z+1].l<<endl;
                  if(b[z+1].l>0)
                add(b[z+1].l,1);
                else ad++;
           // cout<<b[z+1].l<<endl;
                z++;
                //if(z>cnt)puts("#@%^%^");
            }//puts("%^3");
        }
        for(int i=1;i<=n;i++){
            if(cnt==ask(p[i])+ad)ans=min(ans,f[i]);
        }
        //cout<<m<<endl;
        if(cnt==0)ans=0;
        printf("%lld %lld\n",cnt,m-ans);
        for(int i=1;i<=M-4;i++)sp[i]=c[i]=0;
    }
    return 0;
}
