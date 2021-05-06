/*
	Ynvisible_Driver_4.2-1.0.0.h - Library for driving the Ynvisible display.
	Created by Philip Holgersson - Ynvisible
*/
#ifndef _YNV_ECD
#define _YNV_ECD

#include "Arduino.h"
#include "Wire.h"

class YNV_ECD
{
	public:
		YNV_ECD(char address, int number_of_segments);
		void set(bool next_state[]);
		void setNumber1x7(int digit);
		void setNumber2x7(int digit);
		void setBar(int digit);
		void refresh();
		void setCounterVoltage(float voltage);
		void setSwitchingTime(int time);
		void sendData(String data);
		void reset();
		void setSeqRedVoltage(float v);
		void setSeqRedTime(int t);
		void setSeqOxiVoltage(float v);
		void setSeqOxiTime(int t);
		void setParVoltage(float v);
		void setParSwitchTime(int t);
		void setSupplyVoltage(float v);
		void setDrivingMethod(char c);
		void setRefreshTime(int t);
		void setRefreshVoltage(float v);

	private: 
		char _address;
		int _number_of_segments;
};

#endif