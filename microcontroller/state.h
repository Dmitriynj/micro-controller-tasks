#pragma once
#ifndef _STATE_H_
#define _STATE_H_

struct StateDef {
  int value;
};

void initState();

void setState(struct StateDef);
struct StateDef getState();

void executeState();
void toggleStateMode();

#endif
