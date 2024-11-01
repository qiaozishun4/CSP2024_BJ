#include<bits/stdc++.h>
using namespace std;
long long n;
long long r[10000010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int num=n;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(r[i]>r[j]&&r[j]!=0){
				r[j]=0;
				num--;
				i+=2;
			}
		}
	}
	cout<<num-1;
	fclose(stdin);
	fclose(stdout);
}

