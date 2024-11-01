#include <bits/stdc++.h>

using namespace std;

// greater or equal than v[idx]
int binsearch(const vector<int>&v, int val){
	if (val > v.back()){
		return INT_MAX;
	}

	int l = 0, r = v.size();
	while (l < r){
		int mid = (l + r) / 2;
		if (val < v[mid]){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l - 1;
}

double getDist(const int V, const int v_0, const int a){
    return ((double)(pow(V, 2)-pow(v_0, 2))) / ((double)(2 * a));
}
int main(){
	ios::sync_with_stdio(false);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int T;
	cin >> T;

	for (int _ = 0; _ < T; _++){
        int cars, detectors, L, lim;
        cin >> cars >> detectors >> L >>lim;

        vector<int> pos(cars), v_0(cars), a(cars);
        vector<int> posD(detectors);

        for (int i = 0; i < cars; i++){
            cin >> pos[i] >> v_0[i] >> a[i];
        }
        for (int i = 0; i < detectors; i++){
            cin >> posD[i];
        }

        long long exceed = 0, requests = 0;
        for (int i = 0; i < cars; i++){
            if (a[i] == 0){
                if (v_0[i] > lim && binsearch(posD, pos[i])!=INT_MAX){
                    exceed++;
                    requests = 1;
                }
            }else if (a[i] > 0){
                if (v_0[i] > lim){
                    if (binsearch(posD, pos[i])!=INT_MAX){
                        exceed++;
                        //
                    }
                }else{
                    int D = (int)getDist(lim, v_0[i], a[i]);
                    if (binsearch(posD, D)!=binsearch(posD, pos[i])){
                        exceed++;
                        //
                    }
                }
            }else{
                if (v_0[i] > lim){
                    int D = (int)getDist(lim, v_0[i], a[i]);
                    if (binsearch(posD, pos[i]) != binsearch(posD, D)){
                        exceed++;
                        //
                    }
                }
            }
        }
        cout << exceed <<" "<<detectors - requests << endl;
	}
	return 0;
}
