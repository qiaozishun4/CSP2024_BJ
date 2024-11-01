/*
Hello Its me again.
Well actually I have another name
henry_in_out
Search me on bilibili if you see this!

Well I believe this is a mathematical problem
Shi yi zhi ci, xian da biao ba!

oh wow this is more easier than I thought.
So cool!

This is what oi suppose to be in my opinion.
Not always f***ing graph problems.
We are high school students, not scholars.

Everyone go to hear Everlasting Eternity made by lucidin it is so good aaaaaaaaaaaaaaaaaaaaaaa

Alr Its 1.5 hours passed and 3 problems solved!
gg

AK Possible?????
*/


#include <bits/stdc++.h>

using namespace std;

int res[30] = {-1 , -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 22 , 20 , 28 , 68 , 88 , 108 , 188 , 200 , 208 , 288 , 688 , 888};
int T;
int n;

void ErFen(int n){
	string s = "8";
	string ret = "";
	while(n){
		if(n & 1){
			ret += s;	
		}
		s += s;
		n /= 2;
	}
	cout << ret << endl;
}

int main(){
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	
	cin >> T;
	while(T --){
		cin >> n;
		if(n <= 21){
			cout << res[n] << endl;
		}else{
			int curmod = n % 7;
			if(n % 7 == 0){
				curmod += 7;
			}
			curmod += 14;
			cout << res[curmod];
			n -= curmod;
			ErFen(n / 7);
		}
	}
	
	return 0;
}