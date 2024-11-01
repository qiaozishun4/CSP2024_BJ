// And in that light, I found deliverance.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define Cl(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
const int DC=1;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(a%=p;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n;
int nd[]={6,2,5,5,4,5,6,3,7,6};
void opt(int x){cout<<x;n-=nd[x];}

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n;
	if(n==1)return cout<<"-1\n",void();
	if(n==3)return cout<<"7\n",void();
	if(n==4)return cout<<"4\n",void();
	if(n%7==1)opt(1),opt(0);
	if(n%7==2)opt(1);
	if(n%7==3)opt(2),opt(2);
	if(n%7==4)opt(2),opt(0);
	if(n%7==5)opt(2);
	if(n%7==6)opt(6);
	while(n)opt(8);
	cout<<"\n";
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__();
	return 0;
}