#pragma once
#define FQINFO FQInfo
#include <iostream>
using namespace std;
struct FQInfo
{
	int nKey;
	int* p; //tab. dwuelement.
	FQInfo(int x);
	virtual ~FQInfo();
	friend ostream& operator << (ostream& out, const FQINFO& info);
};
