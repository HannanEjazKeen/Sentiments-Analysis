#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fname,lname;
	fname.open("firstname.txt",ios::in);
	lname.open("lastname.txt",ios::in);
	if (!fname.is_open() && !lname.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	
	char firstName[10] = {'\0'};
	char lastName[10] = {'\0'};
	char fullName[30] = {'\0'};

	for (int i = 0;i<10;i++)
	{
		fname>>firstName;
		lname>>lastName;
		int index = 0, index2 = 0;
		for (index=0;firstName[index]!='\0';index++)
		{
			fullName[index] = firstName[index];
		}
		fullName[index] = ' ';
		index++;
		for (index2=0;lastName[index2]!='\0';index2++)
		{
			fullName[index+index2] = lastName[index2];
		}
		fullName[index+index2] = '\0';
		cout<<fullName<<endl;
	}
	
	fname.close();
	lname.close();

	return 0;
}
