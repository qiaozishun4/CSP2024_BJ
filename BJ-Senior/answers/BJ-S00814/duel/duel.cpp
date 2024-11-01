#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;

struct Node{
	int cnt,atk,not_moved,alive;
};

int card[maxn],n,loc_monst[maxn];
bool vis[maxn];

vector<Node> cnt_monster;

bool operator< (const Node &x,const Node &y){
	return x.atk < y.atk;
}
bool operator== (const Node &x,const Node &y){
	return x.atk == y.atk;
}
bool operator> (const Node &x,const Node &y){
	return x.atk > y.atk;
}

inline void read(int &x){
	char c;
	x = 0;
	while(c=getchar()){
		if(c==' '||c=='\n'||c==EOF)break;
		x=(x<<3)+(x<<1)+c-'0';
	}
	return;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	read(n);
	for(int i=1;i<=n;i++){
		read(card[i]);
		if(!vis[card[i]]){
			vis[card[i]]=1;
			loc_monst[card[i]]=cnt_monster.size();
			cnt_monster.push_back({1,card[i],0,0});
		}
		else{
			cnt_monster[loc_monst[card[i]]].cnt++;
		}
	}
	
	for(int i=0;i<cnt_monster.size();i++) 
		cnt_monster[i].alive = cnt_monster[i].not_moved = cnt_monster[i].cnt;
	
	sort(cnt_monster.begin(),cnt_monster.end());
	
//	for(auto monst : cnt_monster)print_monst(monst);
	
	int Round = 0;
//	cout << cnt_monster.size() << endl;
	for(int i=0;i<cnt_monster.size();i++){
		for(int j=i+1;j<cnt_monster.size();j++){
//			Round++;
//			printf("In round %d:\n", Round);
			if(cnt_monster[i].alive >= cnt_monster[j].not_moved){
				cnt_monster[i].alive -= cnt_monster[j].not_moved;
				cnt_monster[j].not_moved=0;
//				print_monst(cnt_monster[i]);
//				print_monst(cnt_monster[j]);
			}
			else{
				cnt_monster[j].not_moved -= cnt_monster[i].alive;
				cnt_monster[i].alive=0;
//				print_monst(cnt_monster[i]);
//				print_monst(cnt_monster[j]);
				break;
			}
		}
	}
	int sum=0;
	for(auto monst : cnt_monster) sum+=monst.alive;
	cout << sum << endl;
	return 0;
}
