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
}
