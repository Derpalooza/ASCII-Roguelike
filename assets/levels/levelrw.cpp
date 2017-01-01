#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	
	ofstream myfile;
	
	myfile.open("myfile");
	myfile << "Testing\n";
	myfile << "mah\n";
	myfile << "file\n";
	myfile.close();
	return 0;
}
