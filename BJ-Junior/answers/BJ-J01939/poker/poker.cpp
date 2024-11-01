#include<bits/stdc++.h>
using namespace std;

bool seen[800][800];
string arx;
string ary;
int N;

void scan(){
	scanf("%d\n",&N);
	for(int i = 0;i < N;i++){
		char a,b;
		scanf("%c%c\n",&a,&b);
		seen[int(a)][int(b)] = true;
	}
}

void ans(){
	int ans = 0;

	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 13;j++){
			if(! seen[ int(arx[i]) ][ int(ary[j]) ]){
				ans++;
			}
		}
	}

	printf("%d",ans);
}

int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	arx = "DCHS";
	ary = "A23456789TJQK";

	scan();
	ans();

	return 0;
}