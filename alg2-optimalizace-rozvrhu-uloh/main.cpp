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

//! \class Task
/*!
* A Task contains information about the start time, end time and value of the Task \n
* 
*/
class Task {
public:
	//! Time when the task starts
	int start;
	//! Time when the task ends
	int end;
	//! The value we get when doing the task
	int value;

	//! Task constructor, all parameters are required
	Task(int s, int e, int v) {
		start = s;
		end = e;
		value = v;
	}

	//! Comparison operators compare the end times of two Tasks \n
	//! The algorithm needs to sort the Tasks to work properly 
	bool operator >(Task other) {
		return end > other.end;
	}
	bool operator <(Task other) {
		return end < other.end;
	}
};


//! \class TaskSolver
/*!
* The TaskSolver class includes a method for solving the problem
*
*/
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

	//! \fn Solve
	/*!
	* The method solves the problem using recursion
	* 
	* \param input is a vector of Tasks. Input doesnt have to be ordered, the method orders it
	* \return integer with the maximum posible value we can get from the tasks
	*/
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