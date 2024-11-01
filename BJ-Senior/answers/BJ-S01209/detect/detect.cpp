#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define RANGE(cont) (cont).begin(), (cont).end()
#define SELF (*this)

long long square(int a) {
	return (long long) a * a;
}

struct Car {
	int s=-1, v=-1, a=-1;
};

struct Range {
	unsigned l=-1, r=-1;
};
bool rLess_lLess(const Range& a, const Range& b) {
	return a.r != b.r ? a.r < b.r : a.l < b.l;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(nullptr);

	unsigned turnN; cin >> turnN;
	for (unsigned turn=0; turn<turnN; ++turn) {
		unsigned carN, testN, roadLen, maxSpeed; cin >> carN >> testN >> roadLen >> maxSpeed;
		vector<Car> cars(carN);
		for (auto& car : cars) {
			cin >> car.s >> car.v >> car.a;
		}
		vector<unsigned> tests(testN);
		for (auto& i : tests) {
			cin >> i;
		}
		unsigned overSpeedN=0;
		vector<Range> overSpeeds; overSpeeds.reserve(cars.size());
		for (const auto& car : cars) {
			const auto sReach = car.s + double(square(maxSpeed) - square(car.v)) / (2*car.a);
			if (!car.a) {
				if (car.v <= maxSpeed) {
					continue;
				}
				overSpeeds.push_back({
					lower_bound(RANGE(tests), car.s)-tests.begin(),
					tests.size()});
			}
			else if (car.a > 0) {
				if (sReach >= tests.back()) {
					continue;
				}
				overSpeeds.push_back({
					max(
						lower_bound(RANGE(tests), car.s)-tests.begin(),
						upper_bound(RANGE(tests), sReach)-tests.begin()),
				tests.size()});
			}
			else {
				if (car.v <= maxSpeed) {
					continue;
				}
				overSpeeds.push_back({
					lower_bound(RANGE(tests), car.s)-tests.begin(),
					lower_bound(RANGE(tests), sReach)-tests.begin()});
			}
			if (overSpeeds.back().l >= overSpeeds.back().r) {
				overSpeeds.pop_back();
				continue;
			}
			++overSpeedN;
		}
		sort(RANGE(overSpeeds), rLess_lLess);
		unsigned openN=0, lastPut=-1;
		for (const auto& range : overSpeeds) {
			if (range.l <= lastPut && lastPut != -1U) {
				continue;
			}
			lastPut = range.r-1;
			++openN;
		}
		cout << overSpeedN << " " << testN-openN << "\n";
	}
}
