#include <bits/stdc++.h>
using namespace std;

struct Car {
	int d, v0, a;
} car[100010];
int p[100010];

struct P {
	int id, num = 0;
};

unordered_set<int> newSet() {
	unordered_set<int> s;
	return s;
}

bool cmp(P p1, P p2) {
	return p1.num < p2.num;
}

double culMaxX(int v0, int a) {
	return -(double)v0 * v0 / 2 / a;
}

double culV(int v0, int a, int x) {
	return sqrt((double)v0 * v0 + 2 * a * x);
}

int T;
int n, m, L, V;

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T > 0) {
		int delectNum = 0, cutPointNum = 0;
		P points[100010];
		vector<int> lvePointNum;
		vector<unordered_set<int>> lvePoints;

		lvePoints.push_back(newSet());
		lvePointNum.push_back(0);
		
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++)
			cin >> car[i].d >> car[i].v0 >> car[i].a;
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
			points[i].id = i;
		}
		
		for (int i = 1; i <= n; i++) {
			Car curCar = car[i];
			int d = curCar.d, v0 = curCar.v0, a = curCar.a;
			double maxD = (a >= 0 ? L : d + culMaxX(v0, a));
			bool delected = false;
			for (int j = 1; j <= m; j++) {
				if (p[j] < d || p[j] > maxD) continue;
				int x = p[j] - d;
				double v = culV(v0, a, x);
				if (v > V) {
					if (!delected) {
						lvePointNum.push_back(0);
						lvePoints.push_back(newSet());
					}
					delected = true;
					points[j].num++;
					lvePointNum[delectNum + 1]++;
					lvePoints[delectNum + 1].insert(j);
				}
			}
			delectNum += delected;
		}
		
		sort(points + 1, points + m + 1, cmp);
		for(int i = 1; i <= m; i++) {
			P point = points[i];
			int id = point.id, num = point.num;
			if (num == 0) {
				cutPointNum++;
				continue;
			}
			
			bool flag = true;
			for(int j = 1; j <= delectNum; j++) {
				unordered_set<int> lvePoint = lvePoints[j];
				if (lvePoint.count(id) && lvePointNum[j] == 1)
					flag = false;
			}
			if (!flag) continue;
			
			cutPointNum++;
			for(int j = 1; j <= delectNum; j++) {
				unordered_set<int> lvePoint = lvePoints[j];
				if (lvePoint.count(id)) {
					lvePoint.erase(id);
					lvePointNum[j]--;
				}
			}
		}
		
		cout << delectNum << " " << cutPointNum << endl;
		T--;
	}
	return 0;
}
