#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

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


class Task {
public:
	int start;
	int end;
	int value;

	Task(int s, int e, int v) {
		start = s;
		end = e;
		value = v;
	}

	bool operator >(Task other) {
		return end > other.end;
	}
	bool operator <(Task other) {
		return end < other.end;
	}
};


class TaskSolver {
private:
	int recursionSolve(vector<Task> input, int i) {
		if (i == 1) return input[i-1].value;

		int taskSkipped = recursionSolve(input, i - 1);
		int taskIncluded = recSolveTaskIncluded(input, i - 1);

		return max(taskSkipped, taskIncluded);
	}

	int recSolveTaskIncluded(vector<Task> input, int i) {
		int result = input[i].value;

		int j = i;
		while (j>=0) {
			if (input[j].end <= input[i].start) {
				break;
			}
			j--;
		}

		if (j < 0) {
			return result;
		}

		result = result + recursionSolve(input, j + 1);
		return result;
	}

public:

	int Solve(vector<Task> input) {
		int len = input.size();
		sort(input.begin(), input.end());
		return recursionSolve(input, len);
	}

};



int main(int argc, char* argv[]) {

	vector<int> input = readIntegersFromFile(argv[1]);

	vector<Task> tasks;
	int taskCount = input[0];

	for (int i = 0; i < taskCount; i++) {
		tasks.push_back(Task(input[i * 3 + 1], input[i * 3 + 2], input[i * 3 + 3]));
	}

	TaskSolver ts = TaskSolver();

	int result = ts.Solve(tasks);

	cout << result << endl;

	return 0;
}