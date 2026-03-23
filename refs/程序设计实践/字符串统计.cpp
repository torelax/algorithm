#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int compa(char *p1, int len1, char *p2, int len2)
{
    int n=0;
    for(int i=0;i<=(len1-len2);i++)
    {
        if(strncmp(p1,p2,len2)==0)
        {
            n++;
            p1=p1+len2-1;
        }
        p1++;
    }
    return n;
}  

int main()
{
    char str1[100],str2[100];
    int len1, len2;
    cin>>str1>>str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    cout<<compa(str1, len1, str2, len2); 
    return 0;
 }

