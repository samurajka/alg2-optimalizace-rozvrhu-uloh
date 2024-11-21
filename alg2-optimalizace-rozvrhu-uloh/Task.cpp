#include "Task.h"

Task::Task(int s, int e, int v) {
	start = s;
	end = e;
	value = v;
}

bool Task::operator >(Task other) {
	return end > other.end;
}

bool Task::operator <(Task other) {
	return end < other.end;
}
