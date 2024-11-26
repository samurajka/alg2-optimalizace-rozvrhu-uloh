#pragma once
#include <vector>
#include "Task.h"

using namespace std;

//! \class TaskSolver
/*!
* The TaskSolver class includes a methods for solving the problem
*
*/
class TaskSolver {
private:
	//! \fn recursionSolve
	/*!
	* The method is called recursively until i == 1
	* calls itself with i-1 and recSolveTaskIncluded then returns the maximum of the two
	* 
	* \param input is a vector of Tasks.
	* \param i is the index for which we want to calculate the maximum value
	* \return integer with the maximum posible value we can get from the tasks so far
	*/
	int recursionSolve(vector<Task> input, int i);

	//! \fn recSolveTaskIncluded
	/*!
	*  Similar to recursionSolve but it has to find the next task that doesnt conflict with input[i]
	* 
	* \param input is a vector of Tasks.
	* \param i is the index for which we want to calculate the maximum value
	* \return integer with the maximum posible value we can get from the tasks so far
	*/ 
	int recSolveTaskIncluded(vector<Task> input, int i);



	//! \fn findIndexWhenIncluded
	/*!
	* finds index of next task that doesnt overlap with input[i]
	*
	* \param input is a vector of Tasks
	* \param i is the index of the Task we dont want to overlap
	*/
	int findIndexWhenIncluded(vector<Task> input, int i);

	//! \fn findSubResults
	/*!
	* recursively solves subproblems and stores the values in subResults
	* 
	* \param subResults vector where the subResults will be stored
	* \param input vector of tasks
	* \param len lenght of the vectors
	*/
	void findSubResults(vector<int>& subResults, const vector<Task>& input, int len);

public:

	//! \fn Solve
	/*!
	* The method solves the problem using a brute force recursive approach \n
	* It starts by sorting the array and then calls the recursionSolve private method
	*
	* \param input is a vector of Tasks. Input doesnt have to be ordered, the method orders it
	* \return integer with the maximum posible value we can get from the tasks
	*/
	int Solve(vector<Task> input);


	//! \fn DynamicSolve
	/*!
	* The method solves the problem using a dynamic programing approach
	*
	* \param input is a vector of Tasks. Input doesnt have to be ordered, the method orders it
	* \return integer with the maximum posible value we can get from the tasks
	*/
	int DynamicSolve(vector<Task> input);
};