#include <bits/stdc++.h>
using namespace std;
char pi[150];
int a[150];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>pi[i];
	}
	int ans=52-n;
	for(int i=1;i<=n*2;i+=2){
		for(int j=i;j<=n*2;j+=2){
			if(pi[i]==pi[j]&&pi[i+1]==pi[j+1]&&a[j]==0&&i!=j){
				a[j]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}