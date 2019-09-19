#include<iostream>
#include<cmath>
#include"complex_trig.h"

void print_menu(){
	std::cout<<"1. Печать меню.\n"<<"2. Печать двух комплексных чисел.\n"<<"3. Изменение первого комплексного числа.\n"<<"4. Изменение второго комплексного числа.\n"<<"5. Проверка их на равенство.\n"<<"6. Сумма двух комплексных чисел.\n"<<"7. Вычитание второого из первого.\n"<<"8. Вычитание первого из второго.\n"<<"9. Произведение двух комплексных чисел.\n"<<"10. Деление первого комплексного числа на второе.\n"<<"11. Деление второго комплексного числа на первое.\n"<<"12. Сопряжённое первого числа.\n"<<"13. Сопряжённое второго числа.\n"<<"0.Выход.\n";
	return;
}

int main(){
	Complex_Trig lhs( 1, 0), rhs(1, M_PI/2), ans;
	int status=1;
	while(1){
		switch(status){
			case 0 : 
				return 0;
				break;
			case 1 :
				print_menu();
				break;
			case 2 :
				std::cout<<"Первое=( "<<lhs.radius()<<" , "<<lhs.angle()<<" )\n";
				std::cout<<"Второе=( "<<rhs.radius()<<" , "<<rhs.angle()<<" )\n";
				break;
			case 3 :{
				double r, fi;
				std::cout<<"Введите модуль комплексного числа."<<std::endl;
				std::cin>>r;
				lhs.ch_radius(r);
				if(r<0) break;
				std::cout<<"Введите угол комлексного числа."<< std::endl;
				std::cin>>fi;
				lhs.ch_angle(fi);
				break;
			}
			case 4 :{
				double r, fi;
				std::cout<<"Введите модуль комплексного числа."<<std::endl;
				std::cin>>r;
				rhs.ch_radius(r);
				if(r<0) break;
				std::cout<<"Введите угол комлексного числа."<< std::endl;
				std::cin>>fi;
				rhs.ch_angle(fi);
				break;
			}
			case 5 :
				if(lhs.equ(rhs)){
					std::cout<<"Числа равны."<<std::endl;
				}else{
					std::cout<<"Числа различны."<<std::endl;
				}
				break;
			
			case 6 :
				ans=lhs.add(rhs);
				std::cout<<"( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) + ( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			case 7 :
				ans=lhs.sub(rhs);
				std::cout<<"( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) - ( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			
			case 8 :
				ans=rhs.sub(lhs);
				std::cout<<"( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) - ( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			case 9 :
				ans=lhs.mul(rhs);
				std::cout<<"( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) * ( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			
			case 10 :
				ans=lhs.div(rhs);
				if(rhs.radius()!=0)std::cout<<"( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) / ( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			case 11 :
				ans=rhs.div(lhs);
				if(lhs.radius()!=0)std::cout<<"( "<<rhs.radius()<<" , "<< rhs.angle()<<" ) / ( "<<lhs.radius()<<" , "<< lhs.angle()<<" ) = ("<<ans.radius()<<" , "<< ans.angle()<<" )"<<std::endl;  
				break;
			case 12 :
				ans=lhs.conj();
				std::cout<<"( "<<ans.radius()<<" , "<<ans.angle()<<" )"<<std::endl;
				break;
			case 13 :
				ans=rhs.conj();
				std::cout<<"( "<<ans.radius()<<" , "<<ans.angle()<<" )"<<std::endl;
				break;
			default:
			std::cout<<"Неверно введено действие."<<std::endl;
		}
		std::cout<<"ПрИгЛаШеНиЕ>>";
		std::cin>>status;
	}
}
