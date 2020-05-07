#ifndef SOLVER_HPP_
#define SOLVER_HPP_
#include <string>
#include <iostream>
#include <complex>

namespace solver{

    class RealVariable{
        double a;
        double b;
        double c;
    public:
        double getA() const {return a;}
        double getB() const {return b;}
        double getC() const {return c;}
        void setA(double a){this->a=a;}
        void setB(double b){this->b=b;}
        void setC(double c){this->c=c;}
        RealVariable(double y=0,double b=1,double c=0):c(c),b(b),a(y){};
        //RealVariable(){}
       friend RealVariable operator*(const RealVariable& x, const double& num);
        friend RealVariable operator-(const RealVariable& x, const double& num);
        friend RealVariable operator==(const RealVariable& x, const double& num);
        friend RealVariable operator^(const RealVariable& x, const double& num);
        friend RealVariable operator+(const RealVariable& x,const RealVariable& y);
        friend  RealVariable operator-(const RealVariable& x,const RealVariable& y);
        friend  RealVariable operator==(const RealVariable& x,const RealVariable& y);
        friend RealVariable operator+(const RealVariable& x, const double& num);
        friend RealVariable operator/(const RealVariable& x, const double& num);
        friend RealVariable operator*(const double& num,const RealVariable& x);
        friend RealVariable operator+( const double& num,const RealVariable& y);
    };

    class ComplexVariable {
        double a;
        double b;
        std::complex<double> c;
    public:
        double getA() const {return a;}
        double getB() const {return b;}
        std::complex<double> getC() const {return c;}
        void setA(double a){this->a=a;}
        void setB(double b){this->b=b;}
        void setC(std::complex<double> c){this->c=c;}
        ComplexVariable(double a=0, double b=1, std::complex<double> compV=0):a(a),b(b),c(compV){};
        //ComplexVariable(){}
        friend  ComplexVariable operator*(const double& num,const ComplexVariable& x);
        friend   ComplexVariable operator+(const RealVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable& y);
        friend  ComplexVariable operator==(const ComplexVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator-(const ComplexVariable& x, const double& num);
        friend ComplexVariable operator/(const ComplexVariable& x, const double& num);
        friend ComplexVariable operator^(const ComplexVariable& x, const double& num);
        friend ComplexVariable operator==(const ComplexVariable& x, const double& num);
        friend  ComplexVariable operator+(const double& num,const ComplexVariable& x);
        friend  ComplexVariable operator+(const ComplexVariable& x, const double& num);
        friend  ComplexVariable operator+(const ComplexVariable& x, std::complex<double> num);
        friend  ComplexVariable operator*(const ComplexVariable& x, std::complex<double> num);
    };
    double solve(RealVariable var);
    std::complex<double> solve(ComplexVariable var);
}











#endif