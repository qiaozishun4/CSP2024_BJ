#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10,L = 1e6+10,V = 1e3+10;
int T;
int n,m,len,sp;
int d,v,a;
struct node{
    int l,r;
    int zh;
}che[N];
int k;
int ce[L];
bool cmp(node t1,node t2){
    if(t1.zh!=t2.zh)return t1.zh<t2.zh;
    else return t1.l<t2.l;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        k = 0;
        memset(ce,0,sizeof(ce));
        scanf("%d%d%d%d",&n,&m,&len,&sp);
        for(int i = 1;i<=n;i++){
            scanf("%d%d%d",&d,&v,&a);
            if(a==0){
                if(v>sp){
                    k++;
                    che[k].l = d;
                    che[k].r = len;
                    che[k].zh = 3;
                }
            }else if(a>0){
                int num = (long long)(sp*sp-v*v)/(2*a);
                if(num!=(double)((sp*sp-v*v)/(2*a))){
                    num++;
                }
                num = d+num+1;
                if(num<=len){
                    k++;
                    che[k].l = num;
                    che[k].r = len;
                    che[k].zh = 2;
                }
            }else if(a<0&&v>sp){
                int num = (sp*sp-v*v)/(2*a);
                if(num==(double)(sp*sp-v*v)/(double)(2*a)){
                    num--;
                }
                if(num>=0){
                    k++;
                    che[k].l = d;
                    che[k].r = d+num;
                    che[k].zh = 1;
                }
            }
        }
        sort(che+1,che+k+1,cmp);
        int p,maxp = 0;
        for(int i = 1;i<=m;i++){
            scanf("%d",&p);
            maxp = max(maxp,p);
            ce[p]++;
        }
        int res = 0;
        for(int i = 1;i<=len;i++)ce[i]+=ce[i-1];
        //for(int i = 0;i<=len;i++)cout<<ce[i]<<' ';
        int t = 1;
        while(che[t].zh==1){
            if(ce[che[t].r]-ce[che[t].l-1]>0){
                res++;
            }
            t++;
        }
        bool op = false;
        if(t>1){
            op = true;
        }
        while(t<=k){
            if(che[t].l<=maxp){
                res++;
            }else break;
            t++;
        }
        //cout<<k<<endl;
        if(res==0)m++;
        printf("%d %d\n",res,m-1);
    }

    return  0;
}
