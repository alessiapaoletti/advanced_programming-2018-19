/* uniq
Write a simple version of the Unix program uniq -c, which, when fed with a text,
outputs the same text with consecutive identical lines collapsed to one prepended with the number of repetitions */

#include <iostream>
int main() {
	std::string line,line1;
	int count{1};
	getline(std::cin,line);
	line1=line;
	while(std::getline(std::cin,line))
	{
		if (line==line1) count++;
		else {
		std::cout << count <<  " " << line1<<std::endl;
		line1=line;
		count = 1;
		}
	}
	std::cout << count <<  " " << line1<<std::endl;
	return 0;
}
