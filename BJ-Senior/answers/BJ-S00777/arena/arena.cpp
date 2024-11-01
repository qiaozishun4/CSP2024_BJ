#include <iostream>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool local = 0;

int playerNum, queryNum, fullPlayerNumTime;
vector<int> a_s;
vector<int> as;
vector<int> Xs(4);
vector<int> queries;
vector<int> rands;

struct Player {
	int id;
	int power;
	Player(int id, int power): id(id), power(power) {};
	
	bool operator < (Player b) {return power < b.power;};
};

struct State {
	vector<Player*> sits;
	State() {};
	State(Player* player) {sits.push_back(player);}
};

void read() {
	cin >> playerNum >> queryNum;
	fullPlayerNumTime = floor(log2(playerNum - 1)) + 1;
	a_s = vector<int>(playerNum);
	as = vector<int>(a_s);
	queries = vector<int>(queryNum);
	rands = vector<int>(fullPlayerNumTime);

	for (int i = 0; i < playerNum; i++) cin >> a_s.at(i);
	for (int i = 0; i < queryNum; i++) cin >> queries.at(i);
	for (int i = 0; i < fullPlayerNumTime; i++) cin >> rands.at(i);
}

int f(int n) {
	if (n == 1) return 0;
	else return floor(log2(n - 1)) + 1;
}

void solve() {
	for (int i = 0; i < playerNum; i++) {
		as.at(i) = a_s.at(i) ^ Xs.at(i % 4);
	}
	vector<int> anss;
	for (int query: queries) {
		vector<State*> games;
		for (int i = 0; i < pow(2, f(query)); i++) {
			if (i < playerNum) games.push_back(new State(new Player(i, as.at(i))));
			else games.push_back(new State(new Player(i, -1)));
		}
		// for (State* game: games) cout << game->sits[0]->id << ' '; cout << "\n#\n";
		int ans = 0;
		while (games.size() > 1) {
			vector<State*> newGames;
			for (int i = 0; i * 2 < games.size(); i++) {
				 int r = rands.at(fullPlayerNumTime - log2(games.size())) & (1l << i);
				 State newState;
				 int amin = INT_MAX, amax = -1, bmin = INT_MAX, bmax = -1;
				 for (Player* p: games.at(i)->sits) {
					amin = min(amin, p->power);
					amax = max(amax, p->power);
				 }
				 for (Player* p: games.at(i * 2 + 1)->sits) {
					bmin = min(bmin, p->power);
					bmax = max(bmax, p->power);
				 }
				 for (Player* player: games.at(i)->sits) {
					if (player->power >= fullPlayerNumTime - log2(games.size()) + 1) {
						if (r && player->power >= bmin) {
							newState.sits.push_back(player);	
						} else if (player->power <= bmax) {
							newState.sits.push_back(player);	
						}
					}
				 }
				 for (Player* player: games.at(i * 2 + 1)->sits) {
					if (player->power >= fullPlayerNumTime - log2(games.size()) + 1) {
						if (r && player->power >= amin) {
							newState.sits.push_back(player);	
						} else if (player->power <= amax) {
							newState.sits.push_back(player);	
						}
					}
				 }
				 newGames.push_back(&newState);
			}
			games = newGames;
		}
		for (Player* player: games[0]->sits) ans += player->id + 1; 
		anss.push_back(ans);
	}
	int fin = anss[0];
	for (int i = 1; i < anss.size(); i++) {
		fin ^= (anss[i] * i);
	}
	cout << fin << '\n';
}

int main() {
    FILE* _;
    if (!local) {
        _ = freopen("arena.in", "r", stdin);
        _ = freopen("arena.out", "w", stdout);
    } else _ = freopen("arena1.in", "r", stdin);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

	read();

	int testNum;
	cin >> testNum;
	for (int _ = 0; _ < testNum; _++) {
		for (int i = 0; i < 4; i++) cin >> Xs.at(i);
		solve();
	}
}
