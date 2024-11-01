#include<bits/stdc++.h>
using namespace std;
int n,cnt,book[52];
string s[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		int flag=0;
		for(int j=0;j<i;j++)
			if(s[j]==s[i])
				flag=1;
		if(flag==0)book[i]=1;
	}
	for(int i=0;i<n;i++){
		if(book[i]==1)
			cnt++;
	}
	if(cnt>52)cout<<0;
	else printf("%d",52-cnt);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
