#include <vector>
using namespace std;
class BankAccount {
private:
	string name;
	int accountnum;
	double balance;
public:
	BankAccount(string n, int ac, double bal) {
		name = n;
		accountnum = ac;
		balance = bal;
	}
	string getname() {
		return name;
	}
	double getbalance() {
		return balance;
	}
	int getaccountnum() {
		return accountnum;
	}
  void deposit(double amount){
    balance+=amount;
  }
  void withdraw(double amount){
    if(balance >= amount){
      balance-=amount;
      cout<<"\t\tAmount withdraw successfully ......."<<endl;
    }
    else{
      cout<<"\t\t Insufficient Balance ...."<<endl;
    }
  }

};
class Bankmanagement {
private:
	vector<BankAccount> accounts;
public:
	void AddAccount(string name,int accountNum,double balance) {
		accounts.push_back(BankAccount(name,accountNum,balance));
	}
  void showAllAccounts(){
    cout<<"\t\t All Account Holders "<<endl;
    for(int i=0;i<accounts.size();i++){
      cout<<"\n\t\t--> serial no. "<<i+1<<endl;
      cout<<"\t\t Name : "<<accounts[i].getname()<<"\n\t\t Account Number : "<<accounts[i].getaccountnum()<<"\n\t\t Balance : "<<accounts[i].getbalance()<<endl;
    }
  }
  void searchAccount(int account){
    cout<<"\t\tAccount Holder "<<endl;
    for(int i=0;i<accounts.size();i++){
      if(accounts[i].getaccountnum()==account){
        cout<<"\t\t Name : "<<accounts[i].getname()<<"\n\t\t Account Number : "<<accounts[i].getaccountnum()<<"\n\t\t Balance : "<<accounts[i].getbalance()<<endl;
      }
    }
  }
  BankAccount* findAccount(int accountNum){
    for(int i=0;i<accounts.size();i++){
      if(accounts[i].getaccountnum()==accountNum){
        return &accounts[i];
      }
    }
  }
};
void choices() {
	cout<<"\n\t    ***** BANK MANAGEMENT SYSTEM *****"<<endl;
	cout<<"\n\t\t\tMain Menu"<<endl;
	cout<<"\t\t 1. Create New Account"<<endl;
	cout<<"\t\t 2. Show all Accounts"<<endl;
	cout<<"\t\t 3. Search An Account"<<endl;
	cout<<"\t\t 4. Deposit Money"<<endl;
	cout<<"\t\t 5. Withdraw Money"<<endl;
	cout<<"\t\t 6. Exit "<<endl;
	cout<<"          \t---------------------  \n";
	cout<<"\n\t   Enter your Choice : ";
}
int main() {
	int choice;
	string f = "no";
  Bankmanagement bank;
	do {
    system("cls");
		choices();
		cin>>choice;

		switch(choice) {
		case 1: {
			string name;
			int accountNum;
			double balance;
			cout<<"\t\tEnter full Name : ";
			getline(cin, name);
			cout<<"\t\tEnter account number : ";
			cin>>accountNum;
			cout<<"\t\tEnter intial balance : ";
			cin>>balance;
			bank.AddAccount(name,accountNum,balance);
			cout<<"\n\t\tAccount created successfully......... ";
      break;

		}
    case 2: {
      bank.showAllAccounts();
      break;
    }
    case 3:{
      int accountnum;
      cout<<"\n\t\tEnter account number: ";
      cin>>accountnum;
      bank.searchAccount(accountnum);
      break;
    }
    case 4:{
      int accountNum;
      double amount;
      cout<<"\t  Enter Account no. to deposit money : ";
      cin>>accountNum;
      BankAccount* account =   bank.findAccount(accountNum);
      
      if(account != NULL){
        cout<<"\t\tEnter the amount to deposit : ";
        cin>>amount;
        account -> deposit(amount);
        cout<<"\n\t\tAmount deposited successfully ......."<<endl;
      }else{
        cout<<"\n\t\tAccount Not found ......"<<endl;
      }

      break;
    }
    case 5:{
      int accountNum;
      double amount;
      cout<<"\t\tEnter Account to withdraw money: ";
      cin>>accountNum;
      BankAccount* account =   bank.findAccount(accountNum);
      
      if(account != NULL){
        cout<<"\t\t Enter the ammount to withdraw";
        cin>>amount;
        account -> withdraw(amount);
      }else{
        cout<<"\t\t Account Not found ......"<<endl;
      }
      break;
		}
    case 6 : 
       break;
    default:
       cout<<"\t\tPlease enter valid choice "   ;
	}
  cout<<"\n\n\t   Do you want to continue (yes/no): ";
		cin>>f;
}
while(f=="y" || f=="yes" || f == "YES" || f=="Yes" || f=="Y");
	cout<<"\n\t\t Thank You for Visiting ";
}
