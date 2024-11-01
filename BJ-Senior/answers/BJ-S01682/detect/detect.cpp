#include<bits/stdc++.h>
using namespace std;
int t,n,m,len,ans,ans2;
double spd;
bool open[100001],need[100001];
unordered_map<int,int> mp;
vector<int> vct;
struct infor{
    int l,r;
    bool need;
    bool operator <(const infor x)const{
        return r<x.r||r==x.r&&l<x.l;
    }
}inf[100001];
struct segment_tree{
    int tree[4000040];
    void clr(){
        memset(tree,0,sizeof(tree));
    }
    void update(int g,int x,int left,int right,int index){
        if(g<left||right<g){
            return;
        }
        if(left==right&&right==g){
            tree[index]+=x;
            return;
        }
        int mid=(left+right)>>1;
        if(g<=mid){
            update(g,x,left,mid,index<<1);
        }
        else{
            update(g,x,mid+1,right,index<<1|1);
        }
        tree[index]=tree[index<<1]+tree[index<<1|1];
    }
    int srch(int gleft,int gright,int left,int right,int index){
        if(gright<left||right<gleft){
            return 0;
        }
        if(gleft<=left&&right<=gright){
            return tree[index];
        }
        int mid=(left+right)>>1;
        if(gright<=mid){
            return srch(gleft,gright,left,mid,index<<1);
        }
        if(gleft>mid){
            return srch(gleft,gright,mid+1,right,index<<1|1);
        }
        return srch(gleft,gright,left,mid,index<<1)+srch(gleft,gright,mid+1,right,index<<1|1);
    }
}tr;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        tr.clr();
        mp.clear();
        vct.clear();
        memset(open,0,sizeof(open));
        ans=0;
        scanf("%d %d %d %lf",&n,&m,&len,&spd);
        ans2=m;
        for(int i=1;i<=n;i++){
            int d;
            double a,v;
            scanf("%d %lf %lf",&d,&v,&a);
            if(a==0){
                if(v<=spd){
                    inf[i].l=inf[i].r=-1;
                }
                else{
                    inf[i].l=d;
                    inf[i].r=len;
                }
            }
            if(a>0){
                if(v<=spd){
                    double tmp=(spd*spd-v*v)/(2*a);//超速时行驶了多远
                    //printf("tmp %lf\n",tmp);
                    if(d+tmp<=len){
                        inf[i].l=d+((tmp==floor(tmp))?tmp+1:ceil(tmp));
                        inf[i].r=len;
                    }
                    else{
                        inf[i].l=inf[i].r=-1;
                    }
                }
                else{
                    inf[i].l=d;
                    inf[i].r=len;
                }
            }
            if(a<0){
                if(v<=spd){
                    inf[i].l=inf[i].r=-1;
                }
                else{
                    double tmp=(spd*spd-v*v)/(2*a);//不超速时行驶了多远
                    //printf("tmp %lf\n",tmp);
                    if(d+tmp<=len){
                        inf[i].l=d;
                        inf[i].r=d+((tmp==floor(tmp))?floor(tmp)-1:floor(tmp));
                    }
                    else{
                        inf[i].l=d;
                        inf[i].r=len;
                    }
                    //    printf("sssssssssssssssssssssss%d %lf\n",d,tmp);
                }
            }
            inf[i].l++;
            inf[i].r++;
            //printf("inf %d %d\n",inf[i].l,inf[i].r);
        }
        for(int i=1;i<=m;i++){
            int tmp;
            scanf("%d",&tmp);
            tr.update(tmp+1,1,1,len+1,1);
            mp[tmp+1]=i;
            vct.push_back(tmp+1);
        }
        for(int i=1;i<=n;i++){
            if(inf[i].l&&inf[i].r){
                int tmp=tr.srch(inf[i].l,inf[i].r,1,len+1,1);
                if(tmp){
                    ans++;
                    inf[i].need=true;
                    //printf("ans++ %d\n",i);
                }
                else{
                    inf[i].need=false;
                }
            }
            else{
                inf[i].need=false;
            }
        }
        sort(inf+1,inf+n+1);
        tr.clr();
        for(int i=1;i<=n;i++){
            if(/*inf[i].l&&inf[i].r&&*/inf[i].need==true&&!tr.srch(inf[i].l,inf[i].r,1,len+1,1)){
                int id=upper_bound(vct.begin(),vct.end(),inf[i].r)-vct.begin()-1;
                if(open[mp[vct[id]]]==false){
                    open[mp[vct[id]]]=true;
                    tr.update(vct[id],1,1,len+1,1);
                    ans2--;
                    //printf("open %d %d\n",mp[vct[id]],vct[id]);
                }
                //printf("interval %d %d\n",inf[i].l,inf[i].r);
            }
        }

        printf("%d %d\n",ans,ans2);
    }
    return 0;
}
