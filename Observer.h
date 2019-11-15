#ifndef __OBSERVER__
#define __OBSERVER__
class Observer
{
public:
	Observer() {
		++numConstructions;
	}
	~Observer() {
		++numDestructions;
	}
	static int numConstructions;
	static int numDestructions;
};
#endif
