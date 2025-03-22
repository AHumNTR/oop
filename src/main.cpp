
#include <iostream>
using namespace std ;
class BankAccount{
	private:
	string customerName;
	int accountNumber;
	double balance;
	int securityPin;
	bool isFrozen;
	public:
	BankAccount(string name, int accNum,double initialBalance,int pin,bool isItFrozen=true){
		customerName=name;
		accountNumber=accNum;
		balance=initialBalance;
		securityPin=pin;
		isFrozen=isItFrozen;
	 
	}
	double getBalance(){ return balance;}
	void deposit(double amount) {if(!isFrozen)balance += amount;}
	
	void withdraw(double amount){if(!isFrozen)balance -=amount;}
	bool isAccountFrozen(){return isFrozen;}
	void unFreezeAccount(int pin){
		if(pin==securityPin)isFrozen=false;
	}
	void setBalance(double newBalance) {balance=newBalance;}
};
class BankEmployee{
	string employeeName;
	int employeeID;
	string jobTitle;
	BankEmployee(string name,int id,string title){
		employeeName=name;
		employeeID=id;
		jobTitle=title;
	}
	void accessAccount(BankAccount *acc);
	void requestUnfreeze(BankAccount *acc,int pin){
		acc->unFreezeAccount(pin);
	}





;
};
int main(){
	

	cout<<"balls"<<endl;
	return 0;
}
