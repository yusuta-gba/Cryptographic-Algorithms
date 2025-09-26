#include <stdio.h>
#include <iostream>
using namespace std;

int joker[] = { 1, 2, 5, 6};
int line[20];
int i;
int j;


int main( char*  argv[], int argc)
{
    
     for(i; i <2; i++)
     {
          j = i;
          line[i] = joker[j];
     }

        cout << "line[0]: " << line[0] << endl;
        cout  << "line[1]  " << line[1] << endl;
  

     line[i] = line[i - 2] + line[i -1];
     j++;
     i++;
     cout << "line[2]: " << line[2] << endl;

        


     
  for(j; j<=4; j++)
  {
    line[i] = joker[j] -joker[j - j];
    
       if( j == 4)
       {
         line[i] = joker[j - (line[i-j-1] + line[i-j-1])] + line[i-j-1];
        //cout << "i " << i <<   "line[i]" << line[i] << endl;        
       }
     i++;
  }
    cout << "line[3] " << line[3] << endl;
    cout << "line[4] " << line[4] << endl;
cout << "i:   " << i << endl;	
int q;
int start = j - 2;
int u = ( j - 2) + 1 +1;
for(q = j - 2; q <=u; q++)
  {
	 if( q  == j - 2)
          {     
             line[i] =  joker[q] + joker[q % 3];  // 6 +1
             cout << "i: " << i << " line[5]: " << line[5] << endl;
          }
                        
          if( q ==  j - 2  + 1 )
          {                    
	     line[i] = joker[ q - 1] +  joker[q % 3]; // 6 + 2
             cout << " line[6]: " << line[6] << endl;   
	  }

         if( q == (j - 2) + 1 +1)
          {
            line[i] =  line[q  % 3]  + joker[start];
          }
     i++; 
} 

 cout << "--------------------" << endl;
     
     line[9] = line[0] + line[8];
     for(int  t = 1; t <= 10; t++)
       {
          line[t + 9] =  line[9] + line[t];
      }

     for( int l=0; l<=20; l++)
     {
        cout << line[l] << "  " << endl;

     }

}
