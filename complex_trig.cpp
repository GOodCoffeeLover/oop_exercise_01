#include<iostream>
#include"complex_trig.h"
#include<cmath>
Complex_Trig::Complex_Trig(double R, double Fi){
	if(R>=0) _r=R; else std::cerr<<"Модлуь числа меньше нуля."<<std::endl; 
	while(Fi>=2*M_PI) Fi-=2*M_PI;
	while(Fi<0) Fi+=2*M_PI;
	if(R==0)_fi=0; else _fi=Fi;
}
Complex_Trig::Complex_Trig(){
	_r=0;
	_fi=0;

}
Complex_Trig Complex_Trig::add(const Complex_Trig& b){
	Complex_Trig a;
	a._r=(double) sqrt((_r*cos(_fi)+b._r*cos(b._fi))*(_r*cos(_fi)+b._r*cos(b._fi)) + (_r*sin(_fi)+b._r*sin(b._fi))*(_r*sin(_fi)+b._r*sin(b._fi)));
	if(a._r>0){ 
		a._fi=acos((_r*cos(_fi)+b._r*cos(b._fi))/a._r);
		if(_r*sin(_fi)+b._r*sin(b._fi)<0) a._fi=2*M_PI-a._fi;
	}else{ a._r=0; a._fi=0; }
	return a;
}
Complex_Trig Complex_Trig::sub(const Complex_Trig& b){
	Complex_Trig a;
	a._r=(double) sqrt((_r*cos(_fi)-b._r*cos(b._fi))*(_r*cos(_fi)-b._r*cos(b._fi)) + (_r*sin(_fi)-b._r*sin(b._fi))*(_r*sin(_fi)-b._r*sin(b._fi)));
	if(a._r>0){	
		a._fi=acos((_r*cos(_fi)-b._r*cos(b._fi))/a._r);
		if(_r*sin(_fi)-b._r*sin(b._fi)<0) a._fi=2*M_PI-a._fi;
	}else{a._r=0; a._fi=0;}
	return a;
}

Complex_Trig Complex_Trig::mul(const Complex_Trig& b){
	Complex_Trig a;
	a._r=_r*b._r;
	if(_fi+b._fi>2*M_PI){
		a._fi=_fi+b._fi-2*M_PI;
	}else{
		a._fi=_fi+b._fi;	   
	}
	if(a._r==0) a._fi=0;
	return a;
}
 
Complex_Trig Complex_Trig::div(const Complex_Trig& b){
	Complex_Trig a(0, 0);
	if(b._r==0){
		std::cerr<<"Деление на ноль. Деление не произведенно."<<std::endl;
		return a;
	}
	a._r=_r/b._r;
	if(_fi-b._fi>=0) a._fi=_fi-b._fi; else a._fi=2*M_PI+(_fi-b._fi);
	if(a._r==0) a._fi=0;
	return a;
}
double Complex_Trig::radius(){
	return _r;
} 
double Complex_Trig::angle(){
	return _fi;
}
void Complex_Trig::ch_radius(double R){
	if(R>0) _r=R; else{ 
		if(R<0) std::cerr<<"Модлуь числа меньше нуля."<<std::endl; 
		_r=0; _fi=0;
		}
	return;
}

void Complex_Trig::ch_angle(double Fi){
	if(_r==0) return;
	while(Fi>=2*M_PI) Fi-=2*M_PI; 
	while(Fi<0) Fi+=2*M_PI; 
	_fi=Fi;
	return;
}
bool Complex_Trig::equ(const Complex_Trig& b){
	return((int) _fi*10000) == ((int) b._fi*10000) && ((int)_r*10000) ==((int)b._r*10000);
}

Complex_Trig Complex_Trig::conj(){
	Complex_Trig a; 
	a._r=_r;
	if(_fi!=0) a._fi=2*M_PI-_fi; else a._fi=0;
	return a;
}
