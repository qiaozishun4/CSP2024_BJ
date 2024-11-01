#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
long long t,n,m,l,v,dd,vv,aa,mx,s,p[100005],arr[100005],ll,rr,sum,last_max,_last;
vector<pair<size_t,size_t>> ori,ufin;
void add1(size_t inp){
    if(inp<=l) ori.push_back({inp,l});
}
void add2(size_t vv,size_t dd){
    if(vv>v) ori.push_back({dd,l});
}
void add3(size_t inp1,size_t inp2){
    if(inp1<=inp2) ori.push_back({inp1,min(l,(long long)inp2)});
}
void print(vector<pair<size_t,size_t>>& vec){
    for(size_t i=0;i<vec.size();i++){
        cout<<i<<':'<<vec[i].first<<' '<<vec[i].second<<endl;
    }
}
bool cmp(const pair<size_t,size_t>& v1,const pair<size_t,size_t>& v2){
    return v1.second-v1.first<v2.second-v2.first;//counts the same r-l as the same value
}
//下面是线段树
struct node{
    size_t l,r;
    long long mn=LLONG_MAX,mp=0;
}tree[400005];
void pushup(size_t pos){
    if(tree[pos].l!=tree[pos].r){
        tree[pos].mn=min(tree[pos<<1].mn,tree[pos<<1|1].mn);
        if(tree[pos].mn==tree[pos<<1].mn) tree[pos].mp=tree[pos<<1].mp;
        else tree[pos].mp=tree[pos<<1|1].mp;
    }
}
void init(size_t l,size_t r,size_t pos){
    tree[pos].l=l,tree[pos].r=r,tree[pos].mn=LLONG_MAX;
    if(l==r){tree[pos].mp=l;return;}
    size_t mid=l+r>>1;
    init(l,mid,pos<<1);
    init(mid+1,r,pos<<1|1);
    tree[pos].mp=l;
}
void change(size_t pp,size_t val,size_t pos){
    if(tree[pos].l==tree[pos].r){tree[pos].mn=val;return;}
    if(pp<=tree[pos<<1].r) change(pp,val,pos<<1);
    else change(pp,val,pos<<1|1);
    pushup(pos);
}
void _cmp_change(pair<size_t,long long>& v1,pair<size_t,long long> v2){
    if(v1.second>v2.second){
        v1=v2;
    }
}
pair<size_t,long long> check(size_t l,size_t r,size_t pos){
    if(tree[pos].l>=l&&tree[pos].r<=r){return {tree[pos].mp,tree[pos].mn};}
    pair<size_t,long long> ans{l,LLONG_MAX};
    if(l<=tree[pos<<1].r) _cmp_change(ans,check(l,r,pos<<1));
    if(r>=tree[pos<<1|1].l) _cmp_change(ans,check(l,r,pos<<1|1));
    return ans;
}
//线段树结束
pair<size_t,long long> pans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        ori.clear(),ufin.clear();
        cin>>n>>m>>l>>v;
        for(size_t i=1;i<=n;i++){
            cin>>dd>>vv>>aa;
            if(aa>0) add1(max(((v*v-vv*vv)/aa/2)+1,(long long)0)+dd);
            else if(aa==0) add2(vv,dd);
            else add3(dd,(v*v-vv*vv)/aa/2-((v*v-vv*vv)%(aa*2)==0)+dd);
        }
        for(size_t i=1;i<=m;i++) cin>>p[i];
        for(size_t i=0,ed=ori.size();i<ed;i++){
            ll=lower_bound(p+1,p+m+1,ori[i].first)-p;
            rr=upper_bound(p+1,p+m+1,ori[i].second)-p-1;
            if(ll>0&&rr<=m&&ll<=rr) ufin.push_back({ll,rr});
        }
        sort(ufin.begin(),ufin.end(),cmp);

        //print(ufin);

        init(1,m,1);
        for(size_t i=1;i<=m;i++)
            arr[i]=LLONG_MAX;
        for(size_t i=0,ed=ufin.size();i<ed;i++){
            pans=check(ufin[i].first,ufin[i].second,1);
            if(pans.second>ufin[i].second)
                change(ufin[i].first,ufin[i].second,1),arr[ufin[i].first]=ufin[i].second;
        }
        arr[m+1]=m+1;
        sum=0,last_max=0,_last=1;
        for(size_t i=1;i<=m+1;i++){
            if(arr[i]!=LLONG_MAX){
                if(i>last_max){
                    if(!_last) sum--;
                    _last=true;
                }
                else _last=false;
                sum++;
                last_max=arr[i];
                //cout<<"IN"<<i<<' '<<arr[i]<<' '<<sum<<' '<<_last<<endl;
            }
        }
        cout<<ufin.size()<<' '<<m-sum+1<<endl;
    }
    return 0;
}
