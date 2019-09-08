#include "dht11.h"
/*

Dht11::Dht11(Pin pin){
    self.pin = pin;
}

Dht11::Dht11(uint8_t pin)
{
    self.pin =  Pin(pin,INPUT_PULLUP);
}

Dht11::Dht11(dht11_t dht11)
{
    self = dht11;
}

uint8_t Dht11::getTemperature()
{

    return self.temperature;
}

uint8_t Dht11::getHumidity()
{
    return self.humidity;
}

void Dht11::getData()
{
				//Serial *serial1 = SerialManager::getInstance(SERIAL1);
    uint8_t buffer[5] = {0, 0, 0, 0, 0};
    uint8_t retries = 0;
    uint32_t prev, now;
    if(!startContition()){
        //serial1->printf("Start failed\r\n");
        _delay_ms(2000);
        return;
    }
    self.pin.setDirection(INPUT_PULLUP);

    //serial1->printf("Reading\r\n");
    //Reading 5 bytes, bit by bit
    for (int i = 0; i < 5; ++i)
    {
        for(int j = 7; j >= 0; --j)
        {
            retries = 0;
            prev = Timer::now();
												// First there is always a 50µs low period
            while(!self.pin.digitalRead())
            {
                //_delay_us(2);
                //retries+=2;
                now = Timer::now() - prev;
                if (now - prev >= 90){
																			// serial1->dbg("Alluppatoo LOW\r\n");
                    return;
                }
            }

            retries = 0;

												// Then the data signal is sent. 26 to 28µs (ideally)
												//    indicate a low bit, and around 70µs a high bit
            prev = Timer::now();
            while(self.pin.digitalRead()){
                //_delay_us(2);
                //retries+=2;
                now = Timer::now() - prev;
                if (now >= 90){
																				//serial1->dbg("Alluppatoo\r\n");
                    return;
                }
            }
												//serial1->dbg("T high %d\r\n",now);
												// Store the value now so that the whole checking doesn't
												//    move the TCNT0 forward by too much to make the data look
												//    bad

            if (now >= 20 && retries <= now){
                bitClear(buffer[i],j);
            }

            else if (now >= 60 && now <= 80){
                buffer[i] |= (1<<j);
            }

        }
								//serial1->dbg("%d\r\n",buffer[i]);
    }




    self.humidity = buffer[0];
    self.humidity_float = buffer[1];
    self.temperature = buffer[2];
    self.temperature_float = buffer[3];
    self.crc = buffer[4];




}

bool Dht11::startContition()
{
    self.pin.setDirection(INPUT_PULLUP);
    //Serial *serial1 = SerialManager::getInstance(SERIAL1);
    uint8_t retries = 0;

    self.pin.off();
    self.pin.setDirection(OUTPUT);
    _delay_ms(20);
    //Setup DHT_PIN as input with pull-up resistor so as to read data
    //self.pin.on();
    self.pin.setDirection(INPUT_PULLUP);

    while (self.pin.digitalRead()){
        _delay_us(2);
        retries +=2;
        if (retries > 40 ){
            // serial1->printf("error 40\r\n");
            return false;
        }
    };

    retries = 0;
    while (!self.pin.digitalRead()){
        _delay_us(2);
        retries +=2;
        if (retries > 90){
            //serial1->printf("error 80 low\r\n");
            return false;
        }
    }


    //Wait for the last response to finish (high for ~80us)
    retries = 0;
    while (self.pin.digitalRead()){
        _delay_us(2);
        retries +=2;
        if (retries > 90){
            //serial1->printf("error 80 high\r\n");
            return false;
        }
    }


    return true;
}

bool Dht11::checkCrc()
{
    uint8_t check = (self.humidity+self.humidity_float+
                     self.temperature+self.temperature_float ) & 0xFF;
    if(check == self.crc){
        return true;
    }
    return false;
}
*/


































