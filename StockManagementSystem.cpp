#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

ifstream inp;
ofstream out;
fstream file;

class Time
{
	protected:
		time_t tt; //store the system time  
		struct tm* current_time;//a data structure that store time in "day, date, hrs:mins:sec yr" format
	
	public:
		void displayTime();//To display the time
};

void Time::displayTime()//To display the time
{
	time (&tt);
    current_time = localtime(&tt); 
    
    cout << asctime(current_time) << endl;//convert the data stored in "current_time: to given format
}

class User:public Time
{
	protected:
		string username, password;
	
	public:
		string getname() const{return username;}
		string getpassword() const{return password;}
		
		void detail();//printing details of time and id details
		
		void registration();//Allow user to sign-up a new account
		bool verification();//Allow user to login
		
		void setName(string un) {username = un;}
		void setPassword(string pw) {password = pw;}
};


void User::detail()//printing details of time and id details
{
	cout << username << endl;
	displayTime();
}

//Function to allow user to sign-up a new account
void User::registration()
{
	string filename, username, password;		
	string admin , adminKey ="123456"; //a special designed key to verify status of user
	
	int pSize, nSize;//variables to store string size of username and password
	
	bool pStatus = true, digit = false, alpha = false, space = false;// bool variables used to check the validity of id created by users
	int adminWrong ; //a variable to store how many times the user keyed in the admin key wrongly
	
	
createname://goto function marker
	system("cls");
	cout << endl << endl ;
	cout << "\t\t    ******* **  *****   ***     **       **    ** *******" << endl;
	cout << "\t\t    **      ** **       ** **   **       **    ** **     *"<< endl; 
	cout << "\t\t    ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
	cout << "\t\t         ** ** **    *  **    ****       ***  *** **"      << endl; 
	cout << "\t\t    ******* **  ******  **     ***        ******  **"      << endl; 
	
	cout << "\n\t\t\t\t   REGISTER NEW ACCOUNT:\n";
	cout << " " << setfill('=') << setw(124);	
	cout << "\n\t\t\t\t     ~ Username ~" << endl;
	cout << "\t\t\t\t * 8 to 10 characters\n\t\t\t\t * Case insensitive\n\t\t\t\t * Space is not accepted" << endl << endl <<endl; 
	cout << "\t USERNAME  : ";
	cin >> username;
	
	//check whether username already exist
	ifstream read;
	filename = username + ".txt";
	read.open(filename.c_str());
	
	if (read.is_open()) 
	{
		cout << "\nSTATUS: ";
		cout << "\n   This username is already exists. Press enter to go to login menu.";
		getch();
		system("cls");
		goto end;
	}
	
	//Control no. of characters of username
	nSize = username.size();
	
	if((nSize > 7) && (nSize < 11))
		cout <<" (VALID)"<<endl;
	else
	{
		cout << "\nSTATUS: ";
		cout << "\n   INVALID USERNAME!! Press enter to register again.";
		getch(); //  used to catch a character from the keyboard. 
		
		goto createname;
	}
	
createpassword://goto function marker

	system("cls");
 	cout << endl << endl ;
	cout << "\t\t    ******* **  *****   ***     **       **    ** *******" << endl;
	cout << "\t\t    **      ** **       ** **   **       **    ** **     *"<< endl; 
	cout << "\t\t    ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
	cout << "\t\t         ** ** **    *  **    ****       ***  *** **"      << endl; 
	cout << "\t\t    ******* **  ******  **     ***        ******  **"      << endl; 
	
	cout << "\n\t\t\t\t  REGISTER NEW ACCOUNT:\n";
	cout << " " << setfill('=') << setw(124);	
	cout << "\n\t\t\t\t     ~ Password ~" << endl;
	cout << "\t\t\t\t * 8 to 10 characters\n\t\t\t\t * Must be alphanumeric\n\t\t\t\t * Case insensitive\n\t\t\t\t * No Space"<< endl<<endl;
	cout << "\t USERNAME  : " << username << " (VALID)" << endl; 
	cout << "\t PASSWORD  : " ;
	//cout << "Create your password: (8 to 10 characters, must be alphanumeric. case and space sensitive)\n";
	
	cin.ignore();
	getline(cin, password);
	pSize = password.size();
	
	//Check whether the password created is alphanumeric
	for(int z = 0; z < pSize; z++)
	{
		if(isalpha(password[z]))
			alpha = true;
		if(isdigit(password[z]))
			digit = true;
	}
	
	//Control no. of characters of password
	if(pSize < 8 || pSize > 10)
	{
		cout << "\nSTATUS: ";
		cout << "\n   Password is too short or too long! Please reenter a new password.\n";
		pStatus = false;
		getch();
		goto createpassword;
	}
	
	//CHECK WHETHER THE STATUS OF PASSWORD IS VALID
	//if not valid, user have to reenter a new password
	if( digit == false || alpha == false)
	{
		cout << "\nSTATUS: ";
		cout << "\n   INVALID PASSWORD!! Please reenter a new password.\n\n\n";
		digit = false;
		alpha = false;
		getch();
		goto createpassword;
	}
	//if valid, user have to enter an admin key
	else
	{
		adminWrong = 0 ;
		
		security :
		system("cls");
        cout << endl << endl ;
		cout << "\t\t    ******* **  *****   ***     **       **    ** *******" << endl;
		cout << "\t\t    **      ** **       ** **   **       **    ** **     *"<< endl; 
		cout << "\t\t    ******* ** **   *** **  **  **  ***  **    ** *******" << endl; 
		cout << "\t\t         ** ** **    *  **    ****       ***  *** **"      << endl; 
		cout << "\t\t    ******* **  ******  **     ***        ******  **"      << endl; 
		cout << "\n\t\t\t\t     REGISTER NEW ACCOUNT:\n";
		cout << " " ;
		
		for(int i = 0 ; i < 102 ; i ++ )
		{cout<<"=" ;}	
		cout << "\n\t\t\t\t\t~  Admin Key  ~" << endl;
		cout << "\t\t\t\t\t * 6 digits\n\t\t\t\t\t * No spacing" << endl << endl << endl << endl;
		cout << "\t USERNAME  : " << username << " (VALID)" << endl; 
		cout << "\t PASSWORD  : " << password << " (VALID)" << endl; 
		cout << "\n\t You need an admin key to create a new id\n";
		cout << "\t ADMIN KEY : " ;
		cin >> admin ; 
		
		//if the admin keyed in is correct, a file will be created storing the username and password details
		if ( admin  == adminKey )
		{ 	
			filename = username + ".txt";
					
			ofstream write(filename.c_str());//folder or directory
			write << username << endl
			  	  << password << endl;//	
			
			write.close();
			
			cout << "\nSTATUS: ";
			cout << "\n   CONGRATULATIONS! YOUR ACCOUNT IS CREATED SUCCESSFULLY AT ";
			displayTime();
			cout << endl
			     << "   Press enter to proceed to MENU.";
			 
			getch();
			system("cls");
		}
		//if the admin keyed in is incorrect, users are given 2 more chances to key in the admin key
		else 
		{
			adminWrong = adminWrong + 1;
			
			switch (adminWrong )
			{
				case 2: cout << "\nSTATUS: ";
						cout << "\n   Failed...!" << endl
							 << "   There is an error in the admin key." << endl			 
							 << "   Press ENTER to continue (This is your 2nd error)";
						getch();
						system("cls");
						goto security;
						break;
						
						
				case 3: cout << "\nSTATUS: ";
						cout << "\n   Failed...!" << endl
							 << "   There is an error in the admin key." << endl			 
			 				 << "   Press ENTER to exit (This is your 3rd error)";
			 			getch();
						system("cls");
						exit(0);
						break;
				
				default:cout << "\nSTATUS: ";
						cout << "\n   Failed...!" << endl
			 				 << "   There is an error in the admin key." << endl			 
			 				 << "   Press ENTER to continue (This is your 1st error)";	
						getch(); // is used to catch a character from the keyboard. 
						system("cls");
						goto security;
						break;
			}	
		}
	}
	
	end:;
}

//Function to allow user to login
bool User::verification()
{
A://goto function marker
	string DBusername, DBpassword;
	string filename;
	bool status;
		
	system("cls"); 
	cout << endl << endl; 
	cout<< "\t\t\t    **        ******   *****   **  ***     **"<<endl
   		<< "\t\t\t    **       **    ** **       **  ** **   **"<<endl
   		<< "\t\t\t    **       **    ** **   *** **  **  **  **"<<endl
		<< "\t\t\t    **       **    ** **    *  **  **    ****"<<endl
		<< "\t\t\t    ********  ******   ******  **  **     ***"<<endl;
		
	cout<< "\n\t\t\t\t\tLOGIN TO SYSTEM \n";
	cout << " " << setfill('=') << setw(104);	
	cout << "\n\n"; 
	cout << "\t Username : ";
	cin  >> username;
	cin.ignore();
	cout << "\t Password : ";
	getline(cin, password);	
	
	//read the username keyed in by user from file operation
	ifstream read;
	filename = username + ".txt";
	read.open( filename.c_str() );//directory 
	
	//if the file is not exist, username keyed in is wrong. 
	if (!read.is_open()) //user account does not exist
	{
		status = false;
		return status;//return FALSE status to exit this function
	}
	
	//if file exist, read the username and password from file
	//store it in variable named with initial 'DB'
	getline(read, DBusername, '\n');
	getline(read, DBpassword);
	
	//compare the username keyed in by user and the username read from file
	//return the status(bool)
	if (DBusername==username && DBpassword==password) 
		status = true;
	else
		status = false;
			
	read.close();
	return status;
}

//==========================================================================================================

class StockInfo
{
	protected:
		char stockname[20], category[20];
		double price;
		int amount;
		
	public:	
		void input(); //for user to input stockname, category, price and amount
		void show();  //To display stockname, catgeory, price and amount in correct format
		
		int checking(char [20]);  //to check the stockname when users want to refill or delete product
		
		//void HexCode(); GIVEUP
		
		void Withdraw();  //allow users to withdraw product with the numbers they want
		void Refill();   //allow users to refill the product with the numbers they want
		
		void TakeOut(int);  //will be called by Withdraw() at the end
		void TakeIn(int);   //will be called by Refill() at the end
		
		void display(); 	//will display the whole database
			
		void AddNewProduct(); //Allow users to add new products
		void DeleteProduct();	//Allow users to delete products
		
		friend istream& operator>>(istream &, StockInfo &);	 //for user to input stockname, category, price and amount
	
		void setStockName(char []);
//		void setCode(string);		
		void setCategory(char []);
		void setAmount(int);
		void setPrice(double);
		
		string getStockName() const {return stockname;}
//		string getCode() const {return code;}
		string getCategory() const {return category;}
		int getAmount() const {return amount;}
		double getPrice() const {return price;}
		
		virtual void Print(){ };
};

void StockInfo::TakeOut(int quantity)
{
	if(amount >= quantity) //to check if the store has enough amount of stock for users or not
	{
		amount -= quantity;
		
		cout << endl << endl;
		cout << " Stock updated." << endl << endl << endl;
    }
	else 
	{
		cout << endl << endl;
		cout << " Insufficient Stock";
	}
		 // used to catch a character from the keyboard. 
}

void StockInfo::TakeIn(int quantity)
{
		amount += quantity; //update the quantity of the stock
		
		cout << endl << endl;
		cout << " Stock updated.";

}

int StockInfo::checking(char name[20])
{
	if (strcmp(stockname, name) == 0) //when users want to refill or delete product, they need to specify the nameof that product
		return 0;
	else
		return 1;
}

void StockInfo::input()
{
	cout << "\tProduct Name(Max 20 Characters & No SPACE)\t: ";
	cin >> stockname;  

/*	
	cout << "Code:\t";
	code = "PK";
	cout << code << endl;
*/	
	cout << "\tProduct Category(Max 20 Characters & No SPACE)\t: ";
	cin >> category;
		
	cout << "\tPrice           \t\t\t\t: ";
	cin >> price;
	
	cout << "\tAmount          \t\t\t\t: ";
	cin >> amount;

}


void StockInfo::show() 
{	
	cout << fixed << setprecision(2);
	cout << " "  << setfill(' ') << left << "|" << " "<< setw(24) << stockname  
	 	 << "|"  << " " << setw(24) << amount   << "|"  << " " << setw(22) << price 
	 	 << "|"  << " " << setw(23) << category << "|" << endl;
}

void StockInfo::AddNewProduct()
{	
	int n; //number of new products users want to add
	
	system("cls");
	
	this->display();  //show users the condition of database first
 	
	getch();
	system("cls");
	cout << endl<<endl; 
	cout<<"\t\t\t\t    ****   ******   ******"   <<endl;
	cout<<"\t\t\t\t  **    ** **    *  **    *"  <<endl;
	cout<<"\t\t\t\t  ******** **     * **     *" <<endl;
	cout<<"\t\t\t\t  **    ** **    *  **    *"  <<endl;	
	cout<<"\t\t\t\t  **    ** ******   ******"   <<endl;
	
	cout << "\n\t\t\t\t\tAdding new item\n";
    	cout <<" ";
	for(int a = 0 ; a <102 ; a ++)
	{cout <<"=";}
	
	cout <<endl <<endl; 
	cout << " How many type of product(s) you wish to add? : ";
    cin >> n;
    
    system("cls");
    
    if (n != 0)
    {
		int j, l, sum = 0;
		
		out.open("database.dat", ios::binary|ios::app);//open our database file in binary and append mode
		cout << endl<<endl; 
		
		cout<<"\t\t\t\t    ****   ******   ******"   <<endl;
		cout<<"\t\t\t\t  **    ** **    *  **    *"  <<endl;
		cout<<"\t\t\t\t  ******** **     * **     *" <<endl;
		cout<<"\t\t\t\t  **    ** **    *  **    *"  <<endl;	
		cout<<"\t\t\t\t  **    ** ******   ******"   <<endl;
		
		for(int i=0;i<n;i++)
		{	

			cout << "\n\n\t\t\t\t\tAdding new item\n";
        	cout <<" ";
			for(int a = 0 ; a <102 ; a ++)
			{cout <<"=";}
			cout << endl; 
	    	this->input(); //users input
	    	
	    	out.write( (char*)this, sizeof(*this) ); //write the latest data into database file
			
			cout << "\n\n Item updated";
			cin.get();
		}
    	cout<<"\n\nSTATUS: Stock Updated!!";
    
    	out.close();
    	
   		
   		cout << endl << right << setw(103);
		cout << "Press <ENTER> to continue ->";
	 
		getch();
    	system("cls");
    	this->display(); //show the latest condition of database
	}
	else
	{
		out.close();
		
		cin.get();
		system("cls");
		
		cout << endl << endl << "No Item is being Added";
		// need call someting to exit the page or to another page 
		cout << endl << right << setw(103);
		cout << "Press <ENTER> to continue ->";
	 
		getch();		
	}
}

void StockInfo::Withdraw()
{
	system("cls");
		
	char name[20]; //for users to iput the name of product they want to withdraw
	
	int quantity;
	int i = 0;
	long Charposition = 0; //to identify the specific positions in database file
	
	this->display(); //display the latest condition of database

	getch();
	system("cls");
	cout << endl<<endl; 
	
	cout << "\t\t **    ***   **  **  ****  **  **  ***     *******     ****   **    ***   ** "<<endl;
	cout << "\t\t  *    * *   *   **   **   **  **  **  **  **     *  **    **  *    * *   *  "<<endl;
	cout << "\t\t   ** ** ** **   **   **   ******  **   ** *******   ********   ** ** ** **  "<<endl;
	cout << "\t\t    * *   * *    **   **   **  **  **  **  ** **     **    **    * *   * *   "<<endl;    
	cout << "\t\t    ***   ***    **   **   **  **  ****    **    **  **    **    ***   ***   "<<endl;	


	cout << "\n\t\t\t\t\tWithdrawing item\n";
    cout <<" ";
	for(int a = 0 ; a <102 ; a ++)
	{cout <<"=";}
		
	cout << endl << endl << "\tProduct's name : ";
	cin >> name;
	
	cout << endl << endl << "\tQuantity       : ";
	cin >> quantity;
	
	file.open("database.dat", ios::binary|ios::out|ios::in); //open the database file in binary, output, inp[ut mode
	
    while(file)
    {
	    Charposition = file.tellp();  //know the specific positions in database file
	    
	    file.read( (char*)this, sizeof(*this) ); //read the latest confitions of database file one by one everytime the loop iterate
	    
	    if(this->checking(name)==0) //to check if the name users input exists in database file or not
	    {
			this->TakeOut(quantity); //modify the data
			
			file.seekp(Charposition); //set to the specific positions of that data
			
			file.write( (char*)this, sizeof(*this) ); //write the latest data into that specific position of database file
			
			i++;
			  
			break;
	    }
    }
    
    if(i != 1)
    	cout<<"\n\n !!Record not found!!"; //if the name users input didnt exist in database, disply this
 	
	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";
	    
	getch();	
    file.close();
    cin.get();
    
    system("cls");
    
	this->display(); //display the latest condition of database file 
	
}

void StockInfo::display() 
{
	int i = 1;
	int z ; 
	
	system("cls");

	displaystock:
	cout << endl;
	cout << " ";
	for(int z = 0 ; z <102 ; z ++)
	{cout <<"=";}	
	cout << endl ;

	cout <<" |";
	cout << setfill(' ') << right << setw(54) <<"Store Items"<< setw(47) << "|" << endl;

	cout << " ";
	for(int z = 0 ; z<102 ; z ++)
	{cout <<"=";}
	
    cout << endl; 
    cout << " " << setfill(' ') << left << "|" << setw(25) << " PARTICULARS"  << "|"  << setw(25) << " STOCK AVAILABLE" << "|"  << setw(23) << " PRICE(RM)" << "|" << setw(24)  << " CATEGORY" << "|"  << endl;

	cout << " " ;
	for ( int b = 0 ; b <102 ;b++)
	{
		cout << "-" ; 
	}
	cout << endl;
	
	inp.open("database.dat",ios::binary); //open the database file to write data

    while(!inp.eof())
    {
		inp.read( (char*)this, sizeof(*this) ); //read the STockInfo data in the database file one by one everytime the loop interate
		
		if( !inp.eof() )
		{
	    	if(inp.tellg() < 0)
	    	{
				i = 0;
				break;
			}
	    	this->show();  //display it one by one everytime the loop interate
	  	} 	

    }
    
     if (i == 0 )
    {
		cout << "\t\t\t\t!!Empty record room!!"<<endl;
    } 
  	
	cout << " " ;
	for ( int b = 0 ; b <102 ;b++)
	{
		cout << "-" ; 
	}
	cout << endl;
	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";
	  	
	inp.close();
}

void StockInfo::Refill()
{
	system("cls");
	
	char temp[20];
	
	int qty;
	int i = 0;
	
	long Charposition = 0;
	
	this->display();
 
	getch();
	system("cls");
	cout << endl << endl;
	
	cout << "\t\t\t\t*******  ******** ******** ** **      **"     << endl;
	cout << "\t\t\t\t**     * **       **       ** **      **"     << endl;
	cout << "\t\t\t\t*******  ******** ******** ** **      **"     << endl;
	cout << "\t\t\t\t** **    **       **       ** **      **"     << endl;
	cout << "\t\t\t\t**    ** ******** **       ** ******* *******"<< endl;
		
	cout << "\n\t\t\t\t\t\tRefilling item\n";
	cout <<" ";
	for(int i = 0 ; i <102 ; i ++)
	{cout <<"=";}
	
	cout << "\n\n\t Item name : "; //enter the name of product that users want to refill
	
	cin >> temp;
	
	cout << "\n\t Quantity  : " ; //enter the quantity of product that users want to refill
	cin >> qty;
	
	file.open("database.dat", ios::binary|ios::out|ios::in);
	
    while(file)
    {
	    Charposition = file.tellp(); //find the position in the file
	    
		file.read( (char*)this, sizeof(*this) ); //read and extract the data from database file

	    if(this->checking(temp) == 0)
	    {
			this->TakeIn(qty); //modify the data
			
			file.seekp(Charposition); //set file posotions to the positions of that data
			
			file.write( (char*)this, sizeof(*this) ); //write the data back to the database file
			
			i++;
			break;
	    }
    }
    if(i != 1)
    	cout<<"\n\n !!Record not found!!"; //if the name users input didnt exist in database, disply this

    file.close();
	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";
	 
	getch();
    system("cls");

    cin.get();

	this->display(); 
	cin.get();	
}

void StockInfo::DeleteProduct()
{
	system("cls"); // clear screen 
	
	this->display();
 
	getch();
	system("cls");
	cout << endl << endl;
	
	cout << endl << endl; 		
	cout << "\t\t\t *****   ******* **      ******* ******** *******"<<endl;
	cout << "\t\t\t **   *  **      **      **         **    **     "<<endl;
	cout << "\t\t\t **    * ******* **      *******    **    *******"<<endl;
	cout << "\t\t\t **   *  **      **      **         **    **     "<<endl;    
	cout << "\t\t\t *****   ******* ******* *******    **    *******"<<endl;

	int i=0;
    char temp[20];
    cout << "\n\n\t\t\t\t\tDelete Record\n";
    cout <<" ";
	for(int a = 0 ; a <102 ; a ++)
	{cout <<"=";}
	cout << endl; 
	//cout << endl << "\t\t\t\t" << "Delete Record";
    cout << endl << endl << "\t\tName of the product : "; //eneter the name of product that want to delete
    
	cin >> temp;
    
	out.open("temp.dat", ios::binary); //create a new database file to write data
    inp.open("database.dat", ios::binary); //open old database file to read data
     
	while(!inp.eof())
    {
		inp.read( (char*)this, sizeof(*this) ); //read data from old database file
		
		if(!inp.eof())
	    	if(this->checking(temp) == 0)
	    	{
				this->show(); //show the row of data that is being deleted
		  		cout<<"\n\n\t\t RECORD DELETED!\n";
		  		
		  		i++;
	    	}
	   		else
	   		{
	   			out.write( (char*)this, sizeof(*this) ); //write new data into new database file
			}			
    }
     
    if(i==0)
    	cout << "\n\n !!RECORD NOT FOUND!!"; //if the name users input didnt exist in database, disply this
    
	inp.close();
    out.close();
    
    remove("database.dat");//delete the old database file
    rename("temp.dat", "database.dat");//replace the name of new database file with the name of old database file
 
	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";

}
/*
void StockInfo::HexCode() //heavy area
{
	int total=0;
	
	for (int i = 0; i < stockname.size() ; i++)
		total = total + int(stockname[i]);

	string hex_string;
	
    //sprintf(hex_string, "%X", total); //convert number to hex
    
   	code = hex_string;
}
*/
istream &operator>>(istream &strm, StockInfo &obj)  //overloaded >> operator. FOr users to input, Just like input()
{
	cout << "Product Name(Max 20 Characters & No Space):\t";
	cin >> obj.stockname;
/*
	cout << "Code:\t";
	obj.setCode("PK");
	cout << obj.code;
*/		
	cout << "Price:\t";
	strm >> obj.price;
	
	cout << "Amount:\t";
	cin >> obj.amount;
	
	cout << "Category(Max 20 Characters & No Space):\t";
	cin >> obj.category;
	
	return strm;
}


void StockInfo::setStockName(char stockname[])
{
	strcpy(this->stockname, stockname);
}
/*
void StockInfo::setCode(string code)
{
	this->code = code;
}
*/
void StockInfo::setCategory(char category[])
{
	strcpy(this->category, category);
}

void StockInfo::setAmount(int amount)
{
	this->amount = amount;
}

void StockInfo::setPrice(double price)
{
	this->price = price;
}

//===================================================================================================================================================

class Screen : public StockInfo
{
	public:
		void Print(); // function that print out report on screen 
		friend istream &operator >> (istream &input, StockInfo &p);	
};

void Screen::Print()// function that print out report on screen 
{
	StockInfo stock;
		
	inp.open("database.dat",ios::binary); 
	
	system("cls");
		
	setfill(' '); // fill the empty space with whitespace 
	cout <<endl;
	cout<<"\t\t*******  ******** *******   ******  *******  ********"<<endl;
	cout<<"\t\t**     * **       **     * **    ** **     *    **"<<endl;
	cout<<"\t\t*******  ******** *******  **    ** *******     **"<<endl;
	cout<<"\t\t** **    **       **       **    ** ** **       **"<<endl;
	cout<<"\t\t**    ** ******** **        ******  **    **    **"<<endl;
	
	cout << endl<<endl;
	cout << " ";
	for(int z = 0 ; z <102 ; z ++)
	{cout <<"=";}	
	cout << endl ;

	cout <<" |";
	cout << setfill(' ') << right << setw(54) <<"Store Items"
		 << setw(47) << "|" << endl;

	cout << " ";
	for(int z = 0 ; z<102 ; z ++)
	{cout <<"=";}
	
    cout << endl; 
    cout << " " << setfill(' ') << left << "|" << setw(25) << " PARTICULARS"  
		 << "|"  << setw(25) << " STOCK AVAILABLE" << "|"  << setw(23) << " PRICE(RM)" 
		 << "|" << setw(24)  << " CATEGORY" << "|"  << endl;

	cout << " " ;
	for ( int b = 0 ; b <102 ;b++)
	{
		cout << "-" ; 
	}
	cout << endl;

    	while(!inp.eof())
   		 {
			inp.read( (char*)(&stock), sizeof(stock) ); // read binary .dat file 
		
			if( !inp.eof() )
			{
				cout << fixed << setprecision(2);
				// display out the info 
				cout << " " << setfill(' ') << left << "|" 
					 << " "<< setw(24) << stock.getStockName()  
					 << "|"  << " " << setw(24) << stock.getAmount()
					 << "|"  << " " << setw(22) << stock.getPrice() 
					 << "|" << " "  << setw(23)  << stock.getCategory() 
					 << "|" << endl;
    		}
		}
		
		inp.close();
		cout << "\n\nSTATUS: ";
		cout << "\n   SUCCESSFUL!\n"
			 << "   REPORT PRINTED.";
		cout << endl << right << setw(103);
		cout << "Press <ENTER> to continue ->";
		getch(); //  used to catch a character from the keyboard. 
}


class Text : public StockInfo
{
	public:
		void Print(); // function that print out report in text file  
};

void Text::Print()// function that print out report in text file  
{
	StockInfo stock;
		
	inp.open("database.dat",ios::binary);
	out.open("Monthly.txt") ;
		
	out <<endl;
	out<<"\t\t*******  ******** *******   ******  *******  ********"<<endl;
	out<<"\t\t**     * **       **     * **    ** **     *    **"<<endl;
	out<<"\t\t*******  ******** *******  **    ** *******     **"<<endl;
	out<<"\t\t** **    **       **       **    ** ** **       **"<<endl;
	out<<"\t\t**    ** ******** **        ******  **    **    **"<<endl;
		 
	out << endl<<endl;
	out << " ";
	for(int z = 0 ; z <102 ; z ++)
	{out <<"=";}	
	out << endl ;

	out <<" |";
	out << setfill(' ') << right << setw(54) <<"Store Items"
		<< setw(47) << "|" << endl;

	out << " ";
	for(int z = 0 ; z<102 ; z ++)
	{out <<"=";}
	
    out << endl; 
    out << " " << setfill(' ') << left << "|" << setw(25) << " PARTICULARS" 
		<< "|" << setw(25) << " STOCK AVAILABLE" << "|"  << setw(23) << " PRICE(RM)"
		<< "|" << setw(24) << " CATEGORY" << "|"  << endl;

	out << " " ;
	for ( int b = 0 ; b <102 ;b++)
	{
		out << "-" ; 
	}
	out << endl;
	
		while(!inp.eof())
		{
			inp.read( (char*)(&stock), sizeof(stock) );
			
			out << fixed << setprecision(2);
			if( !inp.eof() )
			{
			
	   			out << " " << setfill(' ')   << left << "|" << " "<< setw(24) 
				    << stock.getStockName()  << "|"  << " " << setw(24) 
					<< stock.getAmount()      << "|"  << " " << setw(22) 
					<< stock.getPrice()   << "|"  << " " << setw(23) 
					<<  stock.getCategory()     << "|"  << endl;
    		} 
		}
		inp.close();
		out.close();
		
		cout << "\nSTATUS: ";
		cout << "\n   SUCCESSFUL!\n"
			<< "   REPORT PRINTED.";
	
	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";
	 
	getch();//is used to catch a character from the keyboard. 
};


class CSV  : public StockInfo // function that print out report in csv file
{
	public:
		void Print();
};

void CSV::Print()// function that print out report in csv file
{
		StockInfo stock;
		
		inp.open("database.dat",ios::binary); // open input file 
		out.open("Monthly.csv") ;// open output fiele
		
		// "," is for the csv format 
		out << fixed << setprecision(2);
		out  << "Stock Name" << "," << "Amount" << "," << "Price(RM)" << "," << "Category" <<  endl;
			   
		
		while(!inp.eof())
		{
			inp.read( (char*)(&stock), sizeof(stock) );
			
			if( !inp.eof() )
			{
				// this is to output the info into the csv file 
	   			out << stock.getStockName() << "," << stock.getAmount()<< ","
					<< stock.getPrice() <<","
				    << stock.getCategory() << "," <<  endl;	

    		}
		
		}
		inp.close(); // close input file 
		out.close(); // clode output file 
		
		cout << "\nSTATUS: ";
		cout << "\n   SUCCESSFUL!\n"
			<< "   REPORT PRINTED.";

	cout << endl << right << setw(103);
	cout << "Press <ENTER> to continue ->";
	 
	getch();

}

class Menu : public StockInfo, public User //inheritance with User and StockInfo
{
	protected:
		Screen s; 
		Text t;
		CSV c;
		
		StockInfo stock; // for inheritance 
		
	public: 
		void Welcome(); 
		void Login();
		void Selection();
		void Ending();
};

void Menu::Welcome()
{
	displayTime(); // display details of time and id details
	cout << "\t\t\t####### ######## #######  #######  #######"<<endl;
	cout << "\t\t\t##         ##   ##     ## ##     # ##     "<<endl;
	cout << "\t\t\t#######    ##   ##     ## #######  #######"<<endl;
	cout << "\t\t\t     ##    ##   ##     ## ## ##    ##     "<<endl;
	cout << "\t\t\t#######    ##    #######  ##   ##  #######"<<endl;
	cout << endl; 
	cout << "   ###       ###   ###   ###     ##   ###    #######  ###       ### ####### ###     ## ########"<<endl;
	cout <<	"   ## ##   ## ## ##   ## ## ##   ## ##   ## ##        ## ##   ## ## ##      ## ##   ##    ##   "<<endl;
	cout <<	"   ##  ## ##  ## ####### ##  ##  ## ####### ##  ##### ##  ## ##  ## ####### ##  ##  ##    ##   "<<endl;
	cout <<	"   ##   ###   ## ##   ## ##   ## ## ##   ## ##    ##  ##   ###   ## ##      ##   ## ##    ##   "<<endl;
	cout << "   ##         ## ##   ## ##    #### ##   ##  #######  ##         ## ####### ##    ####    ##   "<<endl;

	cout << endl << endl;
	cout << "\t\t\t\t WELCOME to Store Management System."<< endl; 
	cout << " ====================================================================================================== " << endl; 
	cout << "\n Features : \n";
	cout << " * Manipulate product by refill , add new product and withdraw product.\n";
	cout << " * View stock available on hand.\n"; 
	cout << " * Print report on screen , in text file and in CSV file.\n\n" ;
	cout << " ====================================================================================================== " << endl; 
	cout << endl << right << setw(103);
	cout << " Press <ENTER> to enter the system ->";
	getch();
	system("cls");

}

void Menu::Login()
{
	char choice;
	bool status;
	
	menu: 

	displayTime(); // display detail time and the user id 
	cout << endl; 
	cout << "\t\t\t  ***     ***  *******  ***    **  **    **" << endl
		 << "\t\t\t  ** ** ** **  **       ** **  **  **    **" << endl
		 << "\t\t\t  **  ***  **  *******  **  ** **  **    **" << endl
		 << "\t\t\t  **       **  **       **   ****  ***  ***" << endl
		 << "\t\t\t  **       **  *******  **    ***   ****** " << endl;

	cout << " " ;
	for (int i = 0 ;i < 102 ; i ++)
	{cout<< "=" ; }
	
	cout << "\n\n\t1) Log-In\n\t2) Sign-Up (For First Time Users)\n\t3) Back\n\t4) Exit";
	cout << "\n\n\tCHOICE: ";

	
	cin >> choice ; 
	cin.ignore();	
	if(choice == '1') 
	{
		status = verification();  // log in 	
	}
	else if(choice == '2')
	{
		registration();	// call registration function , 
		goto menu;	// go back to the menu page 
    }
    
    else if(choice == '3')
	{	
	    system("cls");
		Welcome(); // go back to the first page 
		goto menu;// go to the menu page 
    }
    
   	else if(choice == '4')
   	{
   		Ending();// go to the last page of the system
   		exit(0); 
	}
	else // this is when user enter other number 
	{
		cout << " Invalid Input! Please try again";
		
		getch();//is used to catch a character from the keyboard. 
		system("cls");
		
		goto menu; // go back to the menu page 
	}
		
	// when it enter correct username and password 
	if (status == true)
	{
		cout << "\n\nSTATUS: ";
		cout << "\n   Succesfully Logged-In at ";
		displayTime();
		getch();
		Selection();
	}
	else 
	{ // wrong username or password 
		cout << "\nSTATUS: ";
		cout << "\n   Failed...!" << endl
			 << "   There are error in your USERNAME or (and) PASSWORD" << endl			 
			 << "   Press <ENTER> to continue (This is your 1st error)"; 
		
		getch();
		system("cls");
		
		// allow user to reenter for two more chane after one retry failed 
		for(int i = 0 ; i < 2 ; i++ )
		{

			status = verification(); // first retry 
			
			// coreect username and password 
			if (status == true)
			{				
				cout << "\n\nSTATUS: ";
				cout << "\n   Succesfully Logged-In at ";
				displayTime();
				cout << "   Press <ENTER> to continue" << endl;
				
				getch();
				system("cls");
				
				Selection();
				break;
			}
			else 
			{
				// wrong username and password 
				cout << "\nSTATUS: ";
				cout << "\n   Failed...!" << endl
					 << "   There are error in your USERNAME or (and) PASSWORD" << endl
					 << "   Press <ENTER> to continue (This is your " << i+2 << "nd / rd error)";
				
				getch();
				system("cls");
			}			
		}
	}		
	if(status == false)
	{
		// allow the program to exit after the user enter wrongly for 3 times
		cout << "\n\n\n\t\t\tYou FAILED to log in for 3 times. This program will ENDS." << endl;
		Ending(); 
	} 
	
}

void Menu::Selection()// for user to pick what they want to do 
{
	
	char j, k;
			
	label: 	
	system("cls"); // clear page
	detail(); // display details of time and id details
	cout << endl; 
	cout << "\t\t****** **    ** ***     **  ****** ******** **  ******  ***     **  ******     \n"
		 << "\t\t**     **    ** ** **   ** **         **    ** **    ** ** **   **  **         \n"
		 << "\t\t****** **    ** **  **  ** **         **    ** **    ** **  **  **  ******    \n"
		 << "\t\t**     ***  *** **    **** **         **    ** **    ** **    ****      **    \n"
		 << "\t\t**      ******  **     ***  ******    **    **  ******  **     ***  ******      " << endl;
		 
	cout << " ";
	for(int i = 0 ; i < 102 ; i++)
	{cout << "=";}

	cout << "\n\n\t1. Add New Product\n\t2. Display Stock\n\t3. Refill\n\t4. Delete Products\n\t5. Withdraw\n\t6. Print Latest Reports\n\t7. Exit"
		 << endl << endl << endl;

	cout <<" ";
	for(int i = 0 ; i < 45 ; i++)
	{cout << "=";}

	cout << "END OF MENU";
	
	for(int i = 0 ; i < 46 ; i++ )
	{cout << "=";}
	
	cout << "\n\n\t Enter Your Choice : ";
	cin >> j;
	
	if(j == '1')  //Add new stock
	{
		
		stock.AddNewProduct();//stockinfo function
		getch();// allow user to enter any character 
		
		goto label; // go back to the function page ( selection ) 
	}	
	else if(j == '2')// display stock 
	{
	
		stock.display();//stockinfo function
		getch(); // allow user to enter any character 
		
		goto label;
	} 
	else if(j == '3')// refill stock 
	{
		stock.Refill();//stockinfo function
		
		goto label; // go back to the function page ( selection ) 
	}
	else if(j == '4')// withdraw stock
	{
		
		stock.DeleteProduct();//stockinfo function
		getch();//  used to catch a character from the keyboard. 
		
		goto label; // go back to the function page ( selection ) 
	} 
	else if(j == '5')// withdraw stock
	{
		stock.Withdraw();//stockinfo function
		getch();//  used to catch a character from the keyboard. 
		
		goto label; // go back to the function page ( selection ) 
	} 
	else if(j == '6') // print report 
	{
		LAB:
		
		system("cls"); // clear page 
		
		cout << "\n\t\t\t\t\t  Print Latest Report "<<endl;
		cout << " ";
		for(int i = 0 ; i < 102 ; i++)
		{cout << "=";}
		cout << endl;
		
		cout << "\t1. On Screen\n\t2. in TXT file\n\t3. in CSV file\n\t4. Return to FUNCTIONS menu"<<endl;
		 
		
		cout <<" ";
		for(int i = 0 ; i < 45 ; i++)
		{cout << "=";}

		cout << "END OF MENU";
	
		for(int i = 0 ; i < 46 ; i++ )
		{cout << "=";}
	
		cout << "\n\n\tEnter Your Choice : ";
	
		cin >> k;

		
		if(k == '1')
		{
			s.Print(); // print report on screen 
			
			goto label; // go back to the function page ( selection ) 
		}
		else if (k == '2')
		{
			t.Print(); // print report in txt file
			
			goto label;
		}
		else if (k =='3')
		{
			c.Print(); // print report in CSV file 
			
			goto label;
		}
		else if(k == '4') // exit the system 
			goto label;
		else
		{
			cout << "Invalid Input" << endl;
			cout << "<ENTER> to return to PRINT menu.";
			
			getch(); // is used to catch a character from the keyboard. 
			system("cls"); // clear page 
			goto LAB;// go back to the printing report page
		}
		
		goto label;
	} 
	else if (j == '7')
	{
		Ending(); // the last page of the system
		
		exit(0); // exit the system
	}
	else
	{
		cout << "Invalid Input" << endl;
		cout << "<ENTER> to return to FUNCTIONS menu.";
		
		getch(); // used to catch a character from the keyboard. 
		system("cls"); // clear page
		
		goto label;// go back to the Selection page
	}
}

void Menu::Ending() // show members involve in this programming technique project
{
	system("cls");  // clear page  
	detail(); // display details of time and id details
	
	cout << "\n\n\n\t\t\tBrought To You By UTM Data Engineering Students"<<endl; 
	cout << "\n\n\n\t\t\t\t";
	cout << "Leader : 1. Lee Sze Yuan \t(A19EC0068)"<<endl;
	cout << "\t\t\t\t";
	cout << "Members: 2. Tee Hui You \t(A19EC0170)"<<endl;
	cout << "\t\t\t\t";
	cout << "         3. Loh Yew Chong \t(A19EC0076)"<<endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	
	exit(0);
}

int main()
{
	Menu m;
	
	m.Welcome();
	m.Login();		//whole system will work here
	
	return 0;
}
