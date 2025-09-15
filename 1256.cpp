#include <stdio.h>
#include <iostream>
using namespace std;

int main(char argv[], int argc)
{

  int line[6];
  int  joker[]  = { 1, 2, 5, 6};
  int i  =  0;
  int j  =  0;

  for(i; i < 2; i++)
 {
       j = i;
      line[i] = joker[j];
       
      
}  

    cout << "i: " << i << endl;
    cout << "j: " << j << endl;

   line[i] = line[i-2] + line[i-1];
   j++;  
   i++;      

for( j; j<=4; j++)
{ 
  if( j == 2) 
  line[i] = joker[j] -  joker[j -2];
 
   if ( j == 3)
   {  cout << "j: " <<  j << " -> " <<	 joker[j] << endl;
      line[i] = joker[j] - joker[ j - 3];
      
     
  }
  
  if( j == 4)
  {
    line[i] =  line[i-1] + line[i-4 - 1];
    
  }

 i++;
// j++;
}

 for(int z = 0; z< 6; z++)
   cout << line[z]  << " " ;

cout << endl;
 return  1;
}
