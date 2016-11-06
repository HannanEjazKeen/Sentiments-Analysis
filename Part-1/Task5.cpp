#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char in[10] = {'\0'};
	char ext[5] = ".txt";
	char fileName[15] = {'\0'};
	cout<<"Enter First Name"<<endl;
	cin>>in;
	int count = 0;
	while(in[count]!='\0')
	{
		fileName[count] = in[count];
		count++;
	}
	for (int i=0;ext[i]!='\0';i++)
	{
		fileName[count+i] = ext[i];
	}
	cout<<fileName<<endl;

	ofstream write;
	write.open(fileName,ios::out);
	if (!write.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}	
	write<<in<<endl;
	write.close();

	char in2[20] = {'\0'};
	ifstream read;
	read.open(fileName,ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	read>>in2;
	read.close();
	cout<<in2<<endl;

	return 0;
}
