#ifndef ENEMIES_H
#define ENEMIES_H

#include <Arduino.h>

#define MAX_ENEMIES             8
#define GAME_LEFT               3

#define GAME_TOP                3
#define GAME_BOTTOM             54

#define ENEMY_BAD               0
#define ENEMY_JELLY             1
#define ENEMY_EEL               2
#define ENEMY_STAR              3 // enemy turned into starfish
#define ENEMY_BUBBLE            4 // enemy turned into bubbles

#define BURST_LENGTH            15
#define BURST_WAIT              20

#define PU_TURNFISH     0
#define PU_STOPFISH     1
#define PU_SHOOTFISH    2
#define PU_POPFISH      3
#define PU_PROTECTFISH  4
#define PU_LIFEFISH     5
#define PU_SHOCKFISH    6
#define PU_MAGNETFISH   7

extern Arduboy arduboy;
extern byte getPowerup(byte);
extern const unsigned char starFish_plus_mask[];

byte fishFrame = 0;

PROGMEM const unsigned char badFishy_plus_mask[] = {
  // width, height
  16, 16,
  // frame 0
  0x00, 0x80, 0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC,
  0x8C, 0xFE, 0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAB, 0xFF,
  0x29, 0xFF, 0x48, 0xFD, 0x70, 0xF8, 0x70, 0xFC, 0xFC, 0xFE,
  0x00, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07,
  0x02, 0x07, 0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x01, 0x07,
  0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x00, 0x03, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x01,
  // frame 1
  0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE,
  0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF,
  0xD9, 0xFF, 0x70, 0xF9, 0x60, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC,
  0x00, 0xFC, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x02, 0x07,
  0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F,
  0x06, 0x0F, 0x06, 0x0F, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x03, 0x00, 0x03,
  // frame 2
  0x80, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE, 0xA4, 0xFF,
  0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF, 0x99, 0xFF,
  0xF0, 0xF9, 0x60, 0xF0, 0xE0, 0xF0, 0xF0, 0xF8, 0x00, 0xF8,
  0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x07, 0x03, 0x07,
  0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F, 0x0E, 0x0F,
  0x0D, 0x0F, 0x00, 0x0F, 0x00, 0x01, 0x01, 0x07, 0x07, 0x0F,
  0x00, 0x0F, 0x00, 0x00,
  // frame 3
  0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE,
  0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF,
  0xD9, 0xFF, 0x70, 0xF9, 0x60, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC,
  0x00, 0xFC, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x02, 0x07,
  0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F,
  0x06, 0x0F, 0x06, 0x0F, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x03, 0x00, 0x03,
};

PROGMEM const unsigned char jellyFish_plus_mask[] = {
  // width, height
  16, 24,

  // frame 0
  0x00, 0x80, 0x80, 0xE0, 0x60, 0xF0, 0x10, 0xF8, 0x28, 0xFC,
  0xB8, 0xFC, 0x94, 0xFE, 0x84, 0xDE, 0x84, 0xCE, 0x84, 0xCE,
  0x88, 0xDC, 0x08, 0x9C, 0x10, 0xF8, 0x60, 0xF0, 0x80, 0xE0,
  0x00, 0x80, 0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x08, 0xFF,
  0xEF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x07, 0xFF, 0x07, 0xFF,
  0xE7, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0x08, 0xFF, 0x08, 0x1F,
  0x07, 0x0F, 0x00, 0x07, 0x00, 0x0C, 0x08, 0x1C, 0x08, 0x1C,
  0x04, 0x0F, 0x03, 0xF7, 0x70, 0xFF, 0x0F, 0x7F, 0x00, 0x0F,
  0x00, 0x0F, 0x0F, 0x7F, 0x70, 0xFF, 0x03, 0xF7, 0x04, 0x0F,
  0x08, 0x1C, 0x08, 0x1C, 0x00, 0x0C,
  // frame 1
  0x00, 0x80, 0x80, 0xC0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0,
  0x50, 0xF8, 0x10, 0x78, 0x10, 0x38, 0x10, 0x38, 0x10, 0x38,
  0x10, 0x38, 0x20, 0x70, 0x20, 0x70, 0x40, 0xE0, 0x80, 0xC0,
  0x00, 0x80, 0x0F, 0x1F, 0x10, 0x3F, 0x10, 0x3F, 0x18, 0xFF,
  0xDC, 0xFF, 0x0E, 0xFF, 0xCE, 0xFF, 0x0E, 0xFF, 0x0E, 0xFF,
  0xCE, 0xFF, 0x0E, 0xFF, 0xDC, 0xFF, 0x18, 0xFE, 0x10, 0x3F,
  0x10, 0x3F, 0x0F, 0x1F, 0x04, 0x0E, 0x04, 0x0E, 0x04, 0x6E,
  0x22, 0x77, 0x11, 0x3B, 0x08, 0x1F, 0x07, 0x0F, 0x00, 0x07,
  0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x11, 0x3B, 0x22, 0x77,
  0x04, 0x6E, 0x04, 0x0E, 0x04, 0x0E,
  // frame 2
  0x00, 0x80, 0x80, 0xE0, 0x60, 0xF0, 0x10, 0xF8, 0x28, 0xFC,
  0xB8, 0xFC, 0x94, 0xFE, 0x84, 0xDE, 0x84, 0xCE, 0x84, 0xCE,
  0x88, 0xDC, 0x08, 0x9C, 0x10, 0xF8, 0x60, 0xF0, 0x80, 0xE0,
  0x00, 0x80, 0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x08, 0xFF,
  0xEF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x07, 0xFF, 0x07, 0xFF,
  0xE7, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0x08, 0xFF, 0x08, 0x1F,
  0x07, 0x0F, 0x00, 0x07, 0x00, 0x1C, 0x0C, 0x1E, 0x02, 0x0F,
  0x01, 0x63, 0x20, 0x71, 0x10, 0x3F, 0x0F, 0x1F, 0x00, 0x0F,
  0x00, 0x0F, 0x0F, 0x1F, 0x10, 0x3F, 0x20, 0x71, 0x01, 0x63,
  0x02, 0x0F, 0x0C, 0x1E, 0x00, 0x1C,
  // frame 3
  0x00, 0x00, 0x00, 0xE0, 0xE0, 0xF8, 0x18, 0xFC, 0x04, 0xFE,
  0x9A, 0xFF, 0xCD, 0xFF, 0xE1, 0xFF, 0xE1, 0xF3, 0xC1, 0xE3,
  0x82, 0xC7, 0x04, 0x9E, 0x18, 0xFC, 0xE0, 0xF8, 0x00, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x04, 0xFF,
  0xF4, 0xFF, 0x07, 0xFF, 0xF7, 0xFF, 0x03, 0xFF, 0x03, 0xFF,
  0xF7, 0xFF, 0x07, 0xFF, 0xF4, 0xFF, 0x04, 0xFF, 0x03, 0x07,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0x1F, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF,
  0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x1F, 0x3F, 0x00, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

PROGMEM const unsigned char eel_plus_mask[] = {
// width, height
80, 16,
// frame 0
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xF0, 0xC0, 0xF0, 0xD0, 0xF8, 0xD0, 0xF8, 0x50, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x30, 0xF8, 0x30, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xD8, 0xFC, 0x58, 0xFC, 0x2C, 0xFE, 0xEC, 0xFE, 0xEC, 0xFE, 0x8C, 0xFE, 
0x8C, 0xFE, 0xEC, 0xFE, 0xEC, 0xFE, 0x2C, 0xFE, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0x58, 0xFC, 0xD0, 0xF8, 0xD0, 0xF8, 0x10, 0xF8, 0x50, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x60, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0E, 0x0C, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x1B, 0x3F, 0x16, 0x3F, 0x15, 0x3F, 0x1D, 0x3F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0E, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0C, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x16, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x2F, 0x7F, 0x2C, 0x7F, 0x2D, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x1B, 0x3F, 0x0A, 0x1F, 0x09, 0x1F, 0x0F, 0x1F, 0x0E, 0x1F, 0x00, 0x1E, 0x00, 0x00, 
// frame 1
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xF0, 0xC0, 0xF0, 0xD0, 0xF8, 0xD0, 0xF8, 0x50, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x30, 0xF8, 0x30, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x18, 0xFC, 
0x18, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0x2C, 0xFE, 0xEC, 0xFE, 0xEC, 0xFE, 0xAC, 0xFE, 0xEC, 0xFE, 0xEC, 0xFE, 0x2C, 0xFE, 0x6C, 0xFE, 0xD8, 0xFC, 0xD8, 0xFC, 0x18, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0x50, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0E, 0x0C, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x1B, 0x3F, 0x16, 0x3F, 0x15, 0x3F, 0x1D, 0x3F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0E, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0D, 0x1F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2C, 0x7F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x17, 0x3F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0D, 0x1F, 0x05, 0x0F, 0x05, 0x0F, 0x06, 0x0F, 0x03, 0x07, 0x03, 0x07, 0x01, 0x03, 0x00, 0x03, 
// frame 2
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xF0, 0xC0, 0xF0, 0xD0, 0xF8, 0xD0, 0xF8, 0x50, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x30, 0xF8, 0x30, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x30, 0xF8, 
0x30, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0x58, 0xFC, 0xEC, 0xFE, 0xEC, 0xFE, 0x8C, 0xFE, 0xAC, 0xFE, 0xEC, 0xFE, 0x2C, 0xFE, 0x6C, 0xFE, 0xEC, 0xFE, 0x58, 0xFC, 0xD8, 0xFC, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xB0, 0xF8, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x80, 
0x00, 0x00, 0x00, 0x0E, 0x0C, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x1B, 0x3F, 0x16, 0x3F, 0x15, 0x3F, 0x1D, 0x3F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0E, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0C, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2C, 0x7F, 0x2C, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 
0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2C, 0x7F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0A, 0x1F, 0x0C, 0x1F, 0x07, 0x0F, 0x07, 0x0F, 0x03, 0x07, 0x00, 0x03, 
// frame 3
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xE0, 0xC0, 0xF0, 0xC0, 0xF0, 0xD0, 0xF8, 0xD0, 0xF8, 0x50, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x30, 0xF8, 0x30, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0xB0, 0xF8, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x18, 0xFC, 
0x18, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x18, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD8, 0xFC, 0x58, 0xFC, 0xD8, 0xFC, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0xC0, 0xE0, 0x80, 0xC0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0E, 0x0C, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x1B, 0x3F, 0x16, 0x3F, 0x15, 0x3F, 0x1D, 0x3F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0E, 0x1F, 0x0A, 0x1F, 0x06, 0x1F, 0x06, 0x1F, 0x09, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x2E, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2F, 0x7F, 0x2E, 0x7F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x16, 0x3F, 0x16, 0x3F, 0x15, 0x3F, 0x1B, 0x3F, 0x0E, 0x1F, 0x0C, 0x1E, 0x00, 0x1C, 0x00, 0x00, 
};

// Enemy Type variables
int8_t numEels = 0;
int8_t numJellys = 0;
byte jellyMax = 1;
byte eelMax = 1;

struct Enemies
{
  public:
    int16_t  x;
    int16_t y;
    byte width, height;
    int8_t xSpeed, ySpeed;

    byte burst;
    byte burstTimer;

    byte type;
    bool active;

    void resetPos();

};

void Enemies::resetPos()
{
  x = 12  * random(12, 14);
  //y = 10 * random(1, 6);

  if (type == ENEMY_JELLY)
    --numJellys;

  if (type == ENEMY_EEL)
    --numEels;

  active = false;
}

Enemies enemyFish[MAX_ENEMIES];

void createEnemy(byte type, byte y)
{
  if (type == ENEMY_JELLY && numJellys >= jellyMax)
    return;
  if (type == ENEMY_EEL && numEels >= eelMax)
    return;
    
  for (byte i = 0; i < MAX_ENEMIES; i++)
  {
    if (enemyFish[i].active == false)
    {
      enemyFish[i].active = true;
      enemyFish[i].type = type;
      enemyFish[i].xSpeed = -3;
      enemyFish[i].ySpeed = 0;
      enemyFish[i].width = 16;
      enemyFish[i].height = 14;
      enemyFish[i].y = y;

      if (type == ENEMY_JELLY)
      {
        enemyFish[i].ySpeed = -2;
        enemyFish[i].height = 20;
        numJellys++;
      }
      if (type == ENEMY_EEL)
      {
        enemyFish[i].xSpeed = -2;
        enemyFish[i].width = 80;
        enemyFish[i].height = 10;
        numEels++;
      }

      return;
    }
  }
}

void updateEnemies()
{
  if (getPowerup(PU_STOPFISH))  // enemies paused
    return;
    
  for (byte i = 0; i < MAX_ENEMIES; i++)
  {
    if (enemyFish[i].active)
    {
      switch (enemyFish[i].type)
      {
        case ENEMY_BAD:
          // ----- Bad Fishy -----
          // Bursts forward, with pause
          if (enemyFish[i].burst > 0)
          {
            // Move while bursting
            enemyFish[i].x +=  enemyFish[i].xSpeed;
            --enemyFish[i].burst;
          }
          else
          {
            // Decrement time before next burst
            --enemyFish[i].burstTimer;
            if (enemyFish[i].burstTimer == 0)
            {
              // Timer up, reset burst and burstTimer
              enemyFish[i].burstTimer = BURST_WAIT;
              enemyFish[i].burst = BURST_LENGTH;
            }
          }
          break;
          
        case ENEMY_JELLY:
          // ----- Jelly Fish -----
          // Bursts upward
          // Moves faster horizontally when bursting
          if (enemyFish[i].burst > 0)
          {
            // Move up while bursting
            enemyFish[i].y +=  enemyFish[i].ySpeed;
            // Faster left movement when bursting
            enemyFish[i].x +=  enemyFish[i].xSpeed;

            if (enemyFish[i].y <= -4)
              enemyFish[i].burst = 1;

            --enemyFish[i].burst;
          }
          else
          {
            // Slower left movement not bursting
            enemyFish[i].x--;

            // Decrement time before next burst
            --enemyFish[i].burstTimer;

            // Drop y
            enemyFish[i].y -= enemyFish[i].ySpeed / 2;
            if (enemyFish[i].y > GAME_BOTTOM - (enemyFish[i].height / 2))
              enemyFish[i].burstTimer = 0;            // Reset timer when under screen

            if (enemyFish[i].burstTimer == 0)
            {
              // Timer up, reset burst and burstTimer
              enemyFish[i].burstTimer = random(10) + (BURST_WAIT / 2);
              enemyFish[i].burst = BURST_LENGTH / 2;
            }
          }
          break;
          
        case ENEMY_EEL:
          // ----- Eel -----
          // Steady left movement
          //if (enemyFish[i].type == ENEMY_EEL)
            enemyFish[i].x +=  enemyFish[i].xSpeed;

          break;

        case ENEMY_STAR:
          if (getPowerup(PU_MAGNETFISH))
          {
            if (arduboy.everyXFrames(3))
            {
              if (enemyFish[i].y < trollyFish.y) enemyFish[i].y++;
              if (enemyFish[i].y > trollyFish.y) enemyFish[i].y--;
            }
          }
      
          enemyFish[i].x -= 4;
          break;

        case ENEMY_BUBBLE:
            enemyFish[i].y--;
            if (enemyFish[i].y < 1) enemyFish[i].resetPos();
            break;
      }

      // Outside of room, deactivate
      if ( enemyFish[i].x < (GAME_LEFT - enemyFish[i].width))  enemyFish[i].resetPos();
    }
  }
}

void drawEnemies()
{
  if (arduboy.everyXFrames(6)) fishFrame++;
  if (fishFrame > 3 || getPowerup(PU_STOPFISH)) fishFrame = 0;
  for (byte i = 0; i < MAX_ENEMIES; i++)
  {
    switch (enemyFish[i].type)
    {
      case ENEMY_BAD:
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 1, badFishy_plus_mask, (fishFrame * (min(enemyFish[i].burst, 1))));
      break;
      
      case ENEMY_JELLY:
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 4, jellyFish_plus_mask, (fishFrame * (min(enemyFish[i].burst, 1))));
      break;
      
      case ENEMY_EEL:
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 3, eel_plus_mask, fishFrame);
      break;

      case ENEMY_STAR:
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 1, starFish_plus_mask, 0);
      break;

      case ENEMY_BUBBLE:
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y, bubbles_plus_mask, enemyFish[i].y % 13);
      break;
    }
  }
}


#endif
