/*
Its me again. If you see a lot of description is BJ-J00743(Probably that number) Then its me again.
I will not try to write anything about my oi journey as long as I can still write code.

Problem Solution:
We notice that Every time, each monster can ONLY fight ONCE with the other monster
Thus, we are sure that greedy algorithm can solve this, by using monster from small to larger
Attacking from smallest to larger (without same health)

Hopefully this is the correct solution!

By the way Im an arcaea player.
**WE MAKE THE GROUND SHAKE**

PROBLEM SOLVED! USED TIME : 16 MINUTES
ESTIMATED POINT GET: 100
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int attacks[100009];
int r;
int res;

bool Compare(int a , int b){
	return a < b;
}

int main(){
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);

	cin >> n;

	memset(attacks, 0 , sizeof(attacks));

	for(int i = 1; i <= n; i ++){
		cin >> attacks[i];
	}
	
	sort(attacks + 1 , attacks + 1 + n , Compare);
	
//	for(int i = 0; i < data.size(); i ++){
//		cout << data[i].key << ' ' << data[i].value << endl;
//	}
	
	int l = 1;
	
	for(int i = 2; i <= n; i ++){
		if(i != l && attacks[i] > attacks[l]){
			attacks[l] = 0;
			l ++;
		}
	}
	
	for(int i = 1; i <= n; i ++){
		if(attacks[i] != 0){
			res ++;
		}
	}
	
	cout << res << endl;
	
	return 0;

}