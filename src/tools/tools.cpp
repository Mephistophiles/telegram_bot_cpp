#include <string>
#include <vector>
#include <sstream>

using namespace std;

string StringJoin(vector<string> vect, string delim) {
	stringstream ss;

	for (size_t i = 0; i < vect.size(); ++i) {
		if (i != 0)
			ss << delim;

		ss << vect[i];
	}

	return ss.str();
}
