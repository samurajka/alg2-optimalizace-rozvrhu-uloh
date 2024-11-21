#pragma once
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
	Task(int s, int e, int v);

	//! Comparison operators compare the end times of two Tasks \n
	//! The algorithm needs to sort the Tasks to work properly 
	bool operator >(Task other);
	bool operator <(Task other);
};

