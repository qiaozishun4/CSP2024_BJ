#include<bits/stdc++.h>
using namespace std;
int n;
char x,y;
int a[100][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		int Y;
		if(y>='2'&&y<='9'){
            Y=int(y-'0');
		}
        if(y=='T'){
            Y=10;
        }
        if(y=='J'){
            Y=11;
        }
        if(y=='Q'){
            Y=12;
        }
        if(y=='K'){
            Y=13;
        }
        if(y=='A'){
            Y=1;
        }
		if(x=='D'){
            a[1][Y]=1;
		}
		if(x=='C'){
            a[2][Y]=1;
		}
		if(x=='H'){
            a[3][Y]=1;
		}
		if(x=='S'){
            a[4][Y]=1;
		}
	}
	int sum=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){

            if(a[i][j]==1){
                sum-=1;
            }
        }
    }
    cout<<sum;
	return 0;
}
