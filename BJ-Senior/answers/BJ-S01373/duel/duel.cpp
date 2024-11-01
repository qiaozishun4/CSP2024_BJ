#include<bits/stdc++.h>
using namespace std;
int n;
int b[1000030],qwe[1000003],idx;
int cnt1=0,cnt2=0;
struct node{
	int id;
	bool f,g;
}a[100001];
bool cmp(node x,node y){
	return x.id<y.id;
}
void s1(){
	int cnt;
	cnt=n;
	for(int i=1;i<=n;i++){
		a[i].id=b[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j].id>a[i].id&&a[i].f==0&&a[j].g==0){
				a[i].f=1;
				a[j].g=1;
				cnt--;
				break;
			}
		}
	}
	cout<<cnt;	
	exit(0);
}
void s3();
void s2(int n){
	for(int i=1;i<=n;i++){
		if(b[i]==1)cnt1++;
		if(b[i]==2)cnt2++;
	}
	if(cnt1+cnt2!=n)s3();
	else cout<<max(cnt1,cnt2);
}
void s3(){
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i]+1){
			cout<<i-1;
			exit(0);
		}
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	if(n<=1000){
		s1();
	}
	else{
		s2(n);
	}
	return 0;
}
