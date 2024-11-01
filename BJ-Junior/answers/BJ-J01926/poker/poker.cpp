#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

using namespace std;

bool pokersp[4][13];

using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(pokersp,0,sizeof(pokersp));
	int n,ans=52;
	cin>>n;
	while(n--){
		string pok;
		cin>>pok;
		int x1,x2;
		if(pok[0]=='D')x1=0;
		else if(pok[0]=='C')x1=1;
		else if(pok[0]=='H')x1=2;
		else if(pok[0]=='S')x1=3;
		if(pok[1]>='2' && pok[1]<='9')x2=pok[1]-'0';
		else if(pok[1]=='A')x2=1;
		else if(pok[1]=='T')x2=10;
		else if(pok[1]=='J')x2=11;
		else if(pok[1]=='Q')x2=12;
		else if(pok[1]=='K')x2=13;
		if(pokersp[x1][x2-1]!=1){
			pokersp[x1][x2-1]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
