#include<bits/stdc++.h>
using namespace std;
int sticks[9]={6,2,5,0,4,0,0,3,7},nm[0,0,1,7,4,2,0,8],tf=0;
int csti(int a,int j)
{
    if(j==1&&(a>7||a<=1))return -1;
    else if(j==1)return nm[a];
    for(int i=0;i<9;i++){
        if(tf==j){
            tf=0;
            i++;
        }
        if(sticks[i]!=0){
            if(csti(a-sticks[i],j-1)==-1&&i==8)return -1;
            else if(csti(a-sticks[i],j-1)==-1&&i<8)continue;
            else return i*pow(10,j-1)+csti(a-sticks[i],j-1);
        }
        else continue;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a=0;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a<=1){
            cout<<-1<<endl;
            continue;
        }
        if(a==5){
            cout<<24<<endl;
            continue;
        }
        if(a==6){
            cout<<6<<endl;
            continue;
        }
        int j=1;
        while(a<j*7)j++;
        tf=l;
        cout<<csti(a,j)<<endl;
    }
    return 0;
}