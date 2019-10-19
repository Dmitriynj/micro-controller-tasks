#include <on-button-pressed-logic.h>
#include <state.h>
#include <config.h>

void onPressButton() {
	int mode = getStateMode();

	if (mode == 1) {
		mode = 2;
		setTime(960);
		setTim4();
	} else {
		mode = 1;
		setTime(480);
		setTim4();
	}

	setStateMode(mode);
}
