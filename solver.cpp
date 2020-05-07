#include <string>
#include <iostream>
#include <complex>
#include "solver.hpp"
//using solver::RealVariable, solver::solve, solver::ComplexVariable;
using namespace solver;

double solver::solve(RealVariable var){
    if(var.getA()==0 && var.getB()==0)  throw std::invalid_argument("Error!!!");
    if(var.getA()>0  && var.getB()==0 && var.getC()<0)  throw std::invalid_argument("Error!!");
    double a = var.getA(),b = var.getB(), c = var.getC();
    double ans=0;
    if(a!=0)  ans = (-b + sqrt(b*b-4*a*c))/(2*a);
    else ans = c/b;
    return ans;
}
std::complex<double> solver::solve(ComplexVariable var){
    double a = var.getA(),b = var.getB();
    std::complex<double> c = var.getC();
    std::complex<double> ans=0;
    if(a!=0)  ans = (-b + sqrt(b*b-4*a*c))/(2*a);
    else ans = c/b;
    return ans;

}
RealVariable solver::operator*(const RealVariable& x, const double& num){
    RealVariable ans;
    if(x.a==0) ans.setB(1);
    ans.setA(x.a*num);
    ans.setB(x.b*num);
    ans.setC(x.c*num);
    return ans;
}
RealVariable solver::operator-(const RealVariable& x, const double& num){
    RealVariable ans;
    ans.setB(x.b);
    ans.setA(x.a);
    ans.setC(x.c-num);
    return ans;
}
RealVariable solver::operator==(const RealVariable& x, const double& num){
    RealVariable ans;
    if(x.a==0) {
        ans.setB(x.b);
        ans.setA(x.a);
    }
    else {
        ans.setB(-x.b);
        ans.setA(-x.a);
    }
    ans.setC(num-x.c);
    return ans;
}
RealVariable solver::operator^(const RealVariable& x, const double& num){
    RealVariable ans;
    if(num==1) ans.setB(num);
    else {
        ans.setA(1);
        ans.setB(0);
    }
    return ans;
}
RealVariable solver::operator+(const RealVariable& x,const RealVariable& y){
    RealVariable ans;
    ans.setA(x.a+y.a);
    ans.setB(x.b+y.b);
    ans.setC(x.c+y.c);
    return ans;
}
RealVariable solver::operator-(const RealVariable& x,const RealVariable& y){
    RealVariable ans;
    ans.setA(x.a-y.a);
    ans.setB(x.b-y.b);
    ans.setC(x.c-y.c);
    return ans;
}
RealVariable solver::operator==(const RealVariable& x,const RealVariable& y){
    RealVariable ans;
    ans.setA(x.a-y.a);
    ans.setB(x.b-y.b);
    ans.setC(x.c-y.c);
    return ans;
}
RealVariable solver::operator+( const double& num,const RealVariable& y){
    RealVariable ans;
    ans.setA(y.getA());
    ans.setB(y.getB());
    ans.setC(y.getC()+num);
    return ans;

}
RealVariable solver::operator+(const RealVariable& x, const double& num){
    RealVariable ans;
    ans.setA(x.a);
    ans.setB(x.b);
    ans.setC(x.c+num);
    return ans;
}
RealVariable solver::operator/(const RealVariable& x, const double& num){
    RealVariable ans;
    ans.setA(x.a/num);
    ans.setB(x.b/num);
    ans.setC(x.c/num);
    return ans;
}
RealVariable solver::operator*(const double& num,const RealVariable& x){
    RealVariable ans;
    ans.setB(x.b*num);
    ans.setA(x.a*num);
    ans.setC(x.c*num);
    return ans;
}


ComplexVariable solver::operator*(const double& num,const ComplexVariable& x){
    ComplexVariable ans;
    ans.setB(x.b*num);
    ans.setA(x.a*num);
    ans.setC(x.c*num);
    return ans;
} //
ComplexVariable solver::operator+(const RealVariable& x,const ComplexVariable& y){
    ComplexVariable ans;
    ans.setA(x.getA()+y.a);
    ans.setB(x.getB()+y.b);
    ans.setC(x.getC()+y.c);
    return ans;
}
ComplexVariable solver::operator+(const ComplexVariable& x,const ComplexVariable& y){
    ComplexVariable ans;
    ans.setA(x.getA()+y.a);
    ans.setB(x.getB()+y.b);
    ans.setC(x.getC()+y.c);
    return ans;
}
ComplexVariable solver::operator-(const ComplexVariable& x,const ComplexVariable& y){
    ComplexVariable ans;
    ans.setA(x.a-y.a);
    ans.setB(x.b-y.b);
    ans.setC(x.c-y.c);
    return ans;
}
ComplexVariable solver::operator==(const ComplexVariable& x,const ComplexVariable& y){
    ComplexVariable ans;
    ans.setA(x.a-y.a);
    ans.setB(x.b-y.b);
    ans.setC(x.c-y.c);
    return ans;
}
ComplexVariable solver::operator-(const ComplexVariable& x, const double& num){
    ComplexVariable ans;
    ans.setB(x.b);
    ans.setA(x.a);
    ans.setC(x.c-num);
    return ans;
}
ComplexVariable solver::operator/(const ComplexVariable& x, const double& num){
    ComplexVariable ans;
    ans.setA(x.a/num);
    ans.setB(x.b/num);
    ans.setC(x.c/num);
    return ans;
}
ComplexVariable solver::operator^(const ComplexVariable& x, const double& num){
    ComplexVariable ans;
    if(num==0)  throw std::invalid_argument("y not exist");
    if(num==1) ans.setB(num);
    else {
        ans.setA(1);
        ans.setB(0);
    }
    return ans;
}
ComplexVariable solver::operator==(const ComplexVariable& x, const double& num){
    ComplexVariable ans;
    if(x.a==0) {
        ans.setB(x.b);
        ans.setA(x.a);
    }
    else {
        ans.setB(-x.b);
        ans.setA(-x.a);
    }
    ans.setC(num-x.c);
    return ans;
}
ComplexVariable solver::operator+(const double& num,const ComplexVariable& x){
    ComplexVariable ans;
    ans.setA(x.a);
    ans.setB(x.b);
    ans.setC(x.c+num);
    return ans;
}
ComplexVariable solver::operator+(const ComplexVariable& x, const double& num){
    ComplexVariable ans;
    ans.setA(x.a);
    ans.setB(x.b);
    ans.setC(x.c+num);
    return ans;
}
ComplexVariable solver::operator+(const ComplexVariable& x, std::complex<double> num){
    ComplexVariable ans;
    ans.setA(x.getA());
    ans.setB(x.getB());
    ans.setC(x.getC()+num);
    return ans;
}
ComplexVariable solver::operator*(const ComplexVariable& x, std::complex<double> num){
    ComplexVariable ans;
    ans.setA(x.getA());
    ans.setB(x.getB());
    ans.setC(x.getC()*num);
    return ans;
}