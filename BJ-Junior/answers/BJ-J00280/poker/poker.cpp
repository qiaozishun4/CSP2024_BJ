#include<bits/stdc++.h>
using namespace std;
map<char,char> md,mc,mh,ms;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=52;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D') md[s[1]]=s[1];
		else if(s[0]=='C') mc[s[1]]=s[1];
		else if(s[0]=='H') mh[s[1]]=s[1];
		else if(s[0]=='S') ms[s[1]]=s[1];
	}
	for(map<char,char>::iterator it=md.begin();it!=md.end();it++) cnt--;
	for(map<char,char>::iterator it=mc.begin();it!=mc.end();it++) cnt--;
	for(map<char,char>::iterator it=mh.begin();it!=mh.end();it++) cnt--;
	for(map<char,char>::iterator it=ms.begin();it!=ms.end();it++) cnt--;
	printf("%d",cnt);
	return 0;
}
