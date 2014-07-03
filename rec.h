#ifndef REC_H
#define REC_H
#include "matrix.h"



class rec
{
protected:
    Matrix Fi,Fia,Fib,X1,X2,X2a,X2b,A,B,C,teta1,teta2,ya,p;

public:
    Matrix somaErro,yest,erro,teta;
    rec();
    void simu(Matrix y, Matrix u, int n);

};

#endif // REC_H
