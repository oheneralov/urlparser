#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

int main(){
string line;
string prevLine;
int counter = 0;
int splitSize = 1000000; // 45 MGB
std::ifstream infile("drug-label-0006-of-0007.json");
ofstream myfile1 ("part1.json");
ofstream myfile2 ("part2.json");
queue<string> myqueue;

while (getline(infile, line))
{
    counter++;
    istringstream iss(line);
    myqueue.push(line);
    if (myqueue.size() > 3){
        myqueue.pop();
    }  
    // cout << line << "\n";
    if ((counter > splitSize) && (myqueue.front().find("},") != string::npos) && (prevLine.find("{") != string::npos) && (line.find("\"package_label_principal_display_panel\":") != string::npos) ){
        cout << "found\n";
        myfile1 << "}\n]\n}" << "\n";
        
        break;
    }
    prevLine = line;
    
   if (myfile1.is_open())
   {
    myfile1 << line << "\n";
    }
  else {
      cout << "Unable to open file";
      break;
  }
/*
  if (counter > 1000){
      cout << "not found\n";
      break;
   }
*/

}

myfile1.close();



return 0;
}


