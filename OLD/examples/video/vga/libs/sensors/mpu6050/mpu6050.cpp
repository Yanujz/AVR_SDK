#include "mpu6050.h"

Mpu6050::Mpu6050(slave_t addr)
{
    self.addr = addr;
}

Mpu6050::Mpu6050(uint8_t writeAddr, uint8_t readAddr)
{
    self.addr.writeAddr = writeAddr;
    self.addr.readAddr = readAddr;
}

void Mpu6050::wakeUp()
{
    master.start(self.addr.writeAddr);
    master.send(MPU6050_PWR_MGMT_1); // PWR_MGMT_1 register
    master.send(0x00); // Setting 0 to wake up
    master.stop();
}

void Mpu6050::sleep()
{
    master.start(self.addr.writeAddr);
    master.send(MPU6050_PWR_MGMT_1);
    uint8_t data = master.receive(self.addr.readAddr);
    data |= (1<<PWR1_SLEEP_BIT);
    master.send(data);
    master.stop();
}

mpu6050_d Mpu6050::getRawData()
{
    uint8_t *ptr =  (uint8_t*)&self.data;

    master.start(self.addr.writeAddr);
    master.send(MPU6050_ACCEL_XOUT_H);
    master.start(self.addr.readAddr);

    ptr[1] = master.read_sendAck();
    ptr[0] = master.read_sendAck();
    ptr[3] = master.read_sendAck();
    ptr[2] = master.read_sendAck();
    ptr[5] = master.read_sendAck();
    ptr[4] = master.read_sendAck();
    ptr[7] = master.read_sendAck();
    ptr[6] = master.read_sendAck();
    ptr[9] = master.read_sendAck();
    ptr[8] = master.read_sendAck();
    ptr[11] = master.read_sendAck();
    ptr[10] = master.read_sendAck();
    ptr[13] = master.read_sendAck();
    ptr[12] = master.read_sendNack();

    return self.data;
}

mpu6050_f Mpu6050::getDataFixed(TEMP_UNITS unit)
{
    mpu6050_f dataFixed;
    getRawData();

    dataFixed.accelX =  self.data.accelX/16384.0;
    dataFixed.accelY =  self.data.accelY/16384.0;
    dataFixed.accelZ =  self.data.accelZ/16384.0;
    dataFixed.gyroX  =  self.data.gyroX*(4*9.8)/65535;
    dataFixed.gyroY  =  self.data.gyroY*(4*9.8)/65535;
    dataFixed.gyroZ  =  self.data.gyroZ*(4*9.8)/65535;
    float celsius    =  self.data.temp/340.00+36.53;
    switch (unit) {
    case CELSIUS_DEGREES:
        dataFixed.temp =  celsius;
        break;
    case FAHRENHEIT_DEGREES:
        dataFixed.temp = (1.80*celsius)+32;
        break;
    case KELVIN_DEGREES:
        dataFixed.temp = celsius + 273.15;
        break;
    }


    return dataFixed;

}

void Mpu6050::setAccelRange(ACCEL_RANGE range)
{
    self.settings.accelCfg = (range << AFS_SEL_BIT);

    master.start(self.addr.writeAddr);
    master.send(MPU6050_ACCEL_CONFIG);
    master.send(self.settings.accelCfg);
    master.stop();
}

ACCEL_RANGE Mpu6050::getAccelRange()
{
    return (ACCEL_RANGE)self.settings.accelCfg;
}

void Mpu6050::setGyroRange(GYRO_RANGE range)
{
    self.settings.gyroCfg = (range << FS_SEL_BIT);

    master.start(self.addr.writeAddr);
    master.send(MPU6050_GYRO_CONFIG);
    master.send(self.settings.gyroCfg);
    master.stop();
}

GYRO_RANGE Mpu6050::getGyroRange()
{
    return (GYRO_RANGE)self.settings.gyroCfg;
}
