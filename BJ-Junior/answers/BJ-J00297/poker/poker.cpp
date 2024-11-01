#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<string> cd;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		string temp;
		cin >> temp;
		cnt++;
		for(int j=0;j<cd.size();j++){
			if(temp==cd[j]){
				cnt--;
				break;
			}
		}
		cd.push_back(temp);
	}
	cout << 52-cnt;
	return 0;
}