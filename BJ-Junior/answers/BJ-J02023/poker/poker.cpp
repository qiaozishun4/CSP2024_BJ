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
map<string,bool>mp;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int T=read();
    while(T--)mp[reads()]=1;
    cout<<52-(int)mp.size()<<'\n';
    return 0;
}
//by 2c_s in luogu
