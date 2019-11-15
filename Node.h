#include <string>
#include "Observer.h"

class Node
{
public:
	Node(int value, Node* left, Node* right);
	~Node();

	bool IsLeaf();
	void UpdateHeight();


	int value;
	int height;
	Node* left;
	Node* right;

	Observer observer;
private:


};
