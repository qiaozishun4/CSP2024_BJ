#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, r[N];
bool cmp(int x, int y){
	return x < y;
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
	sort(r + 1, r + n + 1, cmp);
	int j = 1;
	for(int i = 2; i <= n; i++) if(r[i] > r[j]) j++;
	printf("%d", n - j + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}