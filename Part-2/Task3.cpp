#include<iostream>
#include<fstream>

using namespace std;

void readCheckDisplay()
{
	char std1[20] = {'\0'}, std2[20] = "Good";
	int len1 = 0, len2 = 0;
	int flag = 0;
	int numOfGood = 0;
	ifstream read;
	read.open("task3.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		read>>std1;
		
		while(!read.eof())
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
			if (flag == 1)		
			{
				numOfGood++;
				flag = 0;
			}
			read>>std1;
		}
		read.close();
		cout<<"Number of Good = "<<numOfGood<<endl;
	}
}
int main()
{
	readCheckDisplay();
	return 0;
}
