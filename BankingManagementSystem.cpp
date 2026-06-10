#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
class Account
{
	private:
		string name;
		int AccNo;
		int balance;
		vector<string> history;
	public:
		Account()
		{
   			name="";
    		AccNo=0;
    		balance=0;
		}		
		Account(string n, int a, int b)
		{
			name = n;
			AccNo=a;
			balance=b;
		}
		void addTransaction(string msg)
		{
			history.push_back(msg);
		}
		
		void showHistory()
		{
    		if(history.empty())
    		{
      			cout << "No transactions found." << endl;
       			return;
    		}

    		cout << "Transaction History:" << endl;

    		for(int i = 0; i < history.size(); i++)
    		{
       			 cout << history[i] << endl;
    		}
		}
		void setName(string n)
		{
			name=n;
		}
		
		void setAcc(int a)
		{
			AccNo=a;
		}
		
		string getName()
		{
			return name;
		}
		
		int getAcc()
		{
			return AccNo;
		}
		
		int getBalance()
		{
			return balance;
		}
		void deposit(int b)
		{
			if(b>0)
			{
				balance+=b;
				addTransaction("Deposit " + to_string(b));
			}
			else
			{
				cout<<"invalid amount entered"<<endl;
			}
		}
		
		void withdraw(int b)
		{
			if(b>0 && b<=balance)
			{
				balance-=b;
				addTransaction("Withdraw "+ to_string(b));
			
			}
			else
			{
				cout<<"this amount can't be withdrawed"<<endl;
			}
		}
		
		void display()
		{
			cout<<"Account Number: "<<AccNo<<endl<<"Name: "<<name<<endl<<"Account Balance: "<<balance<<endl; 
		}	
		
		friend ostream & operator <<( ostream &obj, const Account &a)
		{
			obj<<"Name: "<<a.name<<endl<<"Account Number: "<<a.AccNo<<endl<<"Balance: "<<a.balance<<endl;
			return obj;
		}
};

int main()
{
		int AccNo1, AccNo2;
		map<int, Account> accounts;
		accounts.insert({1001, Account("Tanvi", 1001, 10000)});
		accounts.insert({1002, Account("Tanya", 1002, 1000)});
		accounts.insert({1003, Account("Harsh", 1003, 5000)});
		accounts.insert({1004, Account("Shubhi", 1004, 100)});
		accounts.insert({1005, Account("Srishti", 1005, 500)});
		accounts.insert({1006, Account("Khushi", 1006, 4300)});
		accounts.insert({1007, Account("Natasha", 1007, 1000)});
		accounts.insert({1008, Account("Kartik", 1008, 3400)});
	
	char ch; int i,b;
		
	do
	{
		
		cout<<"\nEnter the operation you want to perform\n"<<endl;
		cout<<"1.Deposit Money\n2.Check Balance\n3.Withdraw Money\n4.Transfer Money\n5.Create a new account\n6.Display all accounts\n7.Delete an account\n8.Show transaction history\n9.Exit\n"<<endl;
		cin>>i;
		switch(i)
		{
			case 1: {
						cout<<"Enter account number"<<endl;
						cin>>AccNo1;
						map<int, Account>::iterator a;
						a = accounts.find(AccNo1);
						if(a==accounts.end())
						{
							cout<<"Accound not found"<<endl;
						}
						else
						{
							cout<<"Enter the amount you want to deposit"<<endl;
							cin>>b;
							a->second.deposit(b);
							cout<<"Amount deposited successfully!"<<endl;
						}
						break;
					}
			case 2: {
						cout<<"Enter account number"<<endl;
						cin>>AccNo1;
						map<int, Account>::iterator a;
						a = accounts.find(AccNo1);
						if(a==accounts.end())
						{
							cout<<"Accound not found"<<endl;
						}
						else
						{
							a->second.display();
						}
				
						break;
					}
			case 3: {
						cout<<"Enter account number"<<endl;
						cin>>AccNo1;
						map<int, Account>::iterator a;
						a = accounts.find(AccNo1);
						if(a==accounts.end())
						{
							cout<<"Accound not found"<<endl;
						}
						else
						{
							cout<<"Enter the amount you want to withdraw"<<endl;
							cin>>b;
							a->second.withdraw(b);
							cout<<"Amount withdrawn successfully!"<<endl;
						}
						
						break;
					}
			case 4: {
						cout<<"Enter sender's account number: "<<endl;
						cin>>AccNo1;
						map<int, Account>::iterator a;
						a = accounts.find(AccNo1);
						if(a==accounts.end())
						{
							cout<<"Accound not found"<<endl;
							break;
						}
						cout<<"Enter reciever's account number: "<<endl;
						cin>>AccNo2;
						map<int, Account>::iterator itr;
						itr= accounts.find(AccNo2);
						if(itr==accounts.end())
						{
							cout<<"Accound not found"<<endl;
							break;
						}
						cout<<"Enter the amount you want to transfer:"<<endl;
						cin>>b;
						if(b>a->second.getBalance())
						{
							cout<<"Insufficient balance!"<<endl;
							break;
						}
						a->second.withdraw(b);
						itr->second.deposit(b);
						a->second.addTransaction("Transfer " + to_string(b) + " to " + to_string(AccNo2));
						itr->second.addTransaction("Recieved " + to_string(b) + " from " + to_string(AccNo1));
						cout<<"Amount transferred successfully!"<<endl;
						break;
					}
			case 5: {
						int newa, ib;
						string newname;
						cout<<"Enter the new account details:"<<endl<<"Enter name:"<<endl;
						cin>>newname;
						cout<<"Enter Account Number:"<<endl;
						cin>>newa;
						auto it = accounts.find(newa);
						if(it==accounts.end())
						{
							cout<<"Enter Initial Balance:"<<endl;
							cin>>ib;
							accounts.insert({newa, Account(newname, newa, ib)});
							cout<<"Account created successfully!!"<<endl;
						}
						else
						{
							cout<<"Account number already exists"<<endl;
						}
							break;
					}
			case 6: {
						map<int, Account>::iterator itrrr;
						for(itrrr=accounts.begin(); itrrr!=accounts.end(); itrrr++)
						{
						cout<< itrrr->second <<endl;
						}
						
						break;
					}
					
			case 7: {
						cout<<"Enter account number: "<<endl;
						int delacc;
						cin>>delacc;
						auto itr = accounts.find(delacc);
						if(itr==accounts.end())
						{
							cout<<"account not found"<<endl;

						}
						else
						{
							accounts.erase(delacc);
							cout<<"Account deleted successfully"<<endl;
						}
				
						break;
					}
			case 8:	{
						cout<<"Enter account number"<<endl;
						cin>>AccNo1;
						map<int, Account>::iterator a;
						a = accounts.find(AccNo1);
						if(a==accounts.end())
						{
							cout<<"Accound not found"<<endl;
						}
						else
						{	
							a->second.showHistory();
						}
						break;
			 		} 
			case 9: exit(0);
			default:cout<<"invalid choice"<<endl;
	}
    }while(1);
}
