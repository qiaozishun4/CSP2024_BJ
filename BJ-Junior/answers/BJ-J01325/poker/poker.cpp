#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s[70],t;
int main(){
	freopen("poker.in","r",stdin);
	 freopen("poker.out","w",stdout);
 	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>t;
		int f=1;
		for(int j=1;j<=sum;j++)if(t==s[j])f=0;
		//cout<<f<<' '<<sum<<endl;
		if(f)s[++sum]=t;
	}
	cout<<52-sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}