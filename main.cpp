#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

int main(int argc, char* argv[]){
if (filesize(argv[1]) < (450+1024*1024)){
    cout << "file is too small and will not be split";
    return 0;
}
string line;
string prevLine;
int counter = 0;
int splitSize = 1000000; // 450 MGB
std::ifstream infile(argv[1]);


cout << argv[1] << " is spitting\n";
ofstream myfile1 ("part1.json");
ofstream myfile2 ("part2.json");
queue<string> myqueue;
bool isSecondPart = false;

while (getline(infile, line))
{
    counter++;
    istringstream iss(line);

if (isSecondPart == false){
    myqueue.push(line);
    if (myqueue.size() > 3){
        myqueue.pop();
    }  
    // cout << line << "\n";
    if ((counter > splitSize) && (myqueue.front().find("},") != string::npos) && (prevLine.find("{") != string::npos) && (line.find("\"package_label_principal_display_panel\":") != string::npos) ){
        cout << counter << "is line where to split\n";
        myfile1 << "}\n]\n}" << "\n";
        cout << "part1 iis ready\n";
        
        isSecondPart = true;
        myfile2 << "{" << "\n";
        myfile2 << "\"results\": [" << "\n";
        myfile2 << "{" << "\n";
       myfile2 << line << "\n";
        
        
    } 
    prevLine = line;
    
   if (myfile1.is_open())
   {
    myfile1 << line << "\n";
    }
   else {
      cout << "Unable to open the first file";
      break;
  }
} 
// save the second part
else{
    
    myfile2 << line << "\n";
    

}

}


myfile1.close();
myfile2                                                                                                                        .close();


return 0;
}


