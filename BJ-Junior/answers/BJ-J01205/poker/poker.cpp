#include<bits/stdc++.h>
using namespace std;
struct note{
	char a,b;
	char x,y;
} e[60];
int n,len;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b;
		for(int j=1;j<=n;j++){
			if(e[j].x==e[i].a&&e[j].y==e[i].b)break;
			if(j==n){
				len+=1;
				e[len].x=e[i].a;
				e[len].y=e[i].b;
			}
		}
	}
	cout<<52-len;
	fclose(stdin);
	fclose(stdout);
	return 0;
}