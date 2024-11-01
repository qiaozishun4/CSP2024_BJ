#include<bits/stdc++.h>
using namespace std;
char hs[4]={'D','C','H','S'};
char sz[15]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool hav[128][128];
int n;
int ans=0;
char s[10];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		//char a,b;
		scanf("%s",&s[0]);
		//cout<<s[0]<<s[1]<<endl;
		hav[int(s[0])][int(s[1])]=1;
	}
	
	for (int i=0;i<4;i++){
		for (int j=0;j<13;j++){
			ans+=!(hav[int(hs[i])][int(sz[j])]);
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}
