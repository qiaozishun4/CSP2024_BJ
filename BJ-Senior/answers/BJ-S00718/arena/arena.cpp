#include <iostream>
using namespace std;
bool File;
int main() {
	File = freopen("arena.in","r",stdin);
	File = freopen("arena.out","w",stdout);
	int x;
	cin >> x;
	while (x--) {
		cout << rand() % (rand() % (int)(1e5+7)) << endl;
	}
	return 0;
}