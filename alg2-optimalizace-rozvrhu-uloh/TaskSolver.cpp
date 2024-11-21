#include "TaskSolver.h"
#include <algorithm>

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

