#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll read(){
    ll k=0;char c=getchar();bool flag=1;
    while(!isdigit(c)){if(c=='-')flag=0;c=getchar();}
    while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
    if(flag)return k;else return -k;
}
char readc(){
    char c=getchar();
    while(!isgraph(c))c=getchar();
    return c;
}
string reads(){
    string s="";char c=getchar();
    while(!isgraph(c))c=getchar();
    while(isgraph(c)){s+=c;c=getchar();}
    return s;
}
const int N=1e5+10;
const int num[]={6,2,5,5,4,5,6,3,7,6};
const string pre[]={"108","188","200","208","288","688","888"};
int n,a[N],mi;
string ans;
void dfs(int x,int k,int len){
    if(len>=mi||k<0)return ;
    else if(!k){
        mi=len;
        ans="";
        for(int i=1;i<=len;++i)ans+=(char)(a[i]+'0');
        return ;
    }
    else if(k<2)return ;
    int p;
    if(x==1)p=1;
    else p=0;
    for(int i=p;i<10;++i){
        if(num[i]>k)continue;
        a[x]=i;
        dfs(x+1,k-num[i],len+1);
    }
    return ;
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        if(n<=1){
            puts("-1");
            continue;
        }
        if(n<15){
			mi=1e9;
			dfs(1,n,0);
			cout<<ans<<'\n';
		}
        else{
			int k=(n-15)%7;
			string ans=pre[k];
			for(int i=0;i<(int)ans.size();++i)n-=num[ans[i]-'0'];
			cout<<ans;
			for(int i=1;i<=n/7;++i)putchar('8');
			printf("\n");
		}
    }
    return 0;
}
//by 2c_s in luogu
