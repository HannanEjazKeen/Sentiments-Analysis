#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char inName[10] = {'\0'};
	int len1 = 0, len2 = 0, flag = 0;
	cout<<"Enter name to search"<<endl;
	cin>>inName;

	ifstream fname;
	fname.open("firstname.txt",ios::in);
	if (!fname.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	
	char firstName[10] = {'\0'};

	for (int i = 0;i<10;i++)
	{
		fname>>firstName;
		int count = 0;
		while(firstName[count]!='\0')		count++;
		len1 = count;
		
		count = 0;
		while(inName[count]!='\0')		count++;
		len2 = count;

		if (len1 == len2)
		{
			int index = 0;
			for (index=0;index<len1;index++)
			{
				flag = 1;
				if (firstName[index] != inName[index])
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag==1)
		{
			cout<<"Name found"<<endl;
			break;
		}
	}
	fname.close();
	if (flag == 0)		cout<<"Name not found"<<endl;
	
	return 0;
}
