#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,a[15][4],m,b=0;
    string s;
    cin>>n;
    for(int i=1;i<15;i++){
		for(int j=0;j<4;j++){
			a[i][j]=0;
		}
	}
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[1]=='A') m=1;
        else if('2'<=s[1] && s[1]<='9') m=s[1]-'0';
        else if(s[1]=='J') m=11;
        else if(s[1]=='Q') m=12;
        else if(s[1]=='K') m=13;
        if(s[0]=='D'){
            if(a[m][0]==0){
                a[m][0]=1;
                b++;
            }
        }
        else if(s[0]=='C'){
            if(a[m][1]==0){
                a[m][1]=1;
                b++;
            }
        }
        else if(s[0]=='S'){
            if(a[m][2]==0){
                a[m][2]=1;
                b++;
            }
        }
        else if(s[0]=='H'){
            if(a[m][3]==0){
                a[m][3]=1;
                b++;
            }
        }
    }
    cout<<52-b;
    return 0;
}
