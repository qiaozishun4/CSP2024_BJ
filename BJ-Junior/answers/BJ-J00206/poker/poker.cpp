#include<bits/stdc++.h>
using namespace std;
int a[4][13];
int main(){
    int n,sum=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<4;i++)
		for(int j=0;j<13;i++)
			a[i][j]==0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[0]=='C')
            if(s[1]>='2'&&s[1]<='9') a[0][int(s[1]-'0')-1]++;
            else if(s[1]=='A') a[0][0]++;
            else if(s[1]=='T') a[0][9]++;
            else if(s[1]=='J') a[0][10]++;
            else if(s[1]=='Q') a[0][11]++;
            else if(s[1]=='K') a[0][12]++;
        if(s[0]=='S')
            if(s[1]>='2'&&s[1]<='9') a[1][int(s[1]-'0')-1]++;
            else if(s[1]=='A') a[1][0]++;
            else if(s[1]=='T') a[1][9]++;
            else if(s[1]=='J') a[1][10]++;
            else if(s[1]=='Q') a[1][11]++;
            else if(s[1]=='K') a[1][12]++;
        if(s[0]=='H')
            if(s[1]>='2'&&s[1]<='9') a[2][int(s[1]-'0')-1]++;
            else if(s[1]=='A') a[2][0]++;
            else if(s[1]=='T') a[2][9]++;
            else if(s[1]=='J') a[2][10]++;
            else if(s[1]=='Q') a[2][11]++;
            else if(s[1]=='K') a[2][12]++;
        if(s[0]=='D')
            if(s[1]>='2'&&s[1]<='9') a[3][int(s[1]-'0')-1]++;
            else if(s[1]=='A') a[3][0]++;
            else if(s[1]=='T') a[3][9]++;
            else if(s[1]=='J') a[3][10]++;
            else if(s[1]=='Q') a[3][11]++;
            else if(s[1]=='K') a[3][12]++;
    }
    for(int i=0;i<4;i++) for(int j=0;j<13;j++) if(a[i][j]==0) sum++;
    cout<<sum<<endl;
    return 0;
}
