#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
	int n, cnt=0;
	string s[100];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bool f=1;
        for(int j=1;j<=n;j++){
            if(s[j]==s[i]&&j!=i){
                f=0;
                break;
            }
        }
        if(f==1)cnt++;
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


