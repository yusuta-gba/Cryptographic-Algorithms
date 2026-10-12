#include <stdio.h>
int counter = 0;
void permutate(int i, int j, int * A, int n, int fn);
void swap(int i, int j, int * A);
void fill(int a, bool * B);
bool compare(int n, bool * B);
int main(char  * argv[], int argc)
{

  
int A[] = {1,2,3,4};
bool B[] = {false, false, false, false};
int n = 3;
int fn = 0;
int i = 0;

   //  printf("\n-------------\n");
   int j  = i + 1;
//    printf("FIRST CALL: \n");
//    permutate(i, j, A, n, fn);
//    printf("first over\n");
//    fill(A[n],B);
    for(int n2 = 0; n2<4; n2++)
    {
	if(compare(n2,B))
        { //      printf(" n2:%d n:%d ", n2, n);
		swap(n2, n,A);
	//	printf("next call\n");
                permutate(i,j,A,n,fn);
                fill(A[n],B);
                n2 = -1;
		if(counter ==4)
			break;
		continue;
        }
        
    }
     

  return 1;  
}
bool compare(int n, bool * B)
{
   if(B[n] == true)
   {  //  printf("not used %d\n", n);
	return false; 
   }
   else
   {
	//printf("used %d\n", n);
	return true;
   }
}
void fill(int a, bool * B)
{
  B[a] = true;
  counter++;
  return;
  
}
void swap(int i, int j, int * A)
{
   int temp;
   temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}
void permutate(int i, int j, int * A, int n, int fn)
{ 
  int q2 = n;
   
  for( int q = n - 1; q>=1; q--)
  {
       q2 = q2 * q;
	
  } 
       
   if(  i ==j || fn == q2)
	return;
//   printf("%d,%d\n",i,j);
   
   swap(i,j,A); 
 for( int c = 0; c<4; c++)
    {
        printf("%d", A[c]);
    }  
   printf("\n");
 
 if( j == n-1)
  {   if( i != j -1)
      { // printf("switched i,j %d%d\n",i,j);
         permutate(++i % 3,j,A,n,++fn);
	
        
      }
      else if(i == j-1)
      {  	 
        permutate(--i % 4, j,A,n,++fn);
       
      }
        return;
  }
  else
  {
    permutate(i,++j % 4,A,n,++fn);
	return;
  }
	return;
  
}
