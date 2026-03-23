#include <iostream>
#include <string>

using namespace std;
 void ward (int n,int sorce[],int cla[],int count[],int he[],char is_gan[])
{
   int nmm =n;
   if (sorce[nmm]>80 && he[nmm]>=1)
   {
      count[nmm] = count[nmm]+8000;
   }
   if (sorce[nmm]>85 && cla[nmm]>80)
   {
      count[nmm] = count[nmm]+4000;
   }
   if (sorce[nmm]>90)
   {
      count[nmm] = count[nmm]+2000;
   }
}
 void ward2 (int n,int sorce[],int cla[],char is_west[],char is_gan[],int count[])
{
   int nmm =n;
   if (sorce[nmm]>85 && is_west[nmm]=='Y')
   {
      count[nmm] = count[nmm]+1000;
   }
   if (cla[nmm]>80 && is_gan[nmm]=='Y')
   {
      count[nmm] = count[nmm]+850;
   }
}
int main()
{
   
   int sumc;
   int k;
   int maxa;  
   int m;
   cout<<"InPut 1<=N<=100"<<endl;
   int num;
   cin >> num;
   int sorce[num];
   int cla[num];
   int he[num];
   int count[num];
   string name[num];
   char is_gan[num];
   char is_west[num];
   int n=0;
   while (n<num)
   {
      cin >> name[n]>> sorce[n]>>cla[n]>> is_gan[n]>> is_west[n]>> he[n];
      count[n] = 0;
      n =n+1;
   }
   n =1;
   while (!(n>num))
   {
      ward2(n-1,sorce,cla,is_west,is_gan,count);
      ward(n-1,sorce,cla,count,he,is_gan);
      n =n+1;
   }
   k =0;
   sumc =0;
   m =0;
   maxa =0;
   while (1)
   {
      if (maxa<count[k])
      {
         m =k;
      }
      maxa = (maxa > count[k] ? maxa : count[k]) ;
      sumc += count[k];
      if ((k+1)==num)  break;
      k =k+1;
   }
   cout << name[m] << endl;   
   cout << maxa << endl;   
   cout << sumc << endl;
   return 0;
}
