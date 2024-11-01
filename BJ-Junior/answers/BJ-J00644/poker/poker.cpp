#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
char read(){
	char c='#';
	while(!((c>='A'&&c<='Z')||(c>='0'&&c<='9')))scanf("%c",&c);
	return c;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		char a,b;
		a=read();
		//cout<<1<<endl;
		b=read();
		//cout<<a<<" "<<b<<endl;
		mp[(a-'A')*1000+b]=1;
	}
	printf("%d",52-mp.size());
	return 0;
}
