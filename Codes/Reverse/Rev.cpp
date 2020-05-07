// A Simple C++ program to reverse a string 
#include <bits/stdc++.h> 
using namespace std; 

// Function to reverse a string 
void reverseStr(string& str) 
{ 
	int n = str.length(); 

	// Swap character starting from two 
	// corners 
	for (int i = 0; i < n / 2; i++) 
		swap(str[i], str[n - i - 1]); 
} 

// Driver program 
int main() 
{ 
	string str; 
    cout<<"Enter The String::"<<endl<<endl;
    getline(cin,str);
    cout<<"--------------------------------------------";
    cout<<endl<<"The Entered String::  "<<str<<endl;
	
	
	reverseStr(str); 
	
	cout <<endl<<endl<<"The Final String is:  "<< str<<endl<<endl; 
	
	
	return 0; 
} 



/*

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
*/