#include<iostream>
using namespace std;
int n,ans;
string s[10000000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||s[i]=="0")
				continue;
			if(s[i]==s[j]){
				ans++;
				s[j]="0";
			}
		}
	}
	cout<<52-n+ans;
	return 0;
}