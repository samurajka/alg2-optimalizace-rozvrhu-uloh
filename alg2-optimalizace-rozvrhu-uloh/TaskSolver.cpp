#include "TaskSolver.h"
#include <algorithm>

////////////////////////////////////////////
// Brute Force øešení
int TaskSolver::recursionSolve(vector<Task> input, int i) {
	if (i == 1) return input[i - 1].value;

	int taskSkipped = recursionSolve(input, i - 1);
	int taskIncluded = recSolveTaskIncluded(input, i - 1);

	return max(taskSkipped, taskIncluded);
}

int TaskSolver::recSolveTaskIncluded(vector<Task> input, int i) {
	int result = input[i].value;

	int j = i;
	while (j >= 0) {
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


int TaskSolver::Solve(vector<Task> input) {
		int len = input.size();
		sort(input.begin(), input.end());
		return recursionSolve(input, len);
}
// Brute Force øešení
///////////////////////////////////////////////////


//////////////////////////////////////////////////
// Dynamicke programovani
int TaskSolver::findIndexWhenIncluded(vector<Task> input, int i) {
	int j = i;//
	while (j >= 0) {
		if (input[j].end <= input[i].start) {
			break;
		}
		j--;
	}

	return j; // vyhodi -1 pokud tam nic neni
}

void TaskSolver::findSubResults(vector<int> &subResults, const vector<Task> &input, int len) {
	for (int i = 1; i < len;i++) {
		int taskIncluded = input[i].value;
		int prevIndex = findIndexWhenIncluded(input, i);

		if (prevIndex != -1) { taskIncluded += subResults[prevIndex]; }

		subResults[i] = max(taskIncluded, subResults[i - 1]);
	}
}

int TaskSolver::DynamicSolve(vector<Task> input) {
	int result = 0;
	int len = input.size();
	sort(input.begin(), input.end());

	vector<int> subResults(len);
	subResults[0] = input[0].value;

	findSubResults(subResults, input, len);

	result = subResults[len - 1];
	return result;
}
// Dynamicke programovani
////////////////////////////////////////////////////