#include<iostream>
#include<fstream>

using namespace std;

// all the variables are global so that each function can access it and we do not need pass argument
char word[50] = { '\0' };
char stopWord[50] = { '\0' };
char wordToSearch[50] = { '\0' };
int stopWordLength = 0;
int wordLength = 0;
int wordToSearchLength = 0;
int totalCount = 0;
int postiveCount = 0;
int negativeCount = 0;
int wordCount = 0;
int PositiveOrNegative = 0;

// simple function to find length of a word (used for finding length of stop word read from file)

void getStopWordLength()
{
	stopWordLength = 0;
	while (stopWord[stopWordLength] != '\0')
		stopWordLength++;
}

// Copy of the above find length function (used for finding length of word already written in file data.txt)
void getWordToSearchLength()
{
	wordToSearchLength = 0;
	while (wordToSearch[wordToSearchLength] != '\0')
		wordToSearchLength++;
}

// Copy of the above find length function (used for finding length of word a read sentence from file)
void getWordLength()
{
	wordLength = 0;
	while (word[wordLength] != '\0')
		wordLength++;
}

// comparison between word (to write on file data.txt) and word (already written in file data.txt)
// i.e. finding whether the word ispreviously present in file data.txt or not ? 
bool isWordFoundInDataFile()
{
	int i = 0;
	getWordLength(); // new word from sentence
	getWordToSearchLength(); // previous word from file data.txt
	if (wordToSearchLength == wordLength)
	{
		bool flag;
		while (word[i] != '\0')
		{
			if (wordToSearch[i] != word[i])
			{
				flag = 0;
				break;
			}
			i++;
			flag = 1;
		}

		if (flag == 1)
			return flag; // return 1 (TRUE) if both the words are same
	}

	return 0; // return 0 if length of the words are not same (without comparison - since length is not same)
}


// Function to update record in file data.txt
void writetofile()
{
	totalCount = 0;
	postiveCount = 0;
	negativeCount = 0;
	if (wordCount == 0) // first time write on a file (We do not have any data in file for comparison and update)
	{
		totalCount = 1; // initally total count would be one
		if (PositiveOrNegative == 0) // if sentence is negative
			negativeCount = 1;
		else // if sentence is positive
			postiveCount = 1;
		ofstream out("data.txt"); // write on a file
		out << word << ' ' <<totalCount<<' '<< postiveCount << ' ' << negativeCount << endl;
		//cout << word << ' ' << totalCount << ' ' << postiveCount << ' ' << negativeCount << endl;
		wordCount++; // updating variable for next comming turns for updating file data.txt

	}
	else // Other than first time write
	{
		ifstream infile("data.txt"); // file data.txt to update a file
		ofstream outfile("temp.txt"); // opening temp file to save for updated record
		bool anyChange = 0; // if word has found and updated, do not search for the rest
		while (1)
		{
			infile >> wordToSearch >> totalCount >> postiveCount >> negativeCount; // read from file fro comparison and update
			if (infile.eof())
			{
				break;
			}
			if (anyChange == 0 && isWordFoundInDataFile()) // if word is not previously updated --and-- word is found (see function above) 
			{
				totalCount++; // increament previous total count
				if (PositiveOrNegative == 0)
					negativeCount++;  // increament previous nagative count 
				else
					postiveCount++;  // increament previous positive count

				// after updatation, write it on the file tem.txt
				outfile << word << ' ' << totalCount<<' '<<postiveCount << ' ' << negativeCount << endl;
				//cout << word << ' ' << totalCount << ' ' << postiveCount << ' ' << negativeCount << endl;
				anyChange = 1; // update variable that helps in skipping for rest of the record items

			}
			else // Skip comparision..just write it (the read record from data.txt) on temp.txt file
			{
				outfile << wordToSearch << ' ' <<totalCount<<' '<< postiveCount << ' ' << negativeCount << endl;
				//cout << wordToSearch << ' ' << totalCount << ' ' << postiveCount << ' ' << negativeCount << endl;
			}
		}
		if (anyChange == 0) // if word is not found (this is new word to write at the end of file)
		{
			totalCount = 1;
			if (PositiveOrNegative == 0)
			{
				negativeCount = 1;
				postiveCount = 0;
			}
			else {
				postiveCount = 1;
				negativeCount = 0;
			}
			
			outfile << word << ' ' <<totalCount<<' '<< postiveCount << ' ' << negativeCount << endl;
			//cout << word << ' ' << totalCount << ' ' << postiveCount << ' ' << negativeCount << endl;
		}

		infile.close();
		outfile.close();
		// going to read from temp.txt and write to data.txt (going to overWrite data.txt with new updated record)
		infile.open("temp.txt");
		outfile.open("data.txt");
		while (1)
		{
			// continue read from file temp.txt
			infile >> word >> totalCount >> postiveCount >> negativeCount;
			if (infile.eof())
			{
				break;
			}
			else {
				// continue write to file data.txt	
				outfile << word << ' ' << totalCount << ' ' << postiveCount << ' ' << negativeCount << endl;
			}
		}
	}
}
void resetWord() // initialize/ set char variable word to NULL (we are going to read new word from sentence)
{
	for (int i = 0;i < 50; i++)
		word[i] = '\0';
}


bool isStopword() // Check the word is stop word or not?
{
	ifstream infile("stopwords.txt");
	//char stop[50] = { '\0' };
	bool flag = 0;
	int i = 0;
	getWordLength(); // function call : find length of the word

	while (!infile.eof())
	{
		infile >> stopWord; // read from stopWord.txt a word (called stopWord)
		i = 0;
		getStopWordLength(); // find length
		if (stopWordLength == wordLength) // compare if the lengths are same
		{
			while (stopWord[i] != '\0')
			{
				if (stopWord[i] != word[i]) // check char by char
				{
					flag = 0; // not a matched word
					break;
				}
				i++;
				flag = 1;
			}
			
			if (flag == 1) // if both the words are same return 1 (true)
				return flag;
		  }


	}




	return 0;

}
void convertWordtoLowerCase() // conversion to lower case
{
	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
			word[i] = word[i] + 32;
	}

}

int main()
{
	int x = 0;
	
	ifstream infile("rawdata.txt");
	int i = 0;
	
	char sentence[140] = { '\0' };
	
	while (!infile.eof())
	{
		// reading only one line from file data.txt
		infile.getline(sentence, 140);
		cout << sentence << endl << "Enter 1 for positive and 0 for negative";
		cin >>PositiveOrNegative;
		while (sentence[i]!='\0') // continue loop till sentence ends
		{
			int k = 0;
			// finding word one by one from previously read sentence
			for ( ; (sentence[i] != ' ' && sentence[i]!='.' && sentence[i]!='\0'); i++)
			{
				word[k] = sentence[i];
				k++;
				
			}

			// converting word in to lower case
			convertWordtoLowerCase();
			
			
			
			if (!isStopword()) // if the word is not a stop word
			{
				writetofile(); // write it into a file
            
			}
			
			
			
			resetWord(); // reset variable word to NULL
			i++;

		}
		i = 0; // set i=0 for new sentence 

	}



}
