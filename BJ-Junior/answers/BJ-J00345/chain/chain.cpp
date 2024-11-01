#include<bits/stdc++.h>
using namespace std;
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
template<typename A,typename...B>inline void rd(A&x,B&...y) {
    char ch;bool f=0;
    while(!isdigit(ch=getchar()))if(ch=='-')f=1;
    x=0;do{x=(x<<1)+(x<<3)+(ch^48);}while(isdigit(ch=getchar()));
    if(f)x=-x;
    if constexpr(sizeof...(y))rd(y...);
}
const int N=2e5+33,RN=100;/////////
int n,k,q,id[N],tot,s[N],L[N],R[N];
//bitset<N>f[RN+5],g[RN+5];
bool f[RN+5][N],g[RN+5][N];
int cnt1[N],cnt2[N];
struct Q{
    int r,c,i;bool ans;
}qry[N];
signed main() {
    file("chain.in","chain.out");
    // R* sum(L)
    int t;
    rd(t);
    while(t--) {
        rd(n,k,q);
        tot=0;
        fr(i,1,n) {
            int l;
            rd(l);
            L[i]=tot+1;
            fr(j,1,l) {
                tot++;
                rd(s[tot]);
                id[tot]=i;
            }
            R[i]=tot;
        }
        fr(i,1,q){
            rd(qry[i].r,qry[i].c);
            qry[i].i=i;
            qry[i].ans=0;
        }
        sort(qry+1,qry+q+1,[](Q a,Q b){
             return a.r<b.r;
             });
        int qi=1;
        fr(r,1,RN) {
            //tran f from r-1
            if(r==1) {
                fr(i,1,tot)f[r][i]=(s[i]==1);
            } else {
                fr(i,1,tot)cnt1[s[i]]+=g[r-1][i];
                fr(ii,1,n) {

                    fr(i,L[ii],R[ii])cnt2[s[i]]+=g[r-1][i];
                    fr(i,L[ii],R[ii]) {
                        f[r][i]=(cnt1[s[i]]-cnt2[s[i]]>=1);
                    }
                    fr(i,L[ii],R[ii])cnt2[s[i]]=0;
                }
                fr(i,1,tot)cnt1[s[i]]=0;
            }

            //tran g
            fr(ii,1,n) {
                int cnt=0;
                fr(i,L[ii],R[ii]){
                    g[r][i]=cnt;
                    cnt+=f[r][i];
                    if(L[ii]<=i-k+1)cnt-=f[r][i-k+1];
                }
            }
            fr(i,1,tot)cnt1[s[i]]+=g[r][i];
            while(qi<=q&&qry[qi].r==r){
                qry[qi].ans=cnt1[qry[qi].c];
                qi++;
            }
            fr(i,1,tot)cnt1[s[i]]=0;
            if(qi>q)break;
        }
        sort(qry+1,qry+q+1,[](Q a,Q b){return a.i<b.i;});
        fr(i,1,q){
            pt("%d\n",qry[i].ans);
        }
    }
    return 0;
}
