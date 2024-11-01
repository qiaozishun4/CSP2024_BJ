#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[56];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D'&&s[1]=='A') a[1]=true;
		if(s[0]=='D'&&s[1]=='2') a[2]=true;
		if(s[0]=='D'&&s[1]=='3') a[3]=true;
		if(s[0]=='D'&&s[1]=='4') a[4]=true;
		if(s[0]=='D'&&s[1]=='5') a[5]=true;
		if(s[0]=='D'&&s[1]=='6') a[6]=true;
		if(s[0]=='D'&&s[1]=='7') a[7]=true;
		if(s[0]=='D'&&s[1]=='8') a[8]=true;
		if(s[0]=='D'&&s[1]=='9') a[9]=true;
		if(s[0]=='D'&&s[1]=='T') a[10]=true;
		if(s[0]=='D'&&s[1]=='J') a[11]=true;
		if(s[0]=='D'&&s[1]=='Q') a[12]=true;
		if(s[0]=='D'&&s[1]=='K') a[13]=true;
		if(s[0]=='C'&&s[1]=='A') a[14]=true;
		if(s[0]=='C'&&s[1]=='2') a[15]=true;
		if(s[0]=='C'&&s[1]=='3') a[16]=true;
		if(s[0]=='C'&&s[1]=='4') a[17]=true;
		if(s[0]=='C'&&s[1]=='5') a[18]=true;
		if(s[0]=='C'&&s[1]=='6') a[19]=true;
		if(s[0]=='C'&&s[1]=='7') a[20]=true;
		if(s[0]=='C'&&s[1]=='8') a[21]=true;
		if(s[0]=='C'&&s[1]=='9') a[22]=true;
		if(s[0]=='C'&&s[1]=='T') a[23]=true;
		if(s[0]=='C'&&s[1]=='J') a[24]=true;
		if(s[0]=='C'&&s[1]=='Q') a[25]=true;
		if(s[0]=='C'&&s[1]=='K') a[26]=true;
		if(s[0]=='H'&&s[1]=='A') a[27]=true;
		if(s[0]=='H'&&s[1]=='2') a[28]=true;
		if(s[0]=='H'&&s[1]=='3') a[29]=true;
		if(s[0]=='H'&&s[1]=='4') a[30]=true;
		if(s[0]=='H'&&s[1]=='5') a[31]=true;
		if(s[0]=='H'&&s[1]=='6') a[32]=true;
		if(s[0]=='H'&&s[1]=='7') a[33]=true;
		if(s[0]=='H'&&s[1]=='8') a[34]=true;
		if(s[0]=='H'&&s[1]=='9') a[35]=true;
		if(s[0]=='H'&&s[1]=='T') a[36]=true;
		if(s[0]=='H'&&s[1]=='J') a[37]=true;
		if(s[0]=='H'&&s[1]=='Q') a[38]=true;
		if(s[0]=='H'&&s[1]=='K') a[39]=true;
		if(s[0]=='S'&&s[1]=='A') a[40]=true;
		if(s[0]=='S'&&s[1]=='2') a[41]=true;
		if(s[0]=='S'&&s[1]=='3') a[42]=true;
		if(s[0]=='S'&&s[1]=='4') a[43]=true;
		if(s[0]=='S'&&s[1]=='5') a[44]=true;
		if(s[0]=='S'&&s[1]=='6') a[45]=true;
		if(s[0]=='S'&&s[1]=='7') a[46]=true;
		if(s[0]=='S'&&s[1]=='8') a[47]=true;
		if(s[0]=='S'&&s[1]=='9') a[48]=true;
		if(s[0]=='S'&&s[1]=='T') a[49]=true;
		if(s[0]=='S'&&s[1]=='J') a[50]=true;
		if(s[0]=='S'&&s[1]=='Q') a[51]=true;
		if(s[0]=='S'&&s[1]=='K') a[52]=true;
	}
	for(int i=1;i<=52;i++){
		if(a[i]==false) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
