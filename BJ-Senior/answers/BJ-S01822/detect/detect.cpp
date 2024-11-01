#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll T,n,m,len,lim,tot,ans,num,num2,p[N],sum[N],e[N],ed[N];
struct node{
  int l,r;
  node(int l=0,int r=0):l(l),r(r){}
}t[N];
vector<int>st[N];
void init(){
  tot=num=num2=0;
  for(int i=0;i<=len;++i)sum[i]=ed[i]=0,st[i].clear();
}
int main(){
  freopen("detect.in","r",stdin);
  freopen("detect.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--){
    cin>>n>>m>>len>>lim;
    init();
    for(int i=1;i<=n;++i){
      ll d,v,a;cin>>d>>v>>a;
      if(v<=lim&&a<=0)continue;
      if(v>lim&&a>=0)t[++tot]=node(d,len);
      else{
        ll tmp=lim*lim-v*v+2*a*d,tmp_up,tmp_dn;
        if(tmp%(2*a)==0)tmp_up=tmp/(2*a)+1,tmp_dn=tmp/(2*a)-1;
        else tmp_up=tmp/(2*a)+1,tmp_dn=tmp/(2*a);
        if(v<=lim&&a>0){
          if(tmp_up<=len){
            t[++tot]=node(tmp_up,len);
          }
        }else if(v>lim&&a<0)t[++tot]=node(d,min(tmp_dn,len));
      }
    }
    for(int i=1;i<=m;++i){cin>>p[i];++sum[p[i]];}
    for(int i=1;i<=len;++i)sum[i]+=sum[i-1];
    for(int i=1;i<=tot;++i){
      int tmp=sum[t[i].r];
      if(t[i].l-1>=0)tmp-=sum[t[i].l-1];
      if(tmp){
        ++num;
        st[t[i].l].push_back(i);
        ++ed[t[i].r];
      }
    }
    int lst=0,cur=0,head=1;
    for(int i=0;i<=len;++i){
      int tmp=sum[i];
      if(i)tmp-=sum[i-1];
      if(tmp)lst=i;
      for(int j=0;j<st[i].size();++j){
        int id=st[i][j];
        e[++cur]=id;
      }
      if(!ed[i])continue;
      ++num2;
      while(head<=cur&&t[e[head]].l<=lst){
        --ed[t[e[head]].r];
        ++head;
      }
    }
    cout<<num<<" "<<m-num2<<endl;
  }
  return 0;
}
