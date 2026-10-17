using namespace std;
class permutation
{	private:
	int counter = 0;
	int * DataField;
	int * ResetField;
	int   size;
	bool * reservedField;
	int    functionCallerCounter;
	int    index = 0;
	int    index2 =1;
	int    countsCombination;	
	public:
	permutation(int * input, int n);
	void setField(int * input);
	void readField();
	void reset();
	void p4();
	void p5();
	void permutate(int i, int j, int * A, int n, int fn);
	void swap(int i, int j, int * A);
	void fill(int a, bool * B);
	void  faculty();
	bool compare(int n, bool * B);

// };		Dieses Zeichen automatisch von dem Makefile hinzufügen lassen.
		/*												  *
		 *												  *
		 * Um die anderen Permutations-Funktionen für größere Arrays als C++Funktion zu generieren lassen */


void p9();
void p8();
void p7();
void p6();
};
