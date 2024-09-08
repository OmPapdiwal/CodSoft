#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	
	int number =( rand() % 100 ) + 1;
	
	int Guess=0;
	
	do{
		cout<< "Enter an Number :"<<endl;
		cin>>Guess;
		if(Guess > number)
		{
			cout<<"!!!! ----Enter Smaller Number ---- !!!!"<<endl;
		}
		else if(Guess < number)
		{
			cout<<"!!!! ----Enter Greater Number ---- !!!!"<<endl;
		}
		else{
			cout<<"!!!HURRAY !!!!!! -----You Won"<<endl;
		}
	}while(Guess!=number);
	return 0;
}
