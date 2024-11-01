#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
int n,cnt=0,r[N];
int fl[N];
bool flag=true;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(fl,0,sizeof(fl));
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		if(r[i]>2) flag=false;
	}
	sort(r+1,r+n+1);
	if(flag==true){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(r[i]==1) cnt1++;
			else cnt2++;
		}
		cout<<n-min(cnt1,cnt2)<<endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[j]>r[i]&&fl[j]!=1&&fl[j]!=2&&fl[i]!=2){
				fl[j]=1;
				fl[i]=2;
				cnt-=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
