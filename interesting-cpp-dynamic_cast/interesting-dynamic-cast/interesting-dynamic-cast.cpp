#include "stdafx.h"
#include "stdlib.h"

#define TEST_CASE3

class BaseA
{
public:
	virtual void AA() = 0;
	virtual ~BaseA() {};
};

class NewA : public BaseA
{
public:
	~NewA() { printf(__FUNCTION__ "\n"); }
	virtual void AA() override { printf(__FUNCTION__ "\n"); }
};

class BaseB
{
public:
	virtual void BB() = 0;

#ifdef TEST_CASE3
	virtual void PerfectFunctionName() = 0; // Added part
#endif

	virtual ~BaseB() {};
};

class NewB : public BaseB
{
public:
	virtual ~NewB() { printf(__FUNCTION__ "\n"); }
	virtual void BB() override { printf(__FUNCTION__ "\n"); }

#ifdef TEST_CASE3
	virtual void PerfectFunctionName() override { printf(__FUNCTION__ "\n"); } // Added part
#endif

};

BaseA* TestB()
{
	NewB *pNewB = new NewB();
	return (BaseA*)pNewB;
}

void Test_Case1()
{
	BaseA* pBaseA = TestB();
	BaseB *pBaseB = (BaseB *)pBaseA;
	delete(pBaseA);
}

void Test_Case2()
{
	BaseA* pBaseA = TestB();
	BaseB *pBaseB = (BaseB *)pBaseA;

	// added part: call virtual functions
	pBaseA->AA();
	pBaseB->BB();

	delete(pBaseA);
}

void Test_Case3()
{
	BaseA* pBaseA = TestB();
	BaseB *pBaseB = (BaseB *)pBaseA;

	// added part: call virtual functions
	pBaseA->AA();
	pBaseB->BB();

#ifdef TEST_CASE3				  
	pBaseB->PerfectFunctionName();
#endif

	delete(pBaseA);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test_Case1();
	Test_Case2();
	Test_Case3();
	system("pause");
	return 0;
}
