#include "rc4.h"
#include <string.h>

#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

using namespace std;


rc4::rc4(const char * plain, const char * key)
{
	for(int i = 0; plain[i] != '\0'; i++)
	{
		this->Length = i+1;
	}
		  this->plainTextLength = this->Length;
	for(int j = 0; key[j] != '\0'; j++)
	{
		this->keyLength = j+1;
	}
	
	this->keyField    =   new uint8_t[this->keyLength];
	this->keyField    =   (uint8_t *)   key;	
	this->plainField  =    new uint8_t[this->Length];
	this->plainField  =    (uint8_t *) plain;
	this->cipherField =    new  uint8_t[this->Length];
	this->MasterKey   =    new  uint8_t[this->Length];
	this->decryptedField = new uint8_t [this->Length];
}
void rc4::initialize()
{ 
    printf(" * * *INITIALIZATION  * * * \n");    
//    int array[256];
    for(int i = 0x00; i<0xff; i++)
     {  
	this->I_Box[i] = i;
    	
     }
    return;    
}
void rc4::printI_Box()
{
	printf(" * * * PRINTING * * * \n");
	int q = 0;
	for(int i = 0; i<8; i++)
        {
	 for(int j = 0x00; j<=0x1f; j++)
	 {
	        printf("%s%02x ", KGRN, this->I_Box[q]);		
	        q++;
	 }
		printf("\n");
        }

}
void rc4::select(int s) 
{
	int q = 0;
	for(int i = 0; i<8; i++)
	{
	
		for(int j = 0x00; j<= 0x1f; j++)
		{	
			if( this->I_Box[i * 32 + j] == s)
			{
			  printf("%s%02x ", KRED,this->I_Box[q]);
			  q++; 
			  continue;
			}	
			printf("%s%02x ", KGRN,this->I_Box[q]);
			q++;	
		}
		printf("\n");
	}
}

void rc4::encrypt(uint8_t K[])
{
 
	printf(" * * * * ENCRYPTION IS CALLED * * * * \n");
 
	int j = 0;
       // Änderung des Internen-Zustandes
	for(int i = 0; i<256; i++)
	{		
		j = (j + this->I_Box[i] + K[i % keyLength] ) % 256;
		this->swap(i,j);		
	}
	
	int i = 0;
	    j = 0;

      // Schlüsselgenerierung und die XOR-Operation
	for (int n  = 0; n < this->Length; n++)
	    {
		i = (i + 1) % 256;
		j = (j + this->I_Box[i]) % 256;
	         this->swap(i,j);
		 this->MasterKey[n] = this->I_Box[(this->I_Box[i] + this->I_Box[j]) % 256]; 
		 uint8_t y = *(this->plainField + n);
		 uint8_t q =  y ^ this->MasterKey[n];   
		 memset(this->cipherField+n,q, 1 * sizeof(uint8_t));
	     }
		

}

void rc4::swap(int i, int j)
{
	uint8_t temp = this->I_Box[i];
	this->I_Box[i]  = this->I_Box[j];
	this->I_Box[j]  = temp;
	return;
}
void rc4::setPlainField(const char * buf)
{
	this->plainField = (uint8_t *) buf;
	this->keyLength = 10;
	this->plainTextLength = 19;
	return;

}
void rc4::readPlainField()
{
        printf(" TRYING ARRAY INDEXING %s \n", this->plainField);
	for(int i = 0; i< this->Length; i++)
	{
		printf(" %02x ",*(this->plainField + i));
	}
	cout << endl;
}


void rc4::readCipherField()
{
	printf("READING CIPHERFIELD\n");
	printf(" %s \n", this->cipherField);
	for(int i = 0; i< this->Length; i++)
	{
	         printf(" %02x ", *(this->cipherField + i));
        }
	return;
}

void rc4::readDecryptedField()
{
	printf(" %s \n", this->decryptedField);
	for(int i = 0; i<this->Length; i++)
	{
		 printf(" %02x ", this->decryptedField[i]);
	}
}
void rc4::setKeyField(uint8_t * key)
{
	keyField = new uint8_t[this->keyLength];
	keyField = key;
}

void rc4::readKeyField()
{
	printf("READING KEYFIELD\n");
	printf(" %s \n", this->keyField);
	for(int i = 0; i < 19; i++)
	{
		printf(" %02x ", *(this->keyField + i));
	}
	return;
}
void rc4::decrypt()
{	printf(" DECRYPTION CALLED \n");
	for(int i = 0; i<19; i++)
	{
	  this->decryptedField[i] = this->MasterKey[i] ^ *(this->cipherField+i);	
	  
	}
	printf(" ....");
	return;
}
