#include <stdio.h>
#include <stdint.h>
#include <iostream>

using namespace std;
class rc4{

	public:
   		
		uint8_t I_Box[256];
		uint8_t  * plainField;
		uint8_t  * keyField;
		uint8_t  * cipherField;
		uint8_t  * MasterKey;   		
		uint8_t  * decryptedField;
		int keyLength;
		int plainTextLength;
		int Length;		
		rc4(const char *a, const char * b);
		void setPlainField( const char * buf);
		void setKeyField(uint8_t * key);
		void readPlainField();
		void readCipherField();
		void readKeyField();
		void readDecryptedField();
		void initialize();
   		void select(int s);
		void printI_Box();
		void encrypt(uint8_t K[]);
		void decrypt();
		void swap(int i, int j);
};
