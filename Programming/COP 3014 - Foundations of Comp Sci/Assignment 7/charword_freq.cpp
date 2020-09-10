/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: July 14, 2020                      Total Points: 10
Assignment#: 7 (Strings)

Description: Determines the number of words and the number of occurrences of each letter in a block of text stored in a data file.
*************************************************************************************************************************/

const int CAPACITY = 26; //declares and initialized CAPACITY as 26, a const. int for the size of array

#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way

//Function prototypes
void getWords(string fileName, string &wordString);
void processWords(string wordString, int& numWords);
void countLetters(string wordString, int letters[]);
char matchToLetter(int i);
void outputCounts(int letters[]);

//Function declarations

///*************************************************************************************
//Name:  getWords
//Precondition: Block of text has not yet been read from data file
//Postcondition: Block of text has been read from data file and stored in a string variable
//Description:  Stores text from data file in string variable
//*************************************************************************************

void getWords(string fileName, string &wordString){
    ifstream in; //declares a input file stream called "in"
    in.open(fileName); //opens input file stream and binds it to the file with name stored in fileName

    if(in.fail()){ //if opening ifstream fails...
        cout << "The input file \"" << fileName << "\" has failed to open." << endl;
        cout << "Check file name and trying again." << endl;
    }else{
    getline(in, wordString); //gets the whole black of text and stores it in wordString
    }

    in.close(); //closes input file stream
}

///*************************************************************************************
//Name:  processWords
//Precondition: Block of text is stored in a string variable
//Postcondition: String variable is read and processed to calculate the number of words
//Description:  Caculcates the number of words in a given string
//*************************************************************************************

void processWords(string wordString, int& numWords){
    int sLen = wordString.length();
    numWords = 0;

    for(int i = 0; i < sLen; i++){

        if(i == 0){
            if(!ispunct(wordString[i+1]) && !isspace(wordString[i+1])){
                numWords++;
            }
        }else if(i == (sLen -1)){
            if(!ispunct(wordString[i-1]) && !isspace(wordString[i-1])){
                    numWords++;
                }
        }

        if(ispunct(wordString[i]) || isspace(wordString[i])){
                if( !ispunct(wordString[i-1]) && !isspace(wordString[i-1]) && !ispunct(wordString[i+1]) && !isspace(wordString[i+1]) ){
                    numWords++;
                }
                }
        }

    }

///*************************************************************************************
//Name:  countLetters
//Precondition: Block of text is stored in a string variable
//Postcondition: String variable is read and processed to calculate the occurences of each letter
//Description: Stores the number of occruences of each letter in a string variable into an integer array
//*************************************************************************************

void countLetters(string wordString, int letters[]){
    
    int count = 0;
    for(char x: wordString){
        if(!ispunct(x) && !isspace(x))
            wordString[count] = tolower(x);
        count++;
    }

    for(char x: wordString){
        if(!ispunct(x) && !isspace(x)){
        switch(x){
            case 'a':
            letters[0]++;
            break;
            case 'b':
            letters[1]++;
            break;
            case 'c':
            letters[2]++;
            break;
            case 'd':
            letters[3]++;
            break;
            case 'e':
            letters[4]++;
            break;
            case 'f':
            letters[5]++;
            break;
            case 'g':
            letters[6]++;
            break;
            case 'h':
            letters[7]++;
            break;
            case 'i':
            letters[8]++;
            break;
            case 'j':
            letters[9]++;
            break;
            case 'k':
            letters[10]++;
            break;
            case 'l':
            letters[11]++;
            break;
            case 'm':
            letters[12]++;
            break;
            case 'n':
            letters[13]++;
            break;
            case 'o':
            letters[14]++;
            break;
            case 'p':
            letters[15]++;
            break;
            case 'q':
            letters[16]++;
            break;
            case 'r':
            letters[17]++;
            break;
            case 's':
            letters[18]++;
            break;
            case 't':
            letters[19]++;
            break;
            case 'u':
            letters[20]++;
            break;
            case 'v':
            letters[21]++;
            break;
            case 'w':
            letters[22]++;
            break;
            case 'x':
            letters[23]++;
            break;
            case 'y':
            letters[24]++;
            break;
            case 'z':
            letters[25]++;
            break;
            default:
            break;
            }
        }
    }
}

///*************************************************************************************
//Name:  matchToLetter
//Precondition: String variable is read and processed to calculate the occurences of each letter
//Postcondition: Each element/index in the integer array of occurences is matched to a letter
//Description: Matches the number of occurences to a letter.
//*************************************************************************************

char matchToLetter(int i){
        switch(i){
            case 0:
            return 'a';
            break;
            case 1:
            return 'b';
            break;
            case 2:
            return 'c';
            break;
            case 3:
            return 'd';
            break;
            case 4:
            return 'e';
            break;
            case 5:
            return 'f';
            break;
            case 6:
            return 'g';
            break;
            case 7:
            return 'h';
            break;
            case 8:
            return 'i';
            break;
            case 9:
            return 'j';
            break;
            case 10:
            return 'k';
            break;
            case 11:
            return 'l';
            break;
            case 12:
            return 'm';
            break;
            case 13:
            return 'n';
            break;
            case 14:
            return 'o';
            break;
            case 15:
            return 'p';
            break;
            case 16:
            return 'q';
            break;
            case 17:
            return 'r';
            break;
            case 18:
            return 's';
            break;
            case 19:
            return 't';
            break;
            case 20:
            return 'u';
            break;
            case 21:
            return 'v';
            break;
            case 22:
            return 'w';
            break;
            case 23:
            return 'y';
            break;
            case 24:
            return 'x';
            break;
            case 25:
            return 'z';
            break;
            default:
            return 'a';
        }

}

///*************************************************************************************
//Name:  outputCounts
//Precondition: String variable is read and processed to calculate the occurences of each letter
//Postcondition: Letter that appear and their occurences are properly output to the console.
//Description: Outputs letters and their occurences to console
//*************************************************************************************

void outputCounts(int letters[]){
    for(int i= 0; i < 26; i++){
        if( letters[i] != 0){
            cout << letters[i] << " " << matchToLetter(i) << endl;
        }
    }
}


int main(){

    string words; //Declares string to store the block of text as one word
    int numWords; //Declares int to store number of words
    int letters[CAPACITY] = {0}; //Declares and initializes int array with 0;

    getWords("word_data.txt", words); //gets words from "word_data.txt" data file and stores them in words string variable
    processWords(words, numWords); //processes string "words" and counts the number of words
    countLetters(words, letters);   //counts the ouccurences of each letter and stores them in an integer array 

    cout << "The number of words is: " << numWords << endl; //outputs the number of words to the console
    outputCounts(letters); //outputs each letter than appears and their how many times they appear to console

    return 0;
    }
