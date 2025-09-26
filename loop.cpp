#include "loop.h"
#include <iterator>
#include <iostream>
loop::loop(int s, int e)
{
  this->start = s;
  this->end = e;
  
}

void loop::assign(int a[], int b[])
{
        	
	for(this->index = this->start; this->index<=this->end; this->index++)
        {
		 a[this->index] = b[this->index];
		
	}
       
}

 // 1 2 5 6
void loop::subAdd(int a[], int b[])
{
	for(this->index = this->getStart(); this->index<=this->getEnd(); this->index++)
       {    

           
             
                  a[this->getIndex()] = b[this->getIndex() - b[this->getIndex() - this->getIndex()] ] - b[this->getIndex() - this->getIndex()];
                  cout << "LOCAL  " << a[this->getIndex()] << "INDEX " << this->getIndex() << endl;;      
               
           
 	//	cout << " local " << a[this->getIndex()] << endl;
	
         if( this->getIndex() == this->getEnd())
           {   cout << "SPECIFIC CASE " << endl; 
	      a[this->getIndex()] = b[this->getEnd() - this->getStart()] + b[this->getIndex() - this->getIndex()];	
              cout  << "LOCAL " << a[this->getIndex()];     
           } 
          
 
     }
}

void loop::moduloAdd(int a[], int b[])
{
	for(this->index = this->start; this->index<=this->end; this->index++)
        {
            if(this->getIndex()  ==  this->getStart())
             {   cout << "START CASE " << endl;
                 a[this->getIndex()] =  b[this->getEnd() -this->getIndex() + b[this->getIndex() - this->getIndex()]] + b[this->getIndex() % 3];
                 cout << "START NUMBER: " << a[this->getIndex()] << endl;
             }


	  if( this->getIndex() ==  this->getStart() + b[this->getIndex() - this->getIndex()])
	  {
             a[this->getIndex()] =  b[this->getEnd() - this->getStart() + b[this->getIndex() - this->getIndex()] ] +  b[this->getIndex() %3];   // + 2           
            } 
              printf("---------------");
          
           if(this->getIndex() == this->getEnd())
            {       	
//			8 % 3 = 2   [2] --> 3
 		   a[this->getIndex()] = a[this->getStart() - (this->getEnd() - this->getStart()) - b[this->getIndex() - this->getIndex()]] + b[this->getIndex() % 3];
//		   cout << "FINISH INDEX " <<  this->getStart() - 1 << endl;
            }		
   
        }
}
void loop::incI()
{
   this->index = this->index +1;
}
int loop::getIndex()
{
  return this->index;
}

int loop::getStart()
{
  return this-> start;
}
int loop::getEnd()
{
  return this->end;
}
