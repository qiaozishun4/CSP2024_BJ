#include<bits/stdc++.h>
using namespace std;

const int w=1e6;
const long long inf=1e12;

int t;
int n;
int a[200005];
long long dp[200005];

long long count(int l,int r){
	long long rt=0;
	for(int i=l+1;i<=r;++i){
		rt+=a[i]*(a[i-1]==a[i]);
	}
	return rt;
}

struct qqq{
	int l,r;
	long long add,sum;
}tr[4000005];

void upd(int id){
	tr[id].sum=max(tr[id<<1].sum+tr[id<<1].add,tr[(id<<1)|1].sum+tr[(id<<1)|1].add);
	return;
}

void push_down(int id){
	if(tr[id].add!=0){
		tr[id<<1].add+=tr[id].add;
		tr[(id<<1)|1].add+=tr[id].add;
		tr[id].sum+=tr[id].add;
		tr[id].add=0;
	}
	return;
}

void build_tree(int id,int L,int R){
	tr[id].l=L;
	tr[id].r=R;
	tr[id].add=0;
	tr[id].sum=-inf;
	if(L==R){
		return;
	}
	int mid=(L+R)>>1;
	build_tree(id<<1,L,mid);
	build_tree((id<<1)|1,mid+1,R);
	upd(id);
	return;
}

void add(int id,int L,int R,long long addx){
	if(tr[id].l==L && tr[id].r==R){
		tr[id].add+=addx;
		return;
	}
	push_down(id);
	if(R<=tr[id<<1].r){
		add(id<<1,L,R,addx);
	}
	else if(L>=tr[(id<<1)|1].l){
		add((id<<1)|1,L,R,addx);
	}
	else{
		add(id<<1,L,tr[id<<1].r,addx);
		add((id<<1)|1,tr[(id<<1)|1].l,R,addx);
	}
	upd(id);
	return;
}

void do_mx(int id,int X,long long numx){
	if(tr[id].l==X && tr[id].r==X){
		tr[id].sum+=tr[id].add;
		tr[id].add=0;
		tr[id].sum=max(tr[id].sum,numx);
		return;
	}
	push_down(id);
	if(X<=tr[id<<1].r){
		do_mx(id<<1,X,numx);
	}
	else{
		do_mx((id<<1)|1,X,numx);
	}
	upd(id);
	return;
}

long long query(int id,int L,int R){
	if(L>R){
		return -inf;
	}
	if(tr[id].l==L && tr[id].r==R){
		return tr[id].sum+tr[id].add;
	}
	push_down(id);
	if(R<=tr[id<<1].r){
		return query(id<<1,L,R);
	}
	else if(L>=tr[(id<<1)|1].l){
		return query((id<<1)|1,L,R);
	}
	else{
		return max(query(id<<1,L,tr[id<<1].r),query((id<<1)|1,tr[(id<<1)|1].l,R));
	}
	return -1;
}

void clearx(int id){
	tr[id].add=0;
	tr[id].sum=-inf;
	if(tr[id].l==tr[id].r){
		return;
	}
	clearx(id<<1);
	clearx((id<<1)|1);
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	build_tree(1,0,w);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		dp[1]=0;
		for(int i=2;i<=n+1;++i){
			if(i>=3){
				add(1,0,w,a[i-2]*(a[i-3]==a[i-2]));
				do_mx(1,a[i-3],dp[i-2]);
			}
			dp[i]=dp[i-1]+a[i]*(a[i-2]==a[i]);
			dp[i]=max(dp[i],max(max(query(1,0,a[i]-1),query(1,a[i]+1,w)),query(1,a[i],a[i])+a[i])+a[i-1]*(a[i-2]==a[i-1]));
			dp[i]=max(dp[i],max(max(query(1,0,a[i-1]-1),query(1,a[i-1]+1,w)),query(1,a[i-1],a[i-1])+a[i-1])+a[i]*(a[i-2]==a[i]));
			/*for(int j=i-2;j>=1;--j){
				dp[i]=max(dp[i],dp[j]+count(j,i-2)+a[i-1]*(a[i-2]==a[i-1])+a[i]*(a[j-1]==a[i]));
				dp[i]=max(dp[i],dp[j]+count(j,i-2)+a[i]*(a[i-2]==a[i])+a[i-1]*(a[j-1]==a[i-1]));
			}*/
			//add i-3,i-2 -> push i-2
		}
		cout<<dp[n+1]<<'\n';
		clearx(1);
	}
	return 0;
}
