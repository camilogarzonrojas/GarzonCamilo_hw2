#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

double m=1000.0,k=2000.0,y=0.0,w=sqrt(k/m);
const int steps=10000;
double dt=10.0/steps;
double dw=sqrt(k/m)*(3-0.2)/100;
double a1[steps];
double a2[steps];
double a3[steps];
double u1[steps];
double v1[steps];
double u2[steps];
double v2[steps];
double u3[steps];
double v3[steps];
double A1(int step);
double U1(int step);
double V1(int step);
double A2(int step);
double U2(int step);
double V2(int step);
double A3(int step);
double U3(int step);
double V3(int step);
double F(double t)
{
    return sin(w*t);
}

double A1(int step)
{
    if(a1[step]!=-1)
        return a1[step];
    a1[step]=(-2*k*U1(step)+k*U2(step)+F(step*dt))/m;
    return a1[step];
}

double A2(int step)
{
    if(a2[step]!=-1)
        return a2[step];
    a2[step]=(k*U1(step)-2*k*U2(step)+k*U3(step))/m;
    return a2[step];
}

double A3(int step)
{
    if(a3[step]!=-1)
        return a3[step];
    a3[step]=(k*U2(step)-k*U3(step))/m;
    return a3[step];
}

double U1(int step)
{
    if(step==0)
        return 0.0;
    if(u1[step]!=-1)
        return u1[step];
    u1[step]=U1(step-1)+V1(step-1)*dt+0.5*A1(step-1)*dt*dt;
    return u1[step];
}

double U2(int step)
{
    if(step==0)
        return 0.0;
    if(u2[step]!=-1)
        return u2[step];
    u2[step]=U2(step-1)+V2(step-1)*dt+0.5*A2(step-1)*dt*dt;
    return u2[step];
}

double U3(int step)
{
    if(step==0)
        return 0.0;
    if(u3[step]!=-1)
        return u3[step];
    u3[step]=U3(step-1)+V3(step-1)*dt+0.5*A3(step-1)*dt*dt;
    return u3[step];
}

double V1(int step)
{
    if(step==0)
        return 0.0;
    if(v1[step]!=-1)
        return v1[step];
    v1[step]=V1(step-1)+0.5*(A1(step)+A1(step-1))*dt;
    return v1[step];
}

double V2(int step)
{
    if(step==0)
        return 0.0;
    if(v2[step]!=-1)
        return v2[step];
    v2[step]=V2(step-1)+0.5*(A2(step)+A2(step-1))*dt;
    return v2[step];
}

double V3(int step)
{
    if(step==0)
        return 0.0;
    if(v3[step]!=-1)
        return v3[step];
    v3[step]=V3(step-1)+0.5*(A3(step)+A3(step-1))*dt;
    return v3[step];
}

void inicializarArreglos()
{
    for(int i=0;i<steps;i++)
	{
        u1[i]=-1;
        v1[i]=-1;
        u2[i]=-1;
        v2[i]=-1;
        u3[i]=-1;
        v3[i]=-1;
        a1[i]=-1;
        a2[i]=-1;
        a3[i]=-1;
	}
}

void EscribirDatosParte1()
{
    freopen("datosOde.dat","w",stdout);
    for(int i=0;i<steps;i++)
	{
        cout<<U1(i)<<" "<<U2(i)<<" "<<U3(i)<<" "<<i*dt<<endl;
    	}
}

double amplitudMaxima()
{
    double maxU=-10000;
    double minU=10000;
    for(int i=0;i<steps;i++)
	{
        maxU=max(max(max(U1(i),U2(i)),U3(i)),maxU);
        minU=min(min(min(U1(i),U2(i)),U3(i)),minU);
    	}
    return (maxU-minU);
}

void EscribirDatosParte2()
{
    freopen("datosOde2.dat","w",stdout);
    for(int i=0;i<100;i++ )
	{
        w=dw*i+0.2*sqrt(k/m);
        inicializarArreglos();
        double amplitud=amplitudMaxima();
        cout<<amplitudMaxima()<<" "<<w<<endl;
    	}

}

int main()
{
    inicializarArreglos();
    EscribirDatosParte1();
    EscribirDatosParte2();
	return 0;
}
