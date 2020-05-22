// CPP program to Convert characters 
// of a string to opposite case 
#include<iostream> 
using namespace std; 

// Function to convert characters 
// of a string to opposite case 
void convertOpposite(string &str) 
{ 
	int ln = str.length(); 
	
	// Conversion according to ASCII values 
	for (int i=0; i<ln; i++) 
	{ 
		if (str[i]>='a' && str[i]<='z') 
		//Convert lowercase to uppercase 
			str[i] = str[i] - 32; 
		else if(str[i]>='A' && str[i]<='Z') 
		//Convert uppercase to lowercase 
			str[i] = str[i] + 32; 
	} 
} 

// Driver function 
int main() 
{   string str;
	
    cout<<"Enter The String::"<<endl<<endl;
    getline(cin,str);
    cout<<"--------------------------------------------";
    cout<<endl<<"The Entered String::  "<<str<<endl;
	
	// Calling the Function 
	convertOpposite(str); 
	
	cout <<endl<<endl<<"The Final String is:  "<< str<<endl<<endl; 
	return 0; 
} 
