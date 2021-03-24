#include <iostream>
#include <fstream>
#include <string>

int main() {
	int N = 99;
	int n = 15;

	std::string outFile = "same_length.dat";
	std::ofstream out(outFile);


	for (int i = 0; i < 9; i++) {
		out << i + 1;
		for (int j = 0; j < n-1; j++) {

			out << (i % 10 + 1) % 10;

		}

		out << "\n";
	}

	for (int i = 9; i < N; i++) {
		out << i + 1;
		for (int j = 0; j < n - 2; j++) {

			out <<( i % 10 + 1) % 10;

		}

		out << "\n";
	}
	out.close();


	std::string inFile = "same_length.dat";
	std::ifstream in(inFile);

	int m;
	std::cout << "enter number of line 1 - 99" << std::endl;
	std::cin >> m;
	int a = (m-1)*(n + 2);
	
	in.seekg(a, std::ios::beg );
	std::cout << in.tellg() << std::endl;

	std::string line;
	getline(in, line);
	std::cout << line << std::endl;




	


}

