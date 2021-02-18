#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//global variable!!!
std::string options[] = {"[road]","[west]"," "," "," "};

void ReadFile(const std::string& filename, std::string str) {
	
	std::string line;
	std::string buffer;
  	std::ifstream myfile (filename);
  	bool inRightSection = false; 
  	int firstSpace;
  	int secondSpace;
  	int index = 0;
  	
  	
    //	std::cout << str;
  	
	if (myfile.is_open()){	
	    while ( getline (myfile,line) ){
	    	if (line.find('[') != std::string::npos){
	    		inRightSection = false;
			}
			
	    	if (inRightSection){
	    		//i should search the line to see if it starts with '#'
	    		if(line.compare(0,1,"#") == 0){
	    			//std::cout << "ha! i found a choice." << "\n";
	    			//i should save the word after the "##" into an 'options' list so that the user can chose one for their next turn
	    			firstSpace=line.find(" ");
	    			secondSpace=line.find(" ",firstSpace+1);
	    			buffer = line.substr(firstSpace,(secondSpace - firstSpace)); //(startPos, Len)
	    			buffer = buffer.substr(1); 
	    			options[index] = "[" +buffer +"]";
	    			//std::cout << options[index] << "\n";
	    			index++;
	    			//std::cout << firstSpace << " " << secondSpace << " "<< buffer << "\n";
	    			//i should not print out that word but i should print the rest of the line: "#3 disription of the option"
	    			line.erase (firstSpace,(secondSpace-firstSpace));	
				}
	    		std::cout << line << "\n";
			}
			if (line.find(str)!=std::string::npos){
	    		inRightSection = true;
	    	}
	    }
	    myfile.close();
	}
	else std::cout << "Unable to open file"; 
	//return line; //this should actually return an array of string options?	
}

int main() {
	int choice = 0;
	//game loop
		//readFile
			//readfile should print out the description of the room and return choise opotions for the user
		//get user input choise
    while(true){
    	//std::cout << choice;
		ReadFile("adventure.txt", options[choice]); 
		std::cin >> choice;
		choice--; 
		
		
	}
}
