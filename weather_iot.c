#include <stdio.h>
#include <wiringPi.h>
#include <mcp3004.h>

// dc motor
#define EN 25
#define OUT1 24
#define OUT2 23

// servo motor
#define SERVO 21

// light, water
#define BASE 100
#define SPI_CHAN 0

// LED
#define LED 0

int main(void) {
	if(wiringPiSetup() == -1) {
		return -1;
	}
	mcp3004Setup(BASE, SPI_CHAN);

	pinMode(EN, OUTPUT);
	pinMode(OUT1, OUTPUT);
	pinMode(OUT2, OUTPUT);

	softPwmCreate(SERVO, 0, 200);

	pinMode(LED, OUTPUT);

	int xc = 0;
	int yc = 0;

	while(1) {
		int y = analogRead(BASE); //water
		int x = analogRead(BASE + 1); //light

		delay(100);
		printf("light : %d\n", x);
		delay(100);
		printf("water : %d\n", y);
		delay(100);
		if(y > 50) {
			if(digitalRead(LED) == 1) {
				digitalWrite(LED, 0);
			}
			yc++;
			if(yc >= 4) {
			softPwmWrite(SERVO, 5); //-90도
			digitalWrite(OUT1, 0); //dc모터 끄기
			digitalWrite(OUT2, 0);
			yc = 0;
			}

		}

		else if( x !=  0) {
			xc++;
			if(xc > 4 ) {
				digitalWrite(OUT1, 0);//dc모터 끄기
				digitalWrite(OUT2, 0);
				digitalWrite(LED, 0); //led - trun on
				delay(100);
				digitalWrite(LED, 1);
				delay(100);
				xc = 0;
			}
		
		}
		else {
			if(digitalRead(LED) == 1) {
				digitalWrite(LED, 0);
			}
			xc++;
			if( xc >= 4) {
			softPwmWrite(SERVO, 25); //약 90도
			digitalWrite(OUT1, 1); //dc 모터 작동
			digitalWrite(OUT2, 0);
			xc = 0;
			}
		}

	}

	return 0;
}


