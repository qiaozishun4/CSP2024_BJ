#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >>x;
	string a;
	string b;
	for(int i = 0;i < x;i ++){
		cin >>a;
		if(b.find(a) == -1){
			b = b + a + ' ';
		}
	}
	cout<<52 - b.size() / 3<<endl;
	return 0;
}
