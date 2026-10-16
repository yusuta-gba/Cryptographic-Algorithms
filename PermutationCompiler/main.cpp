#include <stdio.h>
#include "permutation.h"
#include <iostream>
#include <vector>
void permute(std::vector<int>&arr,int start);

int main(char * argv[], int argc)
{
          int A[] = {1,2,3,4};
	  int B[] = {1,2,3,4,5};
	  int C[] = {1,2,3};
	  
	  int fn = 0;
	  permutation * p1  = new permutation(A,3);
//		        p1->p4();
//	permutation * p2 = new permutation(B,5);
//		p2->p5();



		std::vector<int> arr = {1, 2, 3};
		permute(arr, 0);
		p1->permutate(0,1,C,3,fn);
	return 1;
}
void permute(std::vector<int>& arr, int start) {
   	printf("THIS FUNCTION IS CALLED: ");
      if (start == (int)arr.size()) {
        for (int x : arr) std::cout << x << " ";
        std::cout << "\n";
        return;
    }
    for (int i = start; i < (int)arr.size(); ++i) {
	printf("WITHIN LOOP: \n");
        std::swap(arr[start], arr[i]);
        permute(arr, start + 1);
        std::swap(arr[start], arr[i]); // zurücktauschen
    }
}
