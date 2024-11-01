/*
莫名其妙想起了 icpc wf24，为什么有人这么菜？？？
如果有人讨厌浮点数运算的话，不等式记得乘负数要变号哦/cf
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
int p[100001],d[100001],v[100001],a[100001];
int f[100001],q[100001];
struct Seg{
    int l,r;
    bool operator<(const Seg&o)const{return r<o.r;}
}seg[100001];
void work(){
    int n,m,L,V;
    scanf("%d%d%d%d",&n,&m,&L,&V);
    for(int i=1;i<=n;++i)scanf("%d%d%d",d+i,v+i,a+i);
    for(int i=1;i<=m;++i)scanf("%d",p+i);
    int t=0;
    for(int i=1;i<=n;++i){
        int l,r;
        if(a[i]>0){
            if(v[i]>V)l=d[i],r=L;
            else{
                l=(V+v[i])*(V-v[i])/(2*a[i])+d[i]+1,r=L;
                if(l>r)continue;
            }
        }else if(a[i]<0){
            if(v[i]<=V)continue;
            else{
                l=d[i],r=((V+v[i])*(v[i]-V)-1)/(-2*a[i])+d[i];
                if(r>L)r=L;
            }
        }else if(v[i]>V)l=d[i],r=L;
        else continue;
        int l_=std::lower_bound(p+1,p+m+1,l)-p,r_=std::upper_bound(p+1,p+m+1,r)-p-1;
        if(l_<=m&&p[l_]<=r)seg[t++]={l_,r_};
    }
    std::sort(seg,seg+t);
    int fr=0,tl=1,j=0,lim=0;
    for(int i=1;i<=m;++i){
        for(;j<t&&seg[j].r<i;++j)lim=seg[j].l>lim?seg[j].l:lim;
        for(;fr<tl&&q[fr]<lim;++fr);
        f[i]=f[q[fr]]+1;
        for(;fr<tl&&f[q[tl-1]]>f[i];--tl);
        q[tl++]=i;
    }
    for(;j<t;++j)lim=seg[j].l>lim?seg[j].l:lim;
    for(;fr<tl&&q[fr]<lim;++fr);
    printf("%d %d\n",t,m-f[q[fr]]);
}
int main(){
    freopen("detect.in","r",stdin),freopen("detect.out","w",stdout);
    int t;
    for(scanf("%d",&t);t--;work());
    return 0;
}