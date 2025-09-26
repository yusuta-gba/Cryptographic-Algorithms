#include <stdio.h>
#include "loop.h"
#include <iostream>
using namespace std;

int main( char * argv[], int argc)
{
	loop * l1 = new loop(0,1);
	loop * l2 = new loop(3,5);
        int line[9];
	int joker[] = { 1, 2, 5, 6};
        l1->assign(line, joker);
	line[l1->index] = line[l1->index-2]  + line[l1->index-1];
        l1->incI();
        l2->index = l1->getIndex();
	l2->subAdd(line,joker);	
        loop *  l3 = new loop(l2->getIndex(), l2->getIndex() + (l2->getEnd() - l2->getStart()));
        l3->moduloAdd(line, joker); 
        cout << "-----------------------------------------" << endl;
	for(int i = 0; i<9; i++)
		cout << "Line:  " << line[i] << endl;;
       
 return 1;
}
