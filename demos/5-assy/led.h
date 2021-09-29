#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

// variables are defined elsewhere
extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init(void);
void led_update(void);
void greenOn(int on);


#endif // included
