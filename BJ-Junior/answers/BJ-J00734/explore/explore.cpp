//Is this T2 difficulty??
//Everything seems so eazy...
//I don't feel well...
/*
I remember someone will do the
Idk , compilation of this kind of thing?
so maybe I need first some key words to like attract them >:)
AFO OI NOIP NOI CSP CSP-S CSP-J Arcaea Phigros Dynamix osu!mania
Thats enough maybe
Then I can write my opinion to OI >:)

Wait... Why I solved this in 10 minutes?
This can't be puji- difficulty
This is newbie diff
how Im scared about next few problems

ELLO GAYS TUDAY WE HAVE A TOP FIVE LIST OF ALGOLITHEMS (i know its algorithm on purpose believe me)
Numero Funf: DFS
Numero For: Dynamic-Programming
Numero Three: Segment tree
Numero Two: Shu Lian Pao Fen
Honorable Mention: CSP-S 2023 T3
Number One: Simulation

*/

#include <bits/stdc++.h>

using namespace std;

int T;
char mapp[1009][1009];
int n , m , k;
int xcord , ycord , direc;
int cnt;
int cx[5] = {0 , 1 , 0 , -1};
int cy[5] = {1 , 0 , -1 , 0};
bool visited[1009][1009];

bool isLegal(int xcor , int ycor){
	if(1 <= xcor && xcor <= n && 1 <= ycor && ycor <= m && mapp[xcor][ycor] == '.'){
		return true;
	}
	return false;
}

int main(){
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
		
	cin >> T;
	
	while(T --){
		memset(visited , 0 , sizeof(visited));
		cnt = 0;
		cin >> n >> m >> k;
		cin >> xcord >> ycord >> direc;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				cin >> mapp[i][j];
			}
		}
		
		visited[xcord][ycord] = true;
		
		for(int i = 1; i <= k; i ++){
			int curx = xcord + cx[direc];
			int cury = ycord + cy[direc];
			if(isLegal(curx , cury)){
				xcord = curx;
				ycord = cury;
				visited[xcord][ycord] = true;
			}else{
				direc = (direc + 1);
				direc %= 4;
			}
		}
		
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(visited[i][j] == true){
					cnt ++;				
				}
			}
		}
		cout << cnt << endl;
	}	

	return 0;
}