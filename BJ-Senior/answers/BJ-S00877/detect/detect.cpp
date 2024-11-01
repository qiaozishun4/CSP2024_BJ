#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define pref 0.00001
#define debug false
using namespace std;

// For the cars who has positive ai, we just need to test them in the very last sensor
// For the cars who has 0 ai, same with case 1;
// For the cars who has negetive ai. If it can't be tested out by the first sensor it meets, then no longer.
// So for the case 3, we need to calc the absolute position of the car where it downspeed to V
// Then, we can find a range that the sensor in this range must be activated
// Thus, we can literate the range of the sensors and arrange the sensors.
// To avoid the waste of the sensors, we can check for the last sensor that is activated, whether all the cars in case 1 can be detected.
// If yes, then ignore; if not, then activate the last sensor.
// ---
// As for the time, the calc of will-over cars need up to O(N*logN)
// As for the negetive cars, the downspeed calc will be O(N), and the find need O(2*NlogN)
// Then, ranging from 1 to m need O(m)
// Check the car again need O(N*logN)
// Up to T test cases
// Thus, the total time is O(T*(4*N*logN + N + m))
// T = 20, N = 1 * 10^5, L = 10^6
// logN = 16.6
// => Total time = 121657842, too long...

struct car {
	int enter, v, a;
}neg[100005];

int negCnt = 0;
int sensors[100005];

int lookUp(int cnt, long double k) {
	int stk = 0;
	for (int i = 30; i >= 0; i--) {
		if (stk + (1 << i) <= cnt && sensors[stk + (1 << i)] < k) {
			stk += (1 << i);
		}
	}
	return stk;
}

int lookDown(int cnt, long double k) {
	int stk = 0;
	for (int i = 30; i >= 0; i--) {
		if (stk + (1 << i) <= cnt && sensors[stk + (1 << i)] <= k) {
			stk += (1 << i);
		}
	}
	return stk;
}

vector<int> ranges[100005];
car greaterCars[100005];
int gC = 0;
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		negCnt = 0;
		for (int i = 1; i < 100005; i++) {
			ranges[i].clear();
		}
		gC = 0;
		// ClearUp
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		int willOver = 0;
		for (int i = 1; i <= n; i++) {
			int a, v, e;
			cin >> e >> v >> a;
			if (a > 0) {
				++gC;
				greaterCars[gC].enter = e,
				greaterCars[gC].v = v,
				greaterCars[gC].a = a;
			}
			else {
				if (v > V) {
						++negCnt;
						neg[negCnt].enter = e,
						neg[negCnt].v = v;
						neg[negCnt].a = a;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			cin >> sensors[i];
		}
		// cout << willOver << endl;
		sort(sensors + 1, sensors + m + 1);
		car lowSpd;
		double lS = -1;
		for (int i = 1; i <= gC; i++) {
			int v0 = greaterCars[i].v,
				v1 = V,
				a = greaterCars[i].a,
				enter = greaterCars[i].enter;
			long double overPos = enter + (v1 * v1 - v0 * v0) / 2.0 / a;
			if (overPos - pref < sensors[m]) {
				++willOver;
				if (overPos > lS) {
					lS = overPos;
					lowSpd = greaterCars[i];
				}
			}
		}
		// Calc 
		// Emmm, I think I need a conatiner which can can can can can
		// Can find the ...
		// I got it, i have a vector, then a map, if the section ends, first check in the map
		// If not, add the sensor, clear the vector.
		// Do I really need a vector?
		// Oh, yes, because I need to know which ranges should be flag to true
		// --
		// Now I will develop a function
		// Do I?
		// Let me think for a while... 
		// I think I forgot the function name which implies the binary search in std...
		// I will write one?
		// Yes...
		// The first function might be lookUp(int[], k) which returns the first position where the element just Greater than k
		// The second function might be lookDown(int[], k) which returns the first position where the element just Smaller than k
		if (debug)cout << "Negcnt " << negCnt << endl;
		for (int i = 1; i <= negCnt; i++) {
			int v1 = neg[i].v, v2 = V, a = neg[i].a, x0 = neg[i].enter;
			double x1 = x0 - 1.0 * (v1 * v1 - v2 * v2) / (a * 2);
			if (a == 0) {
				x1 = 1145141919810;
			}
			int sensorBg = lookUp(m, x0 * 1.0),
				sensorEd = lookDown(m, x1 - pref);
			if (debug)printf("For the car v = %d, a = %d, entered at %d, it wll over spd before pos %f\n",
					v1, a, x0, x1);
			if (sensorBg >= sensorEd) continue;
			if (debug)printf("Thus, it will pass the sensors (%d, %d]\n", sensorBg, sensorEd);
			willOver++;
			ranges[sensorBg].emplace_back(i);
			ranges[sensorEd].emplace_back(-i);
		}
		if (debug)cout <<willOver<< "car(s) overspeed" << endl;
		int lastSensor = -1;
		int litSensors = 0;
		vector<int> pending;
		map<int, int> done;
		for (int i = 0; i <= m; i++) {
			sort(ranges[i].begin(), ranges[i].end());
			bool flag = false;
			for (auto k : ranges[i]) {
				if (k > 0) {
					pending.emplace_back(k);
					if (debug)printf("At the position %d, a section named %d begun\n", sensors[i], k);
				} else {
					if (flag) continue;
					if (done[-k] != 0) {
						if (debug)printf("A section named %d ended, however, it was calced before\n", -k);
						continue;
					}
					if (pending.size() == 0) continue;
					if (debug)printf("Having ");
					for (auto z : pending) {
						done[z] = 1;
						if (debug)printf("%d ", z);
					}
					if (debug)printf("to clear\n");
					pending.clear();
					flag = true;
				}
			}
			if (flag) litSensors += flag, lastSensor = i;
		}
		if (debug)cout << "Sensors Lit by a < 0: " << litSensors << endl;
		// printf("As for the lowest car which still can overspeed with spd %f at the very last station...\n", lS);
		if (debug)cout << lastSensor << endl;
		if (lS + pref >= sensors[lastSensor]) {
			if (debug)printf("What a pity, we need to lit up the sensor at %d", sensors[m]);
			litSensors++;
		}
		if (debug)cout << lS  << ' ' << sensors[lastSensor]<< endl;
		if (debug)cout << m - litSensors << endl;
		cout << willOver << " " << m - litSensors << endl;
		// Okey, now we think again...
		// For the ai > 0 case 1: all cars have been blocked at the last activated sensor. Then no need to to this.
		// Detection of case 1: the lowSpd car reaches higher than V at that sensor.
		// Case 2: All cars can not be blocked at the last activated sensor, but can be at the very last one.
		// Detection of case 2: the lowSqd car reaches higher than V at the last sensor.
		// Case 3: Some cars will reach.
		// Detection of case 3: Calc the list, and then add.
		// So I think I need to storage the ai > 0 list...
	}
	return 0;
}