#include<bits/stdc++.h>
#include<string>
using namespace std;
string ch[]= {"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
bool flag[100];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<52;j++){
			if(ch[j]==s){
				flag[j]=true;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<52;i++){
		if(!flag[i])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}