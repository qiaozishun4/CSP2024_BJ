#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,j=52,c=0;
    string s[100];
    cin >> n;
    for(int i = 0;i < n;i++) cin >> s[i];
    for(int i = 0;i < n;i++){
    	int f = 1;
    	for(int j = 0;j < i;j++){
    	    if(s[i] == s[j]){
    	    	f=0;
    	    	break;
    	    }
    	}
    	if(f)c++;
    }
    j -= c;
    cout << j;
    return 0;
}