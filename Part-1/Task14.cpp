#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char sentence[140] = {'\0'};
	char word[20] = {'\0'};
	
	ifstream read;
	ofstream write;
	read.open("sentence.txt",ios::in);
	if (!read.is_open())
	{
		cout<<"File not opened"<<endl;
		return 0;
	}
	
	read.getline(sentence,140);
	
	while (!read.eof())
	{
		cout<<sentence<<endl;
		int index = 0;
		while (sentence[index]!='\0')
		{
			int index2 = 0;
			for (index2 = 0;sentence[index+index2] != '\0' && sentence[index+index2] != ' ';index2++)
			{
				word[index2] = sentence[index+index2];
			}
			word[index2] = '\0';
			if (index2>3)		cout<<word<<endl;
			index = index + index2 + 1;
		}
		read.getline(sentence,140);
	}
	read.close();
	
	return 0;
}
