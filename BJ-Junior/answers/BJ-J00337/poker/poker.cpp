#include<iostream>
using namespace std;
int d[200];
int c[200];
int h[200];
int s[200];
int n;
string str;
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","r",stdout);
    cin>>n;
	for(int i = 1;i <= n;i ++){
        cin>>str;
        if(str[0] == 'D'){
            if(str[1] <= '9'&&str[1] >= '0')
                    d[str[1]-'0'] ++;
            else if(str[1] == 'J')
                d[11]++;
            else if(str[1] == 'K')
                d[13]++;
            else if(str[1] == 'Q')
                d[12]++;
            else if(str[1] == 'A')
                d[1]++;
            else
                d[10]++;
        }
        else if(str[0] == 'C'){
            if(str[1] <= '9'&&str[1] >= '0')
                    c[str[1]-'0'] ++;
            else if(str[1] == 'J')
                c[11]++;
            else if(str[1] == 'K')
                c[13]++;
            else if(str[1] == 'Q')
                c[12]++;
            else if(str[1] == 'A')
                c[1]++;
            else
                c[10]++;
        }
        else if(str[0] == 'H'){
            if(str[1] <= '9'&&str[1] >= '0')
                    h[str[1]-'0'] ++;
            else if(str[1] == 'J')
                h[11]++;
            else if(str[1] == 'K')
                h[13]++;
            else if(str[1] == 'Q')
                h[12]++;
            else if(str[1] == 'A')
                h[1]++;
            else
                h[10]++;
        }
        else if(str[0] == 'S'){
            if(str[1] <= '9'&&str[1] >= '0')
                    d[str[1]-'0'] ++;
            else if(str[1] == 'J')
                s[11]++;
            else if(str[1] == 'K')
                s[13]++;
            else if(str[1] == 'Q')
                s[12]++;
            else if(str[1] == 'A')
                s[1]++;
            else
                s[10]++;
        }
	}
	int sum = 0;
	for(int i = 1;i <= 13;i ++){
        if(s[i] == 0)
            sum++;
        if(d[i] == 0)
            sum++;
        if(h[i] == 0)
            sum++;
        if(c[i] == 0)
            sum++;
	}
	cout<<sum;

	return 0;
}
