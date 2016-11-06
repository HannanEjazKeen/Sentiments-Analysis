#include<iostream>
#include<fstream>

using namespace std;

void input()
{
	char std1[20] = {'\0'};
	char std2[20] = {'\0'};
	float m1 = 0,m2 = 0;
	cout<<"Enter your name"<<endl;
	cin.getline(std1,20);

	cout<<"Enter your marks in PF Quiz 1"<<endl;
	cin>>m1;
	
	cin.ignore();

	cout<<"Enter your name"<<endl;
	cin.getline(std2,20);

	cout<<"Enter your marks in PF Quiz 1"<<endl;
	cin>>m2;


	ofstream write;
	write.open("task1.txt",ios::out);
	if (!write.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		write<<std1<<endl<<m1<<endl<<std2<<endl<<m2<<endl;
		write.close();
	}
}

void readCheckDisplay()
{
	char std1[20] = {'\0'}, std2[20] = {'\0'};
	float m1 = 0, m2 = 0;
	int len1 = 0, len2 = 0;
	int flag = 0;
	ifstream read;
	read.open("task1.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		read.getline(std1,20);
		read>>m1;
		read.ignore();
		read.getline(std2,20);
		read>>m2;
		read.close();

		if (m1 == m2)
		{
			int count = 0;
			while(std1[count]!='\0')	count++;
			len1 = count;
			count = 0;
			while(std2[count]!='\0')	count++;
			len2 = count;
			if (len1 == len2)
			{
				flag = 1;
				for (count = 0; count < len1; count++)
				{
					if (std1[count] != std2[count])
					{
						flag = 0;
						break;
					}
				}				
			}
		}
		if (flag == 1)		cout<<"Both records are same"<<endl;
		else			cout<<"Both records are not same"<<endl;
	}
}
int main()
{
	input();
	readCheckDisplay();
	return 0;
}
