#include "permutation.h"
#include  <stdio.h>
#include <iostream>

permutation::permutation(int * input, int n)
{	
	this->size = n;
	this->DataField = new int[n];
	this->reservedField = new bool[n];
	this->setField(input);
	return;
}
void permutation::p4()
{
	 
    for(int n2 = 0; n2 < this->size; n2++)
    {
        if(compare(n2,this->reservedField))
        { 
                swap(n2, this->size-1,this->DataField);
                permutate(this->index,this->index2,this->DataField,this->size-1,this->functionCallerCounter);
                fill(this->DataField[this->size-1],this->reservedField);
                n2 = -1;
                if(this->counter ==4)
                        break;
                continue;
        }

    }	
}
void permutation::setField(int *input)
{
	
	if (input == nullptr) {
    printf("Fehler: input ist nullptr!\n");
    return;
	}
		
        for(int j = 0; j < this->size; j++)
	{
		
		this->DataField[j] = input[j];
		this->reservedField[j] = false;
	}
	return;
}
void permutation::readField()
{
	for(int i = 0; i<this->size; i++)
	{
		printf(" %d ", DataField[i]);
	}
		printf("\n");
}
bool permutation::compare(int n, bool * B)
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
void permutation::fill(int a, bool * B)
{
  B[a] = true;
  this->counter++;
  return;

}
void permutation::swap(int i, int j, int * A)
{
   int temp;
   temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}
void permutation::permutate(int i, int j, int * A, int n, int fn)
{
  int q2 = n;

  for( int q = n - 1; q>=1; q--)
  {
       q2 = q2 * q;

  }

   if(  i ==j || fn == q2)
   {   
	  this->functionCallerCounter = 0;
	  return;
   }
   swap(i,j,A);
 for( int c = 0; c<4; c++)
    {
        printf("%d", A[c]);
    }
   printf("\n");

 if( j == n-1)
  {   if( i != j -1)
      { 
         permutate(++i % 3,j,A,n,++this->functionCallerCounter);


      }
      else if(i == j-1)
      {
        permutate(--i % 4, j,A,n,++this->functionCallerCounter);

      }
        return;
  }
  else
  {
    permutate(i,++j % 4,A,n,++this->functionCallerCounter);
        return;
  }
        return;

}
