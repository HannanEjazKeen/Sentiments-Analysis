#include<iostream>
#include<fstream>

using namespace std;

void readCheckDisplay()
{
	char std1[100] = {'\0'}, std2[20] = "good";
	char wrd[20] = {'\0'};
	int len1 = 0, len2 = 0;
	int flag = 0;
	int numOfGood = 0;

	int count = 0;
	while(std2[count]!='\0')	count++;
	len2 = count;

	ifstream read;
	read.open("task5.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
	}
	else
	{
		read.getline(std1,100);
		
		while(!read.eof())
		{
			for (int index = 0; std1[index] != '\0'; index++)
			{
				int index2 = 0;
				for (int i = index; std1[i] != ' ' && std1[i] != '\0'; i++)
				{
					wrd[index2] = std1[i];
					index2++;
				}
				wrd[index2] = '\0';
				len1 = index2;
							
				if (len1 == len2)
				{
					flag = 1;
					for (count = 0; count < len1; count++)
					{
						if (wrd[count] != std2[count])
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
					break;
				}
				
				index = index + index2;

			}

			read.getline(std1,100);
		}
		read.close();		
		cout<<"Number of Sentences having good = "<<numOfGood<<endl;

	}
}
int main()
{
	readCheckDisplay();
	return 0;
}
