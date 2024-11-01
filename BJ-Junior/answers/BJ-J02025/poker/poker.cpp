#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string str[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n); cnt=52-n;
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(str[i]==str[j])
				cnt++;
	printf("%d",cnt);
	return 0;
}
