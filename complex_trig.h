#ifndef _COMPLEX_TRIG_
#define _COMPLEX_TRIG_
class Complex_Trig{
	public:
		Complex_Trig(double R, double Fi); // создать комплексное число на основе радиуса и углa от 0 до 2*пи
		Complex_Trig();
		Complex_Trig add(const Complex_Trig& b);
		Complex_Trig sub(const Complex_Trig& b);
		Complex_Trig mul(const Complex_Trig& b); 
		Complex_Trig div(const Complex_Trig& b); 
		bool equ(const Complex_Trig& b); //пара поэлементно равна
		Complex_Trig conj(); //conj(r, fi)= (r, -fi)
		double radius();
		double angle();
		void ch_radius(double R);
		void ch_angle(double Fi);	
	private:
		double _r; //radius
		double _fi; //angle
};
#endif
