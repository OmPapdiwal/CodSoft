#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double num1,num2;
	int operations;
	
	cout<<"Enter the First Number "<<endl;
	cin>>num1;
	cout<<"Enter the Second Number "<<endl;
	cin>>num2;
	
	cout<<"Enter the Number of Operation You Wanted To Perform : 1.Addition /n 2.Substraction /n 3.Multiplication /n 4.Division /n"<<endl;
	
	cin>>operations;
	if(operations == 1)
	{
		cout<<"The Addition is:"<<num1 + num2 <<endl;
	}
	else if(operations == 2)
	{
		cout<<"The Substraction is:"<<num1 - num2 <<endl;
	}
	else if(operations == 3)
	{
		cout<<"The Multiplication  is:"<<num1 * num2 <<endl;
	}
	else if(operations == 4)
	{
		cout<<"The Division is:"<<num1 / num2 <<endl;
	}
	else{
		cout<<"Enter Valid Option"<<endl;
	}
		return 0;
}
