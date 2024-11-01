#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int w[]={6,2,5,5,4,5,6,3,7,6};//nums->stick counts
//             0 1 2 3 4 5 6 7 8 9
const int v[]={-1,-1,1,7,4,2,6,8,-1,-1};//stick counts->nums
//             0  1  2 3 4 5 6 7 8  9
//if there isn't have any nums for a stick counts, save -1
//if there are more than one num for a stick counts, save the min num
int T,n;
bool pianfenguoyangli(int n);
string s;
bool dfs(int x){
	if(x<=7){
		if(v[x]==-1)return false;
		s.push_back(v[x]+'0');
		return true;
	}
	if(x<=14){
		switch(x){
			case 8:s+="01";return true;//10
			case 9:s+="81";return true;//18
			case 10:s+="32";return true;//23
			case 11:s+="02";return true;//20
			case 12:s+="82";return true;//28
			case 13:s+="86";return true;//68
			case 14:s+="88";return true;//88
		}
	}
	for(int i=7;i>=2;i--){
		s.push_back(v[i]+'0');
		if(dfs(x-i))return true;
		else s.pop_back();
	}
	return false;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(pianfenguoyangli(n))continue;//A,B,n<=7
		s.clear();
		if(!dfs(n))puts("-1");
		else{
			reverse(s.begin(),s.end());
			cout<<s<<'\n';
		}
	}
    return 0;
}
//32 20888
//8  8  8  8 4
//25 18 11 4 0

//9
//8 1
//7 2

//10
//
//








bool pianfenguoyangli(int n){
	if(n<2){puts("-1");return true;}
	if(n<=7){
		cout<<v[n]<<'\n';
		return true;
	}
	else if(n%7==0){
		while(n){
			putchar('8');
			n-=7;
		}
		puts("");
		return true;
	}
	else if(n%7==1){
		putchar('1');
		putchar('0');
		n-=8;
		while(n){
			putchar('8');
			n-=7;
		}
		puts("");
		return true;
	}
	return false;
}