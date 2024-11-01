#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> v,a;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		v.push_back(x);
		a.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	sort(a.begin(),a.end(),cmp);
	while(int(v.size())>0){
		x=lower_bound(v.begin(),v.end(),a[0]+1)-v.begin();
	//	cout<<x<<' '<<a[0]<<' '<<v[x]<<endl;
		if(x>=int(v.size())||v[x]<=a[0]){
			break;
		}
		else{
			v.erase(v.begin()+x);
			a.erase(a.begin());
		}
	/*	for(int i=0;i<int(v.size());i++) cout<<v[i]<<' ';
		cout<<endl;
		for(int i=0;i<int(a.size());i++) cout<<a[i]<<' ';
		cout<<endl<<endl;*/
	}
	printf("%d",int(a.size()));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
