#include<bits/stdc++.h>
using namespace std;
int s1[1000][1000];
int all=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string m;
        cin>>m;
        if(s1[m[0]-'0'][m[1]-'0']==0){
            all--;
        }
        s1[m[0]-'0'][m[1]-'0']++;
    }
    cout<<all;
}
