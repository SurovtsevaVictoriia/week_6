#include <iostream>
#include <string>
#include <fstream>



int main() {

	std::string inFile = "test.cpp";

	std::string outFile = "outfile.dat";
	std::ofstream out(outFile);

	if (!out.is_open()) {
		std::cerr << "cannot open outFile" << outFile << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream in(inFile);

	if (!in.is_open()) {
		std::cerr << "cannot open inFile" << inFile << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;

	bool multi_line_flag = 0;
	bool string_section_flag = 0;


	while (std::getline(in, line)) {

		int id = 0;

		std::string buffer_line;


		if (multi_line_flag && (line.find("*/") != -1)){
			id = line.find("*/") + 2;
			multi_line_flag = 0;
		}
		else if (multi_line_flag && (line.find("*/") == -1)) {
			buffer_line = "";
			id = line.size();
		}

		std::string buffer_line_without_single_line;
		if (line.find("//") != -1) {

			for (int i = id; i < line.find("//"); i++) {

				buffer_line_without_single_line += line[i];

			}
		}
		else buffer_line_without_single_line = line;

		line = buffer_line_without_single_line;
		id = 0;


		for (int i = id; i < line.size(); i++) {

		
				if( (line.find("/*", i) == i) && !string_section_flag) {
					multi_line_flag = 1; 
					break;
				}

				if ((line.find("\"", i) == i) && !string_section_flag) {
					string_section_flag = 1;
				}
				else if ((line.find("\"", i) == i) && string_section_flag) {
					string_section_flag = 0;
				}

				buffer_line += line[i];

					
		}
				

		out << buffer_line <<"\n";
	
	}


	out.close();
	in.close();
	
}