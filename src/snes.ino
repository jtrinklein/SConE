#include "pins.h"

#define FIXED_TIME 0
void initPins();

void sendButtons();
void setup() {
    initPins();
    disableTimers();
    noInterrupts();
}

#define readLatch() ((PINC & (1 << LATCH_BIT)) ? HIGH : LOW )
#define readClock() ((PINC & (1 << CLOCK_BIT)) ? HIGH : LOW )
#define sendButtonState(btns) PORTC = (PORTC & (~(1<<DATA_BIT))) | ((btns & 1) << DATA_BIT); btns = (btns >> 1)

#define waitForClockCycle()  while(readClock() == HIGH);while(readClock() == LOW)

void loop() {
    if(readLatch() != HIGH) {
        return;
    }

    // get digital pins 0-7
    unsigned int buttonsLow = PIND >> 2;
    unsigned int buttonsHigh = PINB & B00111111;
    // add digital pins 8-13 (plus 2 pins that are wired to crystal)
    // high pins are shifted so pin 8 is bit 8
    // shift down so first button (pin2) is bit 0


    // wait for latch to go low
    while( readLatch() == HIGH);

    // clock 1 - B
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 2 - Y
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 3 - Select
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 4 - Start
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 5 - Up
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 6 - Down
    sendButtonState(buttonsLow);
    waitForClockCycle();
    
    // clock 7 - Left
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 8 - Right
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 9 - A
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 10 - X
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 11 - L
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 12 - R
    sendButtonState(buttonsHigh);
    waitForClockCycle();
    
    // clock 13,14,15,16 - Unused, send not pressed
    PORTC |= (1<<DATA_BIT);
}

void initPins() {
    pinMode(LATCH_PIN, INPUT);
    pinMode(CLOCK_PIN, INPUT);
    pinMode(DATA_PIN, OUTPUT);
    digitalWrite(DATA_PIN, LOW);

    pinMode(BUTTON_B, INPUT);
    digitalWrite(BUTTON_B, HIGH);

    pinMode(BUTTON_A, INPUT);
    digitalWrite(BUTTON_A, HIGH);

    pinMode(BUTTON_X, INPUT);
    digitalWrite(BUTTON_X, HIGH);
    
    pinMode(BUTTON_Y, INPUT);
    digitalWrite(BUTTON_Y, HIGH);

    pinMode(BUTTON_R, INPUT);
    digitalWrite(BUTTON_R, HIGH);

    pinMode(BUTTON_L, INPUT);
    digitalWrite(BUTTON_L, HIGH);

    pinMode(BUTTON_START, INPUT);
    digitalWrite(BUTTON_START, HIGH);

    pinMode(BUTTON_SELECT, INPUT);
    digitalWrite(BUTTON_SELECT, HIGH);

    pinMode(PAD_LEFT, INPUT);
    digitalWrite(PAD_LEFT, HIGH);

    pinMode(PAD_RIGHT, INPUT);
    digitalWrite(PAD_RIGHT, HIGH);

    pinMode(PAD_UP, INPUT);
    digitalWrite(PAD_UP, HIGH);

    pinMode(PAD_DOWN, INPUT);
    digitalWrite(PAD_DOWN, HIGH);

}

void disableTimers() {
    TCCR0A = 0;
    TCCR0B = 0;
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR2A = 0;
    TCCR2B = 0;

}
