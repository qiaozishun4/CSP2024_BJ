#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5+5;
bool File;
struct mon {
	int x = 0,y = 0;//y +=> x
}a[N];
priority_queue<int> b,c;//c +=> b
int n,cnt = 0,x,y;
int main() {
	File = freopen("duel.in","r",stdin);
	File = freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x;
		if (a[x].x == 0) {
			b.push(-x);
			c.push(-x);
		}
		a[x].x++;
		a[x].y++;
	}
	//cout << a[1].x << endl;
	while (!c.empty()) {
		x = -b.top();
		b.pop();
		y = -c.top();
		c.pop();
		//x<y
		//cout << x << ' ' << y << endl;
		while (y <= x && !c.empty()) {
			y = -c.top();
			c.pop();
			//cout << y << endl;
		}/*
		if (c.empty()) {
			cout << ".~<|=+" << endl;
			cout << cnt << ' ' << n - cnt << endl;
		}*/
		//cout << x << "<=+" << y << ' ';
		if (a[y].y != 0) {
			a[y].y--;
		}
		if (a[y].y != 0) {
			c.push(-y);
		}
		if (a[x].x != 0) {
			a[x].x--;
		}
		if (a[x].x != 0) {
			b.push(-x);
		}
		if (y > x) {
			cnt++;
		}
		//cout << b.size() << ' ' << c.size() << ' ' << cnt << endl;
	}
	cout << /*cnt << ' ' << */n - cnt << endl;/*
	if (c.empty()) {
		cout << cnt << endl;
	} else {
		cout << n - cnt << endl;
	}*/
	return 0;
}