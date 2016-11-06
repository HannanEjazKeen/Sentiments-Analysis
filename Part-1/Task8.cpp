#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int num = 0;
	float mark = 0;
	char name[20] = {'\0'};
	
	ifstream read;
	read.open("data.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	
	read>>num>>name>>mark;

	while(!read.eof())
	{
		cout<<num<<": "<<name<<"  "<<mark<<endl;
		read>>num>>name>>mark;
	}
	read.close();

	return 0;
}
