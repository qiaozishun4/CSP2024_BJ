#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    char code[75]="abcdefghijkmlnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-=_+/@?!()";
    while(true)
    {
        srand((unsigned)time(NULL));
        string s="";
        for(int i=0;i<125;i++)   s+=code[rand()%74];
        cout<<s<<endl;
        string ined;
        cin>>ined;
        int correct=0;
        for(int i=0;i<99;i++)   if(ined[i]==s[i])   correct++;
        cout<<correct<<" ("<<1.0d*correct/1.25<<"%)"<<endl;
    }
}