#include "rec.h"

rec::rec(){

}

void rec::simu(Matrix y,Matrix u,int n){


    for(int i=n; i < y.length() ;i++)
        Fia.add(i-n+1,1,-y(i,1));


    for(int i=n; i < u.length() ;i++)
        Fib.add(i-n+1,1,u(i,1));


    Fi=Fia|Fib;


    for(int i=n+1; i <= y.length() ;i++)
        this->teta1.add(i-n,1,y(i,1));

    this->teta1=((~Fi*Fi)^-1)*~Fi*(this->teta1);

    C.eye(n);

    this->yest=y;

    for(int k=n+1; k <= y.length() ;k++){
        Matrix fi;

        fi.add(1,1,-this->yest(k-1,1));
        fi.add(1,2,u(k-1,1));

        p=fi*this->teta1;
        this->yest.add(k,1,p(1,1));
    }

    erro=y-this->yest;
    this->somaErro=mean(abs(erro));

    for(int i=1; i <= n-1 ;i++){

        X1=Fi;

        for(int j=n-i; j <= y.length()-1-i ;j++)
            X2a.add(1+j-n+i,1,-y.getMat(j,1));

        for(int j=n-i; j <= u.length()-1-i ;j++)
            X2b.add(1+j-n+i,1,u(j,1));


        X2=X2a|X2b;


        C=(~X1*X1)^(-1);

        B=(~X2*X2-(~X2)*X1*C*(~X1)*X2)^(-1);

        A=C*(~X1)*X2*B;

        for(int j=n+1; j <= y.length() ;j++)
            ya.add(j-n,1,y(j,1));

        this->teta2=B*(~X2)*(ya-X1*this->teta1);
        this->teta1=this->teta1-A*(~X2)*(ya-X1*this->teta1);

        Fi=X1|X2;

        this->teta=((this->teta1)||(this->teta2));

        for(int k=n+1; k <= y.length() ;k++){
            Matrix fi;
            fi.add(1,3,0);
            fi.add(1,4,0);
            for(int j=1; j <= i+1 ;j++){

                fi.add(1,1,fi(1,3));
                fi.add(1,2,fi(1,4));
                fi.add(1,3,-this->yest(k-j,1));
                fi.add(1,4,u(k-j,1));

            }
            p=fi*this->teta;

        this->yest.add(k,1,p(1,1));

       }

        for(int j=n+1; j <= this->yest.length() ;j++)
        erro.add(j-n,1,this->yest(j,1));

        erro=Fi*this->teta-erro;

        p=mean(abs(erro));
        this->somaErro.add(this->somaErro.getRows(),i+1,p(1,1));

        this->teta1=this->teta;

}
cout<<"teta=\n ";
this->teta.print();
cout<<"\n\nsoma do Erro=\n ";
this->somaErro.print();
cout<<"\n\nY estimado=\n ";
this->yest.print();
cout<<"\n\nerro=\n ";
erro.print();
}
