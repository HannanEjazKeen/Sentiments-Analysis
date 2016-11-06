#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int in = 0;
	ifstream read;
	read.open("data.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	read>>in;
	read.close();
	cout<<in<<endl;
}
