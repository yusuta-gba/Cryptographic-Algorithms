#include <stdio.h>
#include "permutation.h"
int main(char * argv[], int argc)
{
          int A[] = {1,2,3,4};
	  int B[] = {1,2,3,4,5};
//	  permutation * p1  = new permutation(A,4);
//		        p1->p4();
	permutation * p2 = new permutation(B,5);
		p2->p5();
	return 1;
}
