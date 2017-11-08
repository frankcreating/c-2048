#include<iostream>
#include <string>
#include <conio.h>
using namespace std;
#ifndef head
#define head

class board{

public:

	void key_input(){
	int a;
	while(1){
	a=getch();
	check_input(a);
	if (a==27){
		cout << "your enter quit"<<endl;
		break;
	};//end of enfloog judge

};//end of while
	};//end of key_input
	void check_input(int x){
	// int up=119;
	// // up=119;
	// const int down=115;
	// const int left=97;
	// const int right=100;
	int key=x;
		switch(key){
			case 119 : cout << "up"<<endl;break;
			case 115:cout<< "down"<<endl;break;
			case 97:cout<<"left"<<endl;break;
			case 100:cout <<"right"<<endl;break;
			default:cout <<"illigle input,please checkout"<<endl;break;
		};

	};
};

#endif