//WELCOME TO CSP-J 2024.
//This is my 6th? or maybe 7th Idk year participating this event.
//Maybe I will write a lot of discription stuff idk just for fun
//This is my last year so.... Yeah.
//I don't care if they ban me from participating furthur contests.
//Good Luck.
//- Close your eyes -

#include <bits/stdc++.h>

using namespace std;

string s;
int cnt;
int n;
bool existPoker[9][25];

void TONUM(string s){
	int type = 0;
	int number = 0;
	if(s[0] == 'D'){
		type = 1;
	}else if(s[0] == 'C'){
		type = 2;
	}else if(s[0] == 'S'){
		type = 3;
	}else if(s[0] == 'H'){
		type = 4;
	}
		
	if(s[1] == 'T'){
		number = 10;
	}else if(s[1] == 'J'){
		number = 11;
	}else if(s[1] == 'Q'){
		number = 12;
	}else if(s[1] == 'A'){
		number = 1;
	}else if(s[1] == 'K'){
		number = 13;
	}else{
		number = (int)(s[1] - '0');
	}
	
	existPoker[type][number] = true;
	
}

int main(){
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
	
	memset(existPoker, 0, sizeof(existPoker));
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> s;
		TONUM(s);
	}
	
	for(int i = 1; i <= 4; i ++){
		for(int j = 1; j <= 13; j ++){
			if(existPoker[i][j] == false){
				cnt ++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}