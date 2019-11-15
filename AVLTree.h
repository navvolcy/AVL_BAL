#include<string>
#include"Node.h"

using namespace std;

class AVLTree 
{
public:
	Node* root = nullptr;
	// constructor and destructor
	AVLTree();
	~AVLTree();
	// these have to be done recursively
	//functions: how and what my BST works
	// the will call their helper recursively
	void Insert(int value);
	Node* Search(int value);
	void Remove(int value);
	void PreOrderTraversal();
	  

	Node* GetRoot() { return root; }


	void Print();
	int Size();

private:
	Node* InsertHelper(Node* cursor, int value);
	Node* SearchHelper(Node* cursor, int value);

	Node* RemoveHelper(Node* cursor, int value);
	void PreorderHelper(Node* cursor);
	void BtsDestructor(Node* cursor);

	void PrintHelper(string& offset, Node* cursor);
	int SizeHelper(Node* cursor);

	Node* re_Balance(Node* cursor);
	int Balance_Factor(Node* cursor);
	Node* Ro_right(Node* cursor);
	Node* Ro_left(Node* cursor);
	

	

};
