#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char in[20] = {'\0'};
	cout<<"Enter First Name"<<endl;
	cin>>in;

	ofstream write;
	write.open("data.txt",ios::out);
	if (!write.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	write<<in<<endl;
	write.close();

	char in2[20] = {'\0'};
	ifstream read;
	read.open("data.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	read>>in2;
	read.close();
	cout<<in2<<endl;
}
