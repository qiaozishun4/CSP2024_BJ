#include<iostream>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n,b[15][5]={};
    cin>>n;
    char a[55][2];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i][0]=='D'){
			if(a[i][1]=='T') b[9][0]=1;
			else if(a[i][1]=='J') b[10][0]=1;
			else if(a[i][1]=='Q') b[11][0]=1;
			else if(a[i][1]=='K') b[12][0]=1;
			else if(a[i][1]=='A') b[0][0]=1;
			else b[int(a[i][1])-'0'-1][0]=1;
		}else if(a[i][0]=='C'){
			if(a[i][1]=='T') b[9][1]=1;
			else if(a[i][1]=='J') b[10][1]=1;
			else if(a[i][1]=='Q') b[11][1]=1;
			else if(a[i][1]=='K') b[12][1]=1;
			else if(a[i][1]=='A') b[0][1]=1;
			else b[int(a[i][1])-'0'-1][1]=1;
		}else if(a[i][0]=='H'){
			if(a[i][1]=='T') b[9][2]=1;
			else if(a[i][1]=='J') b[10][2]=1;
			else if(a[i][1]=='Q') b[11][2]=1;
			else if(a[i][1]=='K') b[12][2]=1;
			else if(a[i][1]=='A') b[0][2]=1;
			else b[int(a[i][1])-'0'-1][2]=1;
		}else if(a[i][0]=='S'){
			if(a[i][1]=='T') b[9][3]=1;
			else if(a[i][1]=='J') b[10][3]=1;
			else if(a[i][1]=='Q') b[11][3]=1;
			else if(a[i][1]=='K') b[12][3]=1;
			else if(a[i][1]=='A') b[0][3]=1;
			else b[int(a[i][1])-'0'-1][3]=1;
		}
	}
	int ans=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(b[i][j]==0) ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
