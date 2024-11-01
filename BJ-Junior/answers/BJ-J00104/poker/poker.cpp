#include <bits/stdc++.h>
using namespace std;
bool ha[5][60];
int in1[200],in2[200];
int n,sum=52;
char c1,c2;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    in1['D']=1;in1['C']=2;in1['H']=3;in1['S']=4;
    for(int i=2;i<10;i++)
        in2[i+'0']=i;
    in2['A']=1;in2['T']=10;in2['J']=11;in2['Q']=12;in2['K']=13;
    cin >> n;
    while(n--){
        cin >> c1 >> c2;
        if(!ha[in1[c1]][in2[c2]])
            sum--;
        ha[in1[c1]][in2[c2]]=1;
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
