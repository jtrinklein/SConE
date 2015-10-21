SConE
=====

[![Join the chat at https://gitter.im/jtrinklein/SConE](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/jtrinklein/SConE?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

**S**NES **Con**troller **E**mulator using Arduino (Uno)

## Overview

This is a basic SNES controller emulator written for the Arduino Uno.

I got the timing data from this [Pinouts & Protocol FAQ](http://www.gamefaqs.com/snes/916396-super-nintendo/faqs/5395) on gamefaqs.com. I've extracted some of the important details to [snes-flow.md](snes-flow.md).

## Pin Assignments

| Pin | Purpose       | Pin Mode      |
|-----|---------------|---------------|
| A0  | Data Latch    | INPUT         |
| A1  | Data Clock    | INPUT         |
| A2  | Serial Data   | OUTPUT        |
|  2  | Button B      | INPUT Pull-Up |
|  3  | Button Y      | INPUT Pull-Up |
|  4  | Button Select | INPUT Pull-Up |
|  5  | Button Start  | INPUT Pull-Up |
|  6  | Pad UP        | INPUT Pull-Up |
|  7  | Pad Down      | INPUT Pull-Up |
|  8  | Pad Left      | INPUT Pull-Up |
|  9  | Pad Right     | INPUT Pull-Up |
| 10  | Button A      | INPUT Pull-Up |
| 11  | Button X      | INPUT Pull-Up |
| 12  | Button L      | INPUT Pull-Up |
| 13  | Button R      | INPUT Pull-Up |

## Building

I'm using [platformio](http://platformio.org/) to build and deploy the code simply so I didn't have to use the Arduino IDE. Instructions for how to install and set it up can be found on their site. [platformio.ini](platformio.ini) contains the configuration for platformio.

## Reading Buttons

When reading buttons, keep in mind that if a pin is HIGH, the button is not pressed. When a pin reads LOW, the pin is pressed.

## Future Plans

I'm also planning to provide data over USB using the [UnoJoy](https://github.com/AlanChatham/UnoJoy) project, which is where the files in UnoJoy/ come from. 

This will depend on 2 things:

- how much time is left after SNES protocol
- how much time the UnoJoy serial write takes

