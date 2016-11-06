#include<iostream>
#include<fstream>

using namespace std;

void input()
{
	int in1 = 0,in2 = 0;
	cout<<"Enter two values"<<endl;
	cin>>in1>>in2;

	ofstream write;
	write.open("task1.txt",ios::out);
	if (!write.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		write<<in1<<endl<<in2<<endl;
		write.close();
	}
}

void readCheckDisplay()
{
	int rd1 = 0,rd2 = 0;
	
	ifstream read;
	read.open("task1.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		read>>rd1>>rd2;
		read.close();

		if (rd1 == rd2)		cout<<"Numbers are equal"<<endl;
		else			cout<<"Numbers are not equal"<<endl;
	}
}
int main()
{
	input();
	readCheckDisplay();
	return 0;
}
