#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd(){
    char ch=getchar();
    int t=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }
    int num=0;
    while('0'<=ch&&ch<='9'){
        num=num*10+(ch-'0');
        ch=getchar();
    }
    return num*t;
}
inline void pt(int x){
    if(x<0){
        putchar('-');
        pt(-x);
    }else if(x>=10){
        pt(x/10);
        putchar((x%10)+'0');
    }else{
        putchar(x+'0');
    }
    return;
}
struct c{
    int d,v,a;
}car[200010];
pair<int,int>ct[200010];
float lim[200010];
int bd[200010];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int _=rd();
    while(_--){
        int n=rd(),m=rd(),l=rd();
        float v=rd();
        for(int i=1;i<=n;i++){
            int d=rd(),v=rd(),a=rd();
            car[i]=(c){d,v,a};
        }
        for(int i=1;i<=m;i++)lim[i]=rd();
        int ans=0;
        for(int i=1;i<=n;i++){
            if(car[i].a<0){
                int l1=1,r1=m;
                while(l1<r1){
                    int mid=(l1+r1)>>1;
                    int ll=l1,rr=r1;
                    if(lim[mid]<car[i].d)l1=mid+1;
                    else r1=mid;
                    if(ll==l1&&rr==r1)break;
                }
                while(lim[l1]<car[i].d)l1++;
                while(lim[l1-1]>car[i].d)l1--;
                int l=l1,r=m;
                float dis1=((v*v)-(car[i].v*car[i].v))/(car[i].a*2);
                if(dis1<0){
                    continue;
                }
                while(l<r){
                    if(r-l+1<=500)break;
                    int mid=(l+r+1)>>1;
                    int ll=l,rr=r;
                    if((lim[mid]-car[i].d)>=dis1)r=mid-1;
                    else l=mid;
                    if(ll==l&&rr==r)break;
                }
                for(int j=r;j>=l;j--){
                    if(lim[j]-car[i].d<dis1){
                        ans++;
                        ct[ans]=make_pair(j,l1);
                        break;
                    }
                }
            }else if(car[i].a>0){
                int l1=1,r1=m;
                while(l1<r1){
                    int mid=(l1+r1)>>1;
                    int ll=l1,rr=r1;
                    if(lim[mid]<car[i].d)l1=mid+1;
                    else r1=mid;
                    if(ll==l1&&rr==r1)break;
                }
                while(lim[l1]<car[i].d)l1++;
                while(lim[l1-1]>car[i].d)l1--;
                int l=l1,r=m;
                float dis1=((v*v)-(car[i].v*car[i].v))/(car[i].a*2);
                if(dis1<0){
                    ans++;
                    ct[ans]=make_pair(m,1);
                    continue;
                }
                while(l<r){
                    if(r-l+1<=500)break;
                    int mid=(l+r+1)>>1;
                    int ll=l,rr=r;
                    if((lim[mid]-car[i].d)>dis1)r=mid;
                    else l=mid+1;
                    if(ll==l&&rr==r)break;
                }
                for(int j=l;j<=r;j++){
                    if(lim[j]-car[i].d>dis1){
                        ans++;
                        ct[ans]=make_pair(m,j);
                        break;
                    }
                }
            }else{
                if(car[i].v>v){
                    int l1=1,r1=m;
                    while(l1<r1){
                        int mid=(l1+r1)>>1;
                        int ll=l1,rr=r1;
                        if(lim[mid]<car[i].d)l1=mid+1;
                        else r1=mid;
                        if(ll==l1&&rr==r1)break;
                    }
                    while(lim[l1]<car[i].d)l1++;
                    while(lim[l1-1]>car[i].d)l1--;
                    ans++;
                    ct[ans]=make_pair(m,l1);
                }
            }
        }
        pt(ans);
        putchar(' ');
        if(ans==0){
            pt(m);
            putchar('\n');
        }
        sort(ct+1,ct+1+ans);
        int ri=ct[1].first;
        int ans2=1;
        for(int i=2;i<=ans;i++){
            if(ri<ct[i].second){
                ri=ct[i].first;
                ans2++;
            }
        }
        pt(m-ans2);
        putchar('\n');
    }
    return 0;
}
