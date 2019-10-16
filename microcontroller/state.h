#pragma once
#ifndef _STATE_H_
#define _STATE_H_

struct StateDef {
  int value;
};

void executeState(struct StateDef state);
void toggleStateMode(struct StateDef state);

#endif
