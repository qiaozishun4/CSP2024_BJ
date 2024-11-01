#include<bits/stdc++.h>
using namespace std;
int n;
string a[101];
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=13;i++){
		int f=4;
		char c;
		if(i==1) c='A';
		else if(i>1 && i<10) c=(char)(i+'0');
		else if(i==10) c='T';
		else if(i==11) c='J';
		else if(i==12) c='Q';
		else c='K';
		string D="D";
		string C="C";
		string H="H";
		string S="S";
		D+=c;
		C+=c;
		H+=c;
		S+=c;
		//cout<<D<<" "<<C<<" "<<H<<" "<<S<<endl;
		for(int j=1;j<=n;j++){
			if(a[j]==D){
                f--;
                break;
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]==C){
                f--;
                break;
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]==H){
                f--;
                break;
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]==S){
                f--;
                break;
			}
		}
		ans+=f;
	}
	cout<<ans<<endl;
	return 0;
}
