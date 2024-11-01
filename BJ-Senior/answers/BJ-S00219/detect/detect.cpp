#include<bits/stdc++.h>
using namespace std;
struct che{
    int l,r;
    bool a=true;
    bool s=true;
}c[3005];
struct she{
    int w,c[3005],top=0;
}s[3005];

bool cmp(she a, she b){
    //if(a.top!=b.top) return a.top>b.top;
    int c1=0, c2=0;
    for(int i=0;i<a.top;i++){
        if(c[a.c[i]].s)c1++;
    }
    for(int i=0;i<b.top;i++){
        if(c[b.c[i]].s)c2++;
    }return c1>c2;
}
int main(){
    freopen("detect.in","r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int n,m,L,V,cnt=0,cnt2=0;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i=0;i<n;i++){
            int d,v,a;
            scanf("%d%d%d", &d,&v,&a);
            c[i].a=true,c[i].s=true;
            if(a==0){
                if(v>V){c[i].l=d,c[i].r=L;}
                else c[i].a=false;
            }if(a>0){
                int b=(V*V-v*v)/2/a;
                if(b<0)c[i].l=d,c[i].r=L;
                if(b>=0){
                    c[i].l=d+b,c[i].r=L;
                    if((V*V-v*v)%(2*a)==0)c[i].l++;
                }
            }if(a<0){
                if(V>=v)c[i].a=false;
                if(V<v){
                    int b=(V*V-v*v)/2/a;
                    c[i].l=d,c[i].r=d+b;
                    if((V*V-v*v)%(2*a)==0)c[i].r--;
                }
            }
        }for(int i=0;i<m;i++){
            int p;
            scanf("%d", &p);
            s[i].w=p;
            s[i].top=0;
            for(int j=0;j<n;j++)if(c[j].l<=p&&p<=c[j].r&&c[j].a)s[i].c[s[i].top++]=j;
        }
        int old_top=-1;
        for(int i=0;i<m;i++){
            if(old_top!=s[i].top){
                sort(&s[i], &s[m],cmp);
            }
            bool b=true;
            for(int j=0;j<s[i].top;j++){
                //cout <<c[s[i].c[j]].s << " " << s[i].c[j]<<'\n';
                if(c[s[i].c[j]].s)c[s[i].c[j]].s=false,cnt++,b=false;
            }
            //cout << s[i].w <<'\n';
            if(b)cnt2++;
        }//printf("%d %d\n\n\n", cnt, cnt2);
        printf("%d %d\n", cnt, cnt2);
    }
}
