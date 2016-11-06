#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int in = 0;
	cout<<"Enter value"<<endl;
	cin>>in;

	ofstream write;
	write.open("data.txt",ios::out);
	if (!write.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	write<<(in+5)<<endl;
	write.close();

	int in2 = 0;
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
