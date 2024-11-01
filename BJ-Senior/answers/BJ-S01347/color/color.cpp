#include<bits/stdc++.h>
using namespace std;
int T,C,n,A[200005],cnt1,R,B,c;
string s[100000];
void find1(int step,string ss){
	for(int i=0;i<=1;i++){
		if(step==n-1){
		   s[cnt1]=ss+char(i+'0');cnt1++;
		}
		else find1(step+1,ss+char(i+'0'));
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		C=0;cnt1=0;
		cin>>n;
		for(int i=0;i<n;i++){cin>>A[i];}
		find1(0,"");
//		for(int i=0;i<cnt1;i++)cout<<s[i]<<endl;
		for(int i=0;i<cnt1;i++){
			R=B=-1;c=0;
			for(int j=0;j<n;j++){
				if(s[i][j]=='0'){
					if(B!=-1)
						if(A[B]==A[j])c+=A[j];
					B=j;
				}else{
					if(R!=-1)
						if(A[R]==A[j])c+=A[j];
					R=j;
				}
			}
			C=max(C,c);
		}
		cout<<C<<endl;
	}
	return 0;
}
