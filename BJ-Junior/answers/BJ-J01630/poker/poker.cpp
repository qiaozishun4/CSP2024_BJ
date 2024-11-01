#include<bits/stdc++.h>
using namespace std;
const int N = 60;
string s[N];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int ans = 52 - n;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(s[i] == s[j] && i != j){
                ans += 1;
                s[i] = "AA";
            }
        }
    }
    cout<<ans;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
