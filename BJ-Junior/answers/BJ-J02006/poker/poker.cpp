#include<bits/stdc++.h>
using namespace std;
int D[20];
int C[20];
int H[20];
int S[20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n ;
	cin >> n ;
	while(n--){
		char x , y ;
		cin >> x >> y ;
		if(x=='D'){
			if(isdigit(y)){
				D[y-48]++;
			}
			else if(y=='A'){
				D[1]++;
			}
			if(y=='T'){
				D[10]++;
			}
			if(y=='J'){
				D[11]++;
			}
			if(y=='Q'){
				D[12]++;
			}
			if(y=='K'){
				D[13]++;
			}
		}
		if(x=='C'){
			if(isdigit(y)){
				C[y-48]++;
			}
			else if(y=='A'){
				C[1]++;
			}
			if(y=='T'){
				C[10]++;
			}
			if(y=='J'){
				C[11]++;
			}
			if(y=='Q'){
				C[12]++;
			}
			if(y=='K'){
				C[13]++;
			}
		}
		if(x=='H'){
			if(isdigit(y)){
				H[y-48]++;
			}
			else if(y=='A'){
				H[1]++;
			}
			if(y=='T'){
				H[10]++;
			}
			if(y=='J'){
				H[11]++;
			}
			if(y=='Q'){
				H[12]++;
			}
			if(y=='K'){
				H[13]++;
			}
		}
		if(x=='S'){
			if(isdigit(y)){
				S[y-48]++;
			}
			else if(y=='A'){
				S[1]++;
			}
			if(y=='T'){
				S[10]++;
			}
			if(y=='J'){
				S[11]++;
			}
			if(y=='Q'){
				S[12]++;
			}
			if(y=='K'){
				S[13]++;
			}
		}
	}
	int cnt = 0 ;
	for(int i = 1 ; i <= 13 ; i++){
		if(!D[i]){
			cnt++;
		}
		if(!C[i]){
			cnt++;
		}
		if(!S[i]){
			cnt++;
		}
		if(!H[i]){
			cnt++;
		}
	}
	cout << cnt ;
	return 0 ;
}
