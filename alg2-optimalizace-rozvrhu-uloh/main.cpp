#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Task.h"
#include "TaskSolver.h"

using namespace std;


std::vector<int> readIntegersFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::vector<int> numbersVec;
	if (!file.is_open()) {
		std::cerr << "Unable to open file: " << filename << std::endl;
		return numbersVec;
	}
	std::string line;
	// change if to while to read the whole file
	while (std::getline(file, line)) {
		std::stringstream lineAsStream(line);
		int num;
		while (lineAsStream >> num) {
			numbersVec.push_back(num);
		}
	}
	file.close();
	return numbersVec;
}



int main(int argc, char* argv[]) {

	vector<int> input = readIntegersFromFile(argv[1]);

	vector<Task> tasks;
	int taskCount = input[0];

	for (int i = 0; i < taskCount; i++) {
		tasks.push_back(Task(input[i * 3 + 1], input[i * 3 + 2], input[i * 3 + 3]));
	}

	TaskSolver ts = TaskSolver();

	int result = ts.Solve(tasks);

	cout << "Brute Force: ";
	cout << result << endl;

	cout << endl;

	result = ts.DynamicSolve(tasks);

	cout << "Dynamicky: ";
	cout << result << endl;

	return 0;
}