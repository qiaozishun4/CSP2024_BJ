#include<bits/stdc++.h>
using namespace std;
int n,a[114514],m,d,b[114514],nk,s=1,T;
char k[114514][20];
long long outp,nans,pre[20],qzh[214514];
struct nd{
    int mson,lson,r,st,val;
    long long qan;
    int L,R;
}tr[400004];
struct qus{
    long long c,id;
}q[114514];
bool cmp(qus x,qus y){
    return x.c<y.c;
}
int lg(int x){
    int p=1,ret=0;
    while(x>p){
        p*=2;
        ++ret;
    }
    return ret;
}
int lg2(int x){
    int p=1,ret=0;
    while(x>p){
        p*=2;
        ++ret;
    }
    return p;
}
int lg3(int x){
    int ret=s;
    x-=1;
    while(x){
        x/=2;
        ret/=2;
    }
    return ret;
}
void build(int l,int r,int dp,int x){
    tr[x].L=l,tr[x].R=r,tr[x].r=dp;
    if(l==r){
        tr[x].val=l;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,dp-1,x*2);
    build(mid+1,r,dp-1,x*2+1);
    tr[x].mson=x*2;
    tr[x].lson=x*2+1;
    if(tr[x].val){
        swap(tr[x].lson,tr[x].mson);
    }
}
void cl(int x){
    tr[x].val=-1;
    tr[x].st=0;
    tr[x].qan=qzh[tr[x].R]-qzh[tr[x].L-1];
    if(tr[x].R==0) return;
    cl(x*2);
    cl(x*2+1);
}
void ins(int x){
    tr[x].val=b[x-s+1];
    tr[x].st=1;
    int pj=x;
    while(pj!=0){
        int y=pj;
        pj/=2;
        if(tr[pj].val==1){
            break;
        }else if(tr[pj].st==-1){
            tr[pj].st=1;
            tr[pj].val=tr[y].val;
            tr[pj].qan=tr[y].qan;
        }else{
            if(tr[pj].mson==y){
                //cout<<tr[y].val;
                if(tr[y].st!=1){
                    tr[pj].st=-1;
                    tr[pj].qan=tr[y].qan+tr[tr[pj].lson].qan;

                }else if(tr[y].val>=tr[pj].r){
                    tr[pj].st=1;
                    tr[pj].val=tr[y].val;
                    tr[pj].qan=tr[y].qan;
                }else{
                    if(tr[tr[pj].lson].st!=1){
                        tr[pj].st=1;
                        tr[pj].val=tr[tr[pj].lson].val;
                        tr[pj].qan=tr[tr[pj].lson].qan;
                    }else{
                        tr[pj].st=-1;
                        tr[pj].qan=tr[tr[pj].lson].qan;
                    }
                }
            }else{
                tr[pj].st=2;
                tr[pj].qan=tr[y].qan+tr[tr[pj].mson].qan;
            }
        }
        //cout<<"TST:"<<pj<<" "<<tr[pj].qan<<" "<<tr[pj].st<<" "<<tr[y].val<<" "<<tr[pj].r<<"\n";
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%lld",&q[i].c);
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    d=lg(n);
    s=lg2(n);
    for(int i=d;i>0;--i){
        s/=2;
        for(int j=0;j<s;++j){
            char ch;
            cin>>ch;
            //cout<<ch<<"&";
            if(ch=='1'){
                tr[s+j].val=1;
            }
        }
        pre[i]=(s*3-1)*s/2;
    }
    s=lg2(n);
    for(int i=1;i<=s;++i) qzh[i]=qzh[i-1]+i;
    build(1,lg2(n),d,1);
    //predo
    scanf("%d",&T);
    while(T--){
        cl(1);
        nk=0,outp=0;
        int tmp[4];
        for(int i=0;i<4;++i){
            scanf("%d",&tmp[i]);
        }
        for(int i=1;i<=n;++i){
            b[i]=a[i]^tmp[i%4];
            //cout<<b[i]<<" ";
        }
        for(int i=1;i<=m;++i){
            for(int j=q[i-1].c+1;j<=q[i].c;++j){
                ins(s+j-1);
            }
            //cout<<(long long)tr[lg3(q[i].c)].qan<<" "<<q[i].id<<"\n";
            outp=((long long)q[i].id*tr[lg3(q[i].c)].qan)^outp;
        }
        printf("%lld\n",outp);
    }
    return 0;
}

