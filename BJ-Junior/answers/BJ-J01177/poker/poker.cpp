#include<string>
#include<iostream>
#include<map>
using namespace std;
string p[100],s[100];
map<string,bool> m;
int cnt,n,ans;
string f1[10]={" ","D","C","H","S"},f2[100]={" ","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			p[++cnt]=f1[i]+f2[j];
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		m[s[i]]=true;
	}
	for(int i=1;i<=52;i++){
		if(m[p[i]]==0){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}