// servo.hpp

#ifndef SERVO
#define SERVO

#include "pca9685.hpp"

#include <iostream>
#include <wiringPi.h>

#define PIN_BASE 300
#define MAX_PWM 4096
#define HERTZ 50

class virServo {
public:
	int pin;
	float killSig = 1.55;
	int rotationTimeCW;
	int rotationTimeCCW;
	float CCWStop;
	float CWStop;

    virServo(int boardPin) {
		pin = boardPin;
		rotationTimeCW = 150;
		rotationTimeCCW = 150;
		CCWStop = 1.5;
		CWStop = 1.6;
    }

    void rotate(int speed, int times, bool CW) {
		float CWPulse;
		float CCWPulse;
		
		CWPulse = killSig + 0.9;
		CCWPulse = killSig - 0.8;
		
		float pulse;
		if (CW == 1) {
		    pulse = CWPulse;
		    int tick = calcTicks(pulse, HERTZ);
			pwmWrite(PIN_BASE + pin, tick);
			delay(rotationTimeCW*times);
			stopServo(CW);
		} else if (CW == 0) {
			pulse = CCWPulse;
			int tick = calcTicks(pulse, HERTZ);
			pwmWrite(PIN_BASE + pin, tick);
			delay(rotationTimeCCW*times);
			stopServo(CW);
		}
		
		delay(500);
		killServo();
		delay(50);
    }
    
private:
	int calcTicks(float impulseMs, int hertz) {
		float cycleMs = 1000.0f / hertz;
		return (int)(MAX_PWM * impulseMs / cycleMs + 0.5f);
	}
	
	float map(float input, float min, float max) {
		return (input * max) + (1 - input) * min;
	}

	void stopServo(bool CW) {
		if (CW) {
			int stopTick = calcTicks(CWStop,HERTZ);
			pwmWrite(PIN_BASE + pin, stopTick);
		} else {
			int stopTick = calcTicks(CCWStop,HERTZ);
			pwmWrite(PIN_BASE + pin, stopTick);			
		}
	}
	
	void killServo() {
		int stopTick = calcTicks(killSig,HERTZ);
		pwmWrite(PIN_BASE + pin, stopTick);	
	}
	
};

#endif
