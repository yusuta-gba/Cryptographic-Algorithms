#include "permutation.h"
#include  <stdio.h>
#include <iostream>
#include <cstdio>
permutation::permutation(int * input, int n)
{	printf("Constructor begins..\n");
	this->size = n;
	this->DataField = new int[n];
	this->ResetField = new int[n];
	this->reservedField = new bool[n];
	this->index = 0;
 	this->index2 = this->index + 1;
	this->setField(input);
	printf("CONSTRUCTOR READY..\n");
	return;
}
void permutation::reset()
{
	for(int i = 0; i<this->size; i++)
	{
		this->DataField[i] = this->ResetField[i];
		this->reservedField[i] = false;
	}
		this->counter=0;
}
void permutation::p5()
{
//	p4();
//	this->reset();
	for(int i = 0; i<this->size; i++)
     	{	swap(i,this->size-1,this->DataField);
     		p4();
     		this->reset();
	}
     
}
void permutation::p4()
{
//	printf(" : : : : : : : p4 called : : : : : : :\n");	 
    for(int n2 = 0; n2 < 4; n2++)
    {
        if(compare(n2,this->reservedField))
        {            // ( x, 3)
                swap(n2, 3,this->DataField);
			// ( 0, 1, plain, 3, 0)
                permutate(this->index,this->index2,this->DataField,3,this->functionCallerCounter);
                
		fill(this->DataField[3] - 1,this->reservedField);
                n2 = -1;
                if(this->counter ==4)
                        break;
                continue;
        }

    }	

//	for(int j = 0; j< this->size; j++)
//	{
//		printf(" %d ", this->reservedField[j]);
//	}
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
		this->ResetField[j] = input[j];
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
//  printf(" %d.. \n",this->DataField[a]);
       if(B[a] == false)
	{ B[a] = true;
  	 this->counter++;
	}
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
	printf("%d %d, %02x, %d, %d\n");
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
 for( int c = 0; c<this->size; c++)
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


void permutation::p9(){ 
 for(int i = 0; i<this->size; i++) { 
 	swap(i,this->size-1,this->DataField);p9();
 this->reset(); } }
void permutation::p8(){ 
 for(int i = 0; i<this->size; i++) { 
 	swap(i,this->size-1,this->DataField);p8();
 this->reset(); } }
void permutation::p7(){ 
 for(int i = 0; i<this->size; i++) { 
 	swap(i,this->size-1,this->DataField);p7();
 this->reset(); } }
void permutation::p6(){ 
 for(int i = 0; i<this->size; i++) { 
 	swap(i,this->size-1,this->DataField);p6();
 this->reset(); } }
