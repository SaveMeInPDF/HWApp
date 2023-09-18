#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

class GetCSV {
public:
	string get(char value)
	{
		setlocale(LC_ALL, "Russian");
		string fname = "city.csv";
		map<char, vector<string>> cities;
		vector<string> row;
		string line, word;
		string a = "123";

		fstream file(fname, ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{

				cities[line[0]].push_back(line);
			}
		}
		else
			cout << "Could not open the file\n";


		auto rng = default_random_engine{ random_device{}()};
		shuffle(begin(cities[value]), end(cities[value]), rng);

		return cities[value][0];
	}
};


int main() {
	GetCSV gcsv;

	cout << gcsv.get('À');
}