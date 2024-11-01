#include<iostream>
using namespace std;
const int mylib[12]{0,6,2,5,5,4,5,6,3,7,6};
int T;
int foundation(int k){
    if(k<=1)return -1;
    if(k==2)return 1;
    if(k==5)return 2;
    if(k==3)return 7;
    if(k==4)return 4;
    if(k==6)return 6;
    if(k==7)return 8;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        cout<<foundation(n)<<"\n";
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
