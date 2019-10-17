#include <config.h>
#include <state.h>

int main(void){
	setConfig();
	initState();

	while(1) {
		executeState();
	}
}
