#include<bits/stdc++.h>
using namespace std;

string s[100];
int n,sum=52;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		bool flag=false;
		cin>>s[i];
        for(int j=1;j<i;j++){
            if(s[j]==s[i]){
                flag=true;
            }
        }
        if(!flag){
            sum--;
        }
	}
	cout<<sum;
	return 0;
}
