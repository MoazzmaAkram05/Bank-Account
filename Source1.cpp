#include<iostream>
#include<string>
using namespace std;
class BankAccount{
private:
	string name;
	double balance;
public:
	//constructor
	BankAccount(string n, double b){
		cout << "Constructor Creat account: " << n << endl;
		if (b < 0){
			throw"ERROR: Negative balance is not allowed";
		}
		name = n;
		balance = b;
	}
	//withdraw function
	void withdraw(double amount){
		cout << "Trying to withdrawn the Amount:" << amount << endl;
		if (amount>balance){
			throw"ERROR: Balance too low";
		}
		balance -= amount;
		cout << "WithDraw Successful . Balance = " << balance << endl;
	}
	//Destructor
	~BankAccount(){
		cout << "Destructor Called for: " << name << endl;
	}
};
int main(){
	//creating Account 
	cout << "\t---------Account Creation---------" << endl;
	try{
		//Creating account with valid balance
		BankAccount*ac1 = new BankAccount("Ali", 20000);
		ac1->withdraw(15000);
		//safely Deleting the account
		delete ac1;
	}
	catch (const char *msg){
		cout << msg << endl;
	}
	cout << endl;
	cout << "\t----------WithDraw Cheak----------" << endl;
	BankAccount*ac2 = NULL;
	try{
		//create account with negative value
		BankAccount*ac2 = new BankAccount("Sara", -345);
		delete ac2;
	}
	catch (const char *msg){
		cout << msg << endl;
	}
	cout << endl;
	try{
		//creating account with low balance
		BankAccount*ac3= new BankAccount("Ahmad", 678);
		ac3->withdraw(1500);
		delete ac3;
	}
	catch (const char *msg){
		cout << msg << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}