#pragma once
#include <vector>
#include "Task.h"

using namespace std;

//! \class TaskSolver
/*!
* The TaskSolver class includes a method for solving the problem
*
*/
class TaskSolver {
private:
	int recursionSolve(vector<Task> input, int i);

	int recSolveTaskIncluded(vector<Task> input, int i);

	int findIndexWhenIncluded(vector<Task> input, int i);

	void findSubResults(vector<int>& subResults, const vector<Task>& input, int len);

public:

	//! \fn Solve
	/*!
	* The method solves the problem using recursion
	*
	* \param input is a vector of Tasks. Input doesnt have to be ordered, the method orders it
	* \return integer with the maximum posible value we can get from the tasks
	*/
	int Solve(vector<Task> input);

	int DynamicSolve(vector<Task> input);
};