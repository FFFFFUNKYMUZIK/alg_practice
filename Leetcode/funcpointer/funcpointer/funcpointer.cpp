#include "stdafx.h"

#if 1

#include <iostream>

using namespace std;

int(*pfn)(int, int);
typedef int(*pfntype)(int, int);

int add_(int a, int b) {
	return a + b;
}

int minus_(int a, int b) {
	return a - b;
}

class funcpclass {
public:
	int cadd(int a, int b) { return a + b; };
	int cminus(int a, int b) { return a - b; };

};


int(funcpclass::*cpfn)(int, int);
typedef int(funcpclass::*cpfntype)(int, int);



int main()
{
	pfn = add_;
	pfntype testpf;
	testpf = minus_;
	
	cout << "pfn(3,4) : " << pfn(3, 4) << endl;
	//cout << "*pfn(3,4) : " << (*pfn)(3, 4) << endl; /*error!*/
	cout << "(*pfn)(3,4) : " << (*pfn)(3, 4) << endl;
	cout << "(*****pfn)(3,4) : " << (*****pfn)(3, 4) << endl;
	cout << "testpf(3,4) : " << testpf(3, 4) << endl;
	cout << "(*****testpf)(3,4) : " << (*****testpf)(3, 4) << endl;

	//cpfn = funcpclass::cadd; /*error!*/
	cpfn = &funcpclass::cadd;
	cpfntype testcpf;
	testcpf = &funcpclass::cminus;

	funcpclass cl;
	funcpclass* pcl = &cl;

	cout << "(cl.*cpfn)(3, 4) : " << (cl.*cpfn)(3, 4) << endl;
	cout << "(pcl->*cpfn)(3, 4) : " << (pcl->*cpfn)(3, 4) << endl;
	//cout << "(pcl->*cpfn)(3, 4) : " << (pcl->cpfn)(3, 4) << endl; /*error!*/
	cout << "(cl.*testcpf)(3, 4) : " << (cl.*testcpf)(3, 4) << endl;
	cout << "(pcl->*testcpf)(3, 4) : " << (pcl->*testcpf)(3, 4) << endl;

	system("pause");
    return 0;
}

#else

#include <stdlib.h>
#include <iostream>

class CFunc
{
public:
	int (CFunc::*pFunc)(int, int);
	int GetArea(int x, int y);
	void CallFunc(void) { (this->*pFunc)(3, 4); } // CallFunc 함수호출시 자체 오버헤드를 줄이기 위해 inline
	CFunc();
	~CFunc() {}
};

CFunc::CFunc()
{
	pFunc = GetArea;
}
int CFunc::GetArea(int x, int y)
{
	return x * y;
}

using namespace std;
class fruit
{
public:
	fruit() { f = &fruit::compare; }
	int (fruit::*f)(const int*, const int*);
	int compare(const int *one, const int *two)
	{
		return ((*one == *two) ? 0 : *one > *two);
	}
} apple;

int funcptr(const void* one, const void* two)
{
	return ((apple.*apple.f)((const int *)one, (const int *)two));
};

int a[3] = { 3, 2, 1 };
int main()
{
	int i;
	cout << "before ";
	for (i = 0; i < 3; i++) cout << a[i] << "  ";
	cout << endl;
	qsort(a, 3, sizeof(a[0]), funcptr);
	cout << "after ";
	for (i = 0; i < 3; i++) cout << a[i] << "  ";
	cout << endl;
	return 0;
}

#endif