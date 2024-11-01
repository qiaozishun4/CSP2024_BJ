#include<iostream>
using namespace std;
int n;
int cnt = 0;
int ans = 0;
struct monster{
	int r;
	int protect;
	int times;
	bool out;
}a[10001];
bool is_timesover(monster a[],int n,int ans){
	for(int i = 0;i < n;i++){
		if(a[i].times == 0)
			ans++;
	}
	if(ans == 0)
		return true;
	else
		return false;
}
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].r;
		a[i].times = 1;
		a[i].protect = a[i].r;
		a[i].out = false;
	}
	while(!is_timesover){
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++){
				if(j != i && a[i].times > 0 && !a[i].out && !a[j].out && a[j].protect < a[i].r)
					{
						a[i].times -= 1;
						a[j].out = true;
					}
				else
					continue;
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(!a[i].out)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}