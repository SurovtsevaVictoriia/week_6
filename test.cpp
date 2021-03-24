#include <iostream> //comment
#include <fstream>
/*#include <cmath>
#include */ <string> //comment

//single line comment 
double tan_(double x) { return tan(x); } //tangent
double sin_(double x) { return sin(x); } //sinus

auto function_print(double f(double), double start = 0.0, double end = 10.0, double step = 1.0) {

	using namespace std;
	string outFile = "out.dat";

	ofstream out(outFile);
	//ofstream out;
	//out.open(outFile);

	if (!out.is_open()) {
		cerr << "cannot /*not a comment*/ open outFile"; /*<< outFile << endl;
		return EXIT_FAILURE;*/ int a = 0; //comment
	}
	/*
	for (auto i = start; i <= (end / step); ++i) {
		out << i * step << "\t" << f(i * step) << "\n";
	}

	out.close();
	*/
}

int main() {

	function_print(sin_, 0, 5, .05);

	return EXIT_SUCCESS;
}