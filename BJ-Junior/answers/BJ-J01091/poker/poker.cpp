#include<bits/stdc++.h>
using namespace std;
int a[4][13]={0};
int n,cnt=0;
int main()
{
	ifstream fin("poker.in",ios::in);
	ofstream fout("poker.out",ios::out);
    fin >> n;
    char s1,s2;
    for(int i=0;i<n;i++){
		fin >> s1 >> s2;
		int x=int(s1),y=int(s2);
        if(y=='A'){
            if(x=='D')
                a[0][0]=1;
            else if(x=='C')
                a[1][0]=1;
            else if(x=='H')
                a[2][0]=1;
            else
                a[3][0]=1;
        }
        else if(y=='2'){
            if(x=='D')
                a[0][1]=1;
            else if(x=='C')
                a[1][1]=1;
            else if(x=='H')
                a[2][1]=1;
            else
                a[3][1]=1;
        }
        else if(y=='3'){
            if(x=='D')
                a[0][2]=1;
            else if(x=='C')
                a[1][2]=1;
            else if(x=='H')
                a[2][2]=1;
            else
                a[3][2]=1;
        }
        else if(y=='4'){
            if(x=='D')
                a[0][3]=1;
            else if(x=='C')
                a[1][3]=1;
            else if(x=='H')
                a[2][3]=1;
            else
                a[3][3]=1;
        }
        else if(y=='5'){
            if(x=='D')
                a[0][4]=1;
            else if(x=='C')
                a[1][4]=1;
            else if(x=='H')
                a[2][4]=1;
            else
                a[3][4]=1;
        }
        else if(y=='6'){
            if(x=='D')
                a[0][5]=1;
            else if(x=='C')
                a[1][5]=1;
            else if(x=='H')
                a[2][5]=1;
            else
                a[3][5]=1;
        }
        else if(y=='7'){
            if(x=='D')
                a[0][6]=1;
            else if(x=='C')
                a[1][6]=1;
            else if(x=='H')
                a[2][6]=1;
            else
                a[3][6]=1;
        }
        else if(y=='8'){
            if(x=='D')
                a[0][7]=1;
            else if(x=='C')
                a[1][7]=1;
            else if(x=='H')
                a[2][7]=1;
            else
                a[3][7]=1;
        }
        else if(y=='9'){
            if(x=='D')
                a[0][8]=1;
            else if(x=='C')
                a[1][8]=1;
            else if(x=='H')
                a[2][8]=1;
            else
                a[3][8]=1;
        }
        else if(y=='T'){
            if(x=='D')
                a[0][9]=1;
            else if(x=='C')
                a[1][9]=1;
            else if(x=='H')
                a[2][9]=1;
            else
                a[3][9]=1;
        }
        else if(y=='J'){
            if(x=='D')
                a[0][10]=1;
            else if(x=='C')
                a[1][10]=1;
            else if(x=='H')
                a[2][10]=1;
            else
                a[3][10]=1;
        }
        else if(y=='Q'){
            if(x=='D')
                a[0][11]=1;
            else if(x=='C')
                a[1][11]=1;
            else if(x=='H')
                a[2][11]=1;
            else
                a[3][11]=1;
        }
        else if(y=='K'){
            if(x=='D')
                a[0][12]=1;
            else if(x=='C')
                a[1][12]=1;
            else if(x=='H')
                a[2][12]=1;
            else
                a[3][12]=1;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==1)
                cnt++;
        }
    }
    fout << 52-cnt;
    return 0;
}
