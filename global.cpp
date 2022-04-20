#include "global.h"
FQInfo::FQInfo(int x)
{
	nKey = x;
	p = new int[2];
}
FQInfo::~FQInfo()
{
	delete [] p;
}
ostream& operator << (ostream& out, const FQINFO& info)
{
	out << "nKey = " << info.nKey << endl;
	//out << "p = " << info.p[1] << ", " << info.p[2] << endl;
	return out;
}