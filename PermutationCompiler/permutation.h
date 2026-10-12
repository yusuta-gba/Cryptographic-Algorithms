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
	bool compare(int n, bool * B);
};
