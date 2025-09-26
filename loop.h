#include <stdio.h>
using namespace std;

class loop
{
  public:
   int start;
   int end;
   int index;

loop(int s, int e);

void assign(int a[], int b[]);

void subAdd(int a[], int b[]);
void moduloAdd(int a[], int b[]);
void incI();

int getIndex();
int getStart();
int getEnd();
};
