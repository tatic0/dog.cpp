#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>

/*
F Varas July 2012

Dog is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Dog is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Dog.  If not, see <http://www.gnu.org/licenses/>.
*/

using namespace std; 
/*

the main goal is to provide filename and filecontent from the command line

*/
int exitcode;
void exit (int exitcode);

int main (int argc, const char* argv[]) 
{ 
  if (argc <= 2)
    {
    cout << "Usage: " << argv[0] << " string destination \n\n";
    cout << "all extra arguments will be ignored\n";
    //void exit (int exitcode);    
    exitcode=4;
    exit(exitcode);
    }
  else if (argc > 2)
    {
    std::string argv1 = argv[1]; 
    std::string argv2 = argv[2];
    //int content = atoi(argv[1]);
    string content = argv[1];     //fuck it works!!!
    //string filename = argv[2];
    /*
    two next vars are useless, i'll keep them as a reminder by now.
    */
    char filename[] = "./text.text";
    char filecontent[] = "new line added\n";
    
    ifstream inFile; 
    inFile.open(argv[2]);

    if (inFile.fail()) 
      { 
      cout << "Could Not Open file: " << filename << "\n"; 
      cout << "Creating new file: " << filename << "\n";
      ofstream outFile;
      outFile.open(argv[2], ios::app);
      outFile << "first line \n" << filecontent;
      outFile.close();
      } 

    else 
      { 
      cout << "File: " << filename << " exists and can be opened.\n"; 
      ofstream outFile;
      outFile.open(argv[2], ios::app);
/*
add test (if int, or so) if necessary
*/
      outFile << content << "\n";
      outFile.close();
      }
    } 
  return 0;
}
