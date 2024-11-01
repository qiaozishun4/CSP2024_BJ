#include<bits/stdc++.h>
using namespace std;

freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);

int main(){
    int n,cnt=52;
    string s;
    cin>>n;
    if(n==52){
		cout<<"0";
		return 0;
	}
    bool flag[54]={0};
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
			if(s[1]=='A') flag[1]=true;
			if(s[1]=='2') flag[2]=true;
			if(s[1]=='3') flag[3]=true;
			if(s[1]=='4') flag[4]=true;
			if(s[1]=='5') flag[5]=true;
			if(s[1]=='6') flag[6]=true;
			if(s[1]=='7') flag[7]=true;
			if(s[1]=='8') flag[8]=true;
			if(s[1]=='9') flag[9]=true;
			if(s[1]=='T') flag[10]=true;
			if(s[1]=='J') flag[11]=true;
			if(s[1]=='Q') flag[12]=true;
			if(s[1]=='K') flag[13]=true;
		}			
		if(s[0]=='C'){
			if(s[1]=='A') flag[14]=true;
			if(s[1]=='2') flag[15]=true;
			if(s[1]=='3') flag[16]=true;
			if(s[1]=='4') flag[17]=true;
			if(s[1]=='5') flag[18]=true;
			if(s[1]=='6') flag[19]=true;
			if(s[1]=='7') flag[20]=true;
			if(s[1]=='8') flag[21]=true;
			if(s[1]=='9') flag[22]=true;
			if(s[1]=='T') flag[23]=true;
			if(s[1]=='J') flag[24]=true;
			if(s[1]=='Q') flag[25]=true;
			if(s[1]=='K') flag[26]=true;
		}		
		if(s[0]=='H'){
			if(s[1]=='A') flag[27]=true;
			if(s[1]=='2') flag[28]=true;
			if(s[1]=='3') flag[29]=true;
			if(s[1]=='8') flag[34]=true;
			if(s[1]=='9') flag[35]=true;
			if(s[1]=='T') flag[36]=true;
			if(s[1]=='J') flag[37]=true;
			if(s[1]=='Q') flag[38]=true;
			if(s[1]=='K') flag[39]=true;
		}	
		if(s[0]=='S'){
			if(s[1]=='A') flag[40]=true;
			if(s[1]=='2') flag[41]=true;
			if(s[1]=='3') flag[42]=true;
			if(s[1]=='4') flag[43]=true;
			if(s[1]=='5') flag[44]=true;
			if(s[1]=='6') flag[45]=true;
			if(s[1]=='7') flag[46]=true;
			if(s[1]=='8') flag[47]=true;
			if(s[1]=='9') flag[48]=true;
			if(s[1]=='T') flag[49]=true;
			if(s[1]=='J') flag[50]=true;
			if(s[1]=='Q') flag[51]=true;
			if(s[1]=='K') flag[52]=true;
		}	
        
    }
    for(int i=52;i>=1;i--){
        if(flag[i]==true) cnt--;
    }
    cout<<cnt;	
	return 0;
}
