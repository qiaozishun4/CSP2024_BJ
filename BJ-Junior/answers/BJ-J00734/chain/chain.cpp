/*
Ugh..... This is embarassing
I thought t4 would be easy math problem
but In reality it might be a dynamic programming or other stuff.
BUT I SLEPT FOR AN HOUR NOOOOOO
I shouldn't sleep at 2am today....

Welp maybe first I can write a BaoLi? I think so...
Then how many points I can get from this?
I don't want do calculations aaaaaaaaaa
maybe I'm going to sleep at Mc'Donalds after this contest ended
SO TIRED

S(i , j) <= 200009....
Hmmmmmm Sounds Interesting....?

Notice that dp[i][j] is only relevant to last....
Also , we notice that if the value i comes from 2 people, then it doesn't matter.

Wait  wut

Why the fak it is correct????

oh this is not correct

anyways I don't care
At least I make the cases correct lol

*/

#include <bits/stdc++.h>

using namespace std;

int T;
int n, k, q;
vector<int> cards[100009];
int S;
struct query{
	int round;
	int ends;
	bool res;
	int sequence;
};
query ql[100009];
bool dp[3][200009];
vector<int> from[200009];
int l[100009];
int rod = 0;
int nextrd;
int maxrd;
int cc;
int maxnum;
int firstfrom[200009];
bool flags[200009];

bool Compare(query a , query b){
	return a.round < b.round;
}

bool Compare2(query a , query b){
	return a.sequence < b.sequence;
}

int main(){
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out", "w" , stdout);
	
	cin >> T;
		
	while(T --){	
		
		cin >> n >> k >> q;
		
		for(int i = 1; i <= n; i ++){
			cin >> l[i];
			for(int j = 1; j <= l[i]; j ++){
				cin >> S;
				cards[i].push_back(S);
				maxnum = max(maxnum , S);
			}
		}
		
		for(int i = 1; i <= q; i ++){
			cin >> ql[i].round >> ql[i].ends;
			ql[i].sequence = i;
		}
		
		rod ++;
		
		memset(dp , 0 , sizeof(dp));
		
		for(int i = 1; i <= n; i ++){
			for(int j = 0; j < l[i]; j ++){
				if(cards[i][j] == 1){
					for(int p = j + 1; p <= min(l[i] - 1 , j + k - 1); p ++){
						dp[rod & 1][cards[i][p]] = true;
						from[cards[i][p]].push_back(i);	
					}
				}
			}
		}
		
		sort(ql + 1, ql + 1 + q, Compare);
		
		cc = 1;
		nextrd = ql[cc].round;
		maxrd = ql[q].round;		
		
		while(rod <= maxrd){
			while(rod == nextrd){
				ql[cc].res = dp[rod & 1][ql[cc].ends];
				cc ++;
				nextrd = ql[cc].round;
			}
			
			rod ++;
			
			memset(firstfrom , 0 , sizeof(firstfrom));
			memset(flags , false , sizeof(flags));
			
			for(int L = 1; L <= maxnum ; L++){
				if(dp[(rod + 1) & 1][L] == true){
					flags[L] = true;
					firstfrom[L] = from[L][0];
				}
				
				for(int i = 1; i < from[L].size(); i ++){
					if(from[L][i] != firstfrom[L]){
						flags[L] = false;
					}
				}
			}
			
			for(int L = 1; L <= maxnum ; L++){
				from[L].clear();
			}
			
			for(int L = 1; L <= maxnum; L++){
				if(dp[(rod + 1) & 1][L] == true){					
					for(int i = 1; i <= n; i ++){
						if(flags[L] && i == firstfrom[L]){
							continue;
						}else{
							for(int j = 0; j < l[i]; j ++){
								if(cards[i][j] == L){
									for(int p = j + 1; p <= min(l[i] - 1, j + k - 1); p ++){
										dp[rod & 1][cards[i][p]] = true;
										from[cards[i][p]].push_back(i);
									}		
								}
							}
						}
					}
					
				}
			}			
		}
		
		sort(ql + 1, ql + 1 + q, Compare2);
		
		for(int i = 1; i <= q; i ++){
			cout << ql[i].res << endl;
		}
	}
	return 0;
}