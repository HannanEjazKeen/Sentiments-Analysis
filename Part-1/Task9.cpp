#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int num = 0;

	ifstream read;
	read.open("int.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	
	read>>num;
	read.close();

	int value = 0;
	int flag = 0;

	ofstream write;
	write.open("output.txt",ios::out);

	ifstream read2;
	read2.open("data.txt",ios::in);

	if (!read2.is_open() && !write.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}

	read2>>value;
	
	while(!read2.eof())
	{
		if (value == num)
		{
			write<<"Found"<<endl;
			flag = 1;
			break;
		}
	read2>>value;
	}

	if (flag==0)		write<<"Not Found"<<endl;	

	read2.close();
	write.close();

	return 0;
}
