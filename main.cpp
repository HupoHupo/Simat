#include <iostream>
#include <stdarg.h>
#include "simat.h"

extern void QPrint(const char *format,...)
{
    char buffer[1024];
    va_list p;
    va_start(p, format);
    int count = vsnprintf(buffer,sizeof(buffer) - 1,format,p);
    va_end(p);

    if(count < 1) return;
    buffer[1023] = 0;
    std::cout << buffer;
}


int main()
{
	using namespace QSpace;
	Matrix<float,3,3> mat;

	mat << 1,2,3,
           4,5,6,
           7,8,11;

    mat.Print(" % .3f");

	return 0;
}

