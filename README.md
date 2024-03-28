Test program for the WS2812D LEDs found here:
https://www.aliexpress.us/item/3256805685141537.html

Be careful with the pinout.  VCC & GND are reversed compared to other datasheets you may find online.  The pinout in the above listing is correct.

This code should work for any WS2812 LEDs, although it may require a change to the line in setup().