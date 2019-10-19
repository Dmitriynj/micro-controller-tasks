#pragma once
#ifndef _STATE_H_
#define _STATE_H_

struct State {
	int counter;
	int mode;
	int sum;
};

int getStateValue();
void setStateValue(int);

int getStateMode();
void setStateMode(int);

int getStateSum();
void setStateSum(int);

int* getStatePeriods();
void setStatePeriods(int*);

int* getStatePins();
void setStatePins(int*);


#endif
