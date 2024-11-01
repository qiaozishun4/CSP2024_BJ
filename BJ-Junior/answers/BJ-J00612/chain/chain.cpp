#include <bits/stdc++.h>
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar((x % 10) + '0');
}
int T;
int n,m,q;
int l[200050];
bool dp[200050][105];
int deq[200050],top,ed;
pair <int,int> frm[200050][105];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> T;
	while (T--){
		vector <int> s[100050],tmp[100050];
		memset(dp,0,sizeof(dp));
		n = read(),m = read(),q = read();
		for (int i = 1;i <= n;i++){
			l[i] = read();
			for (int j = 1;j <= l[i];j++) s[i].push_back(read());
		}
		dp[1][0] = 1;
		frm[1][0] = make_pair(2,0);
		for (int i = 1;i <= 100;i++){
			for (int j = 1;j <= n;j++){
				top = 1,ed = 0;
				for (int k = 1;k < s[j].size();k++){
					while (deq[top] < k - m + 1 && ed >= top) top++;
					if (dp[s[j][k - 1]][i - 1] == 1 && (frm[s[j][k - 1]][i - 1].first > 1 || frm[s[j][k - 1]][i - 1].second != j)) deq[++ed] = k - 1;
					if (ed >= top){
						dp[s[j][k]][i] = 1;
						frm[s[j][k]][i].first++;
						if (frm[s[j][k]][i].first == 1) frm[s[j][k]][i].second = j;
					}
					else dp[s[j][k]][i] = 0;
				}
			}
		}
		while (q--){
			int x,y;
			x = read(),y = read();
			write(dp[y][x]);
			putchar('\n');
		}
	}
	return 0;
}