#include <iostream>
#include <fstream> 
#include <cstdlib>
using namespace std; 
/*

the main goal is to provide filename and filecontent from the command line

*/
int exitcode;
void exit (int exitcode);

int main (int argc, char* argv[]) 
{ 
  if (argc <= 1)
    {
    cout << "Usage: " << argv[0] << " string destination \n\n";
    cout << "all extra arguments will be ignored\n";
    //void exit (int exitcode);    
    exitcode=0;
    exit(exitcode);
    }
  char filename1[] = "./text.text";
  char filecontent[] ="adding new line to file\n";

  ifstream inFile; 
  inFile.open (filename1);
  //inFile.open ("text.text");

  if (inFile.fail()) 
    { 
    cout << "Could Not Open file: " << filename1 << "\n"; 
    cout << "Creating new file: " << filename1 << "\n";
    ofstream outFile;
    outFile.open(filename1, ios::app);
    //outFile << "adding new line to file \n";
    outFile << "first line \n" << filecontent;
    outFile.close();
    } 

  else 
    { 
    cout << "File: " << filename1 << " exists and can be opened.\n"; 
    ofstream outFile;
    outFile.open(filename1, ios::app);
    outFile << filecontent;
    outFile.close();
    } 
  return 0;
}
