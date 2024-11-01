#include<bits/stdc++.h>
using namespace std;
map<string,int> pk;
int n,sum;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(!pk[s]){
			sum++;
			pk[s]++;
		}
	}
	printf("%d",52-sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
