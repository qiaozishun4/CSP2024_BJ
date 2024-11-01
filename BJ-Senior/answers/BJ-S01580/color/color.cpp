#include <iostream>
#include <cstdio>
#include <stack>
#include <string.h>
#include <map>

using namespace std;

long long AAA[10005],n,appear[2005];

long long DFS(int now,int redtop,int bluetop){
	if(now==n)return 0;
	if(AAA[now]==AAA[redtop] || AAA[now]==AAA[bluetop])return AAA[now]+DFS(now+1,redtop,bluetop);
	if(appear[AAA[redtop]]==1 && appear[AAA[now]]==1)return DFS(now+1,now,bluetop);
	if(appear[AAA[bluetop]]==1 && appear[AAA[now]]==1)return DFS(now+1,redtop,now);
	int atk=now+1;
	while(appear[AAA[atk]]==1)atk++;
	return max(DFS(atk,now,bluetop),DFS(atk,redtop,now));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(appear,0,sizeof(appear));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>AAA[i];
			if(AAA[i]<=2000)appear[AAA[i]]++;
		}
		cout<<DFS(1,0,-1)<<endl;
	}
	return 0;
}
