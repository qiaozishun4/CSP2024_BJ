#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
//#define int long long
#define ull unsigned long long 
#define pii pair<int,int>
#define pk pop_back
#define pb push_back
#define fi first
#define se second
#define ll long long
#define WA cerr<<"meowww~\n";
#define WR(x) cerr<<x<<"\n";
#define C continue
#define pii pair<int,int>
#define INF
#define MAXN 100001
//const int MOD=
void Umn(int &x,int y) { if(x>y)x=y;return ; }
void Umx(int &x,int y) { if(x<y)x=y;return ; }
//void MD(int &x) { if(x<0)x+=MOD;if(x>MOD)x-=MOD;return ; }
int n; int a[MAXN];
int mx=0,tot=0; int bx[MAXN];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n; For(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	tot=n;mx=a[n];
	For(i,1,n) bx[a[i]]++; int lst=0;
	For(i,1,mx) { int tp=min(bx[i],lst);tot-=tp;lst+=(bx[i]-tp); }
	cout<<tot<<"\n";
	return 0;
}
//g++ T1.cpp -std=c++14 -o T1 -Wall -Wextra -fsanitize=undefined -fsanitize=address