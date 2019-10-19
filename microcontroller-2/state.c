#include <state.h>
#include <string.h>

struct State state;

int periods[] = {1, 2, 3, 4};
int pins[] = {0x1000, 0x2000, 0x4000, 0x8000};

int getStateCounter() {
	return state.counter;
}

void setStateCounter(int value) {
	state.counter = value;
}

int getStateMode() {
	return state.mode;
}

void setStateMode(int value) {
	state.mode = value;
}

int getStateSum() {
	return state.sum;
}

void setStateSum(int value) {
	state.sum = value;
}

int* getStatePeriods() {
	return periods;
}

void setStatePeriods(int value[]) {
	memcpy(&value, &periods, sizeof value);
}

int* getStatePins() {
	return pins;
}
void setStatePins(int value[]) {
	memcpy(&value, &pins, sizeof value);
}
