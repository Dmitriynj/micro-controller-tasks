#include <config.h>
#include <state.h>
#include <stdio.h>

int main(void){
	setConfig();
	struct StateDef state = getStateInstance();

	while(1) {
		executeState(state);
	}
}
