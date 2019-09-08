#ifndef MPU6050_H
#define MPU6050_H
#include "i2cmaster.h"
#include "macros.h"
///@file

/* Register GYRO_CONFIG 0x1B

Description:
    This register is used to trigger gyroscope self-test and configure
    the gyroscopes’ full scale range.

    Gyroscope self-test permits users to test the mechanical and electrical
    portions of the gyroscope.

    The self-test for each gyroscope axis can be activated by controlling
    the XG_ST,YG_ST, and ZG_ST bits of this register.

    Self-test for each axis may be performed independently or all at the same time.

+-------+-------+-------+---------+---------+---+---+---+
|   7   |   6   |   5   |    4    |    3    | 2 | 1 | 0 |
+-------+-------+-------+---------+---------+---+---+---+
| XG_ST | YG_ST | ZG_ST |   FS_SEL[1:0]     | - | - | - |
+-------+-------+-------+-------------------+---+---+---+


+--------+-------------+
| FS_SEL | Scale Range |
+--------+-------------+
|      0 | ± 250 °/s   |
|      1 | ± 500 °/s   |
|      2 | ± 1000 °/s  |
|      3 | ± 2000 °/s  |
+--------+-------------+

Parameters:
XG_ST:
    Setting this bit causes the X axis gyroscope to perform self test.
YG_ST:
    Setting this bit causes the Y axis gyroscope to perform self test.
ZG_ST:
    Setting this bit causes the Z axis gyroscope to perform self test.
FS_SEL:
    2-bit unsigned value. Selects the full scale range of gyroscopes.
*/

#define FS_SEL_BIT 3

enum GYRO_RANGE: uint8_t{
    MPU6050_GYRO_FS_250,
    MPU6050_GYRO_FS_500,
    MPU6050_GYRO_FS_1000,
    MPU6050_GYRO_FS_2000
};

/* Register ACCEL_CONFIG 0x1C

Description:
    This register is used to trigger accelerometer self test and configure
    the accelerometer full scale range.

    This register also configures the Digital High Pass Filter (DHPF).

+-------+-------+-------+---------+---------+---+---+---+
|   7   |   6   |   5   |    4    |    3    | 2 | 1 | 0 |
+-------+-------+-------+---------+---------+---+---+---+
| XA_ST | YA_ST | ZA_ST |   AFS_SEL[1:0]    | - | - | - |
+-------+-------+-------+-------------------+---+---+---+


+---------+-------------+
| AFS_SEL | Scale Range |
+---------+-------------+
|      0  | ± 2g        |
|      1  | ± 4g        |
|      2  | ± 8g        |
|      3  | ± 16g       |
+---------+-------------+

Parameters:

XA_ST:
    When set to 1, the X- Axis accelerometer performs self test.
YA_ST:
    When set to 1, the Y- Axis accelerometer performs self test.
ZA_ST:
    When set to 1, the Z- Axis accelerometer performs self test.
AFS_SEL:
    2-bit unsigned value. Selects the full scale range of accelerometers.
*/

#define AFS_SEL_BIT 3

enum ACCEL_RANGE: uint8_t{
    MPU6050_RANGE_2G,
    MPU6050_RANGE_4G,
    MPU6050_RANGE_8G,
    MPU6050_RANGE_16G
};

/* Register PWR_MGMT_1 0x6B

Description:
    This register allows the user to configure the power mode and clock source.
    It also provides a bit for resetting the entire device, and a bit for disabling
    the temperature sensor.

    By setting SLEEP to 1, the MPU-60X0 can be put into low power sleep mode.

    When CYCLE is set to 1 while SLEEP is disabled, the MPU-60X0
    will be put into Cycle Mode.

    In Cycle Mode, the device cycles between sleep mode and waking up to take
    a single sample of data from accelerometer at a rate determined by LP_WAKE_CTRL.

    To configure the wake frequency, use LP_WAKE_CTRL within the Power Management 2
    register (Register 108).

+--------------+-------+-------+------+----------+--------+--------+--------+
|     Bit7     | Bit6  | Bit5  | Bit4 |   Bit3   |  Bit2  |  Bit1  |  Bit0  |
+--------------+-------+-------+------+----------+--------+--------+--------+
| DEVICE_RESET | SLEEP | CYCLE |  -   | TEMP_DIS |       CLKSEL[2:0]        |
+--------------+-------+-------+------+----------+------------+------+------+


+--------+------------------------------------------------+
| CLKSEL |                  Clock Source                  |
+--------+------------------------------------------------+
|      0 | Internal 8MHz oscillator                       |
|      1 | PLL with X axis gyroscope reference            |
|      2 | PLL with Y axis gyroscope reference            |
|      3 | PLL with Z axis gyroscope reference            |
|      4 | PLL with external 32.768kHz reference          |
|      5 | PLL with external 19.2MHz reference            |
|      6 | Reserved                                       |
|      7 | Stops the clock and keeps the timing generator |
|        | in reset                                       |
+--------+------------------------------------------------+



Parameters:

DEVICE_RESET:
    When set to 1, this bit resets all internal registers to their default values.
    The bit automatically clears to 0 once the reset is done.
    The default values for each register can be found in Section 3.
SLEEP:
    When set to 1, this bit puts the MPU-60X0 into sleep mode.
CYCLE:
    When this bit is set to 1 and SLEEP is disabled, the MPU-60X0 will cycle
    between sleep mode and waking up to take a single sample of data from
    active sensors at a rate determined by LP_WAKE_CTRL (register 108).
TEMP_DIS:
    When set to 1, this bit disables the temperature sensor.
CLKSEL:
    3-bit unsigned value. Specifies the clock source of the device.
*/

#define PWR1_RESET_BIT 7
#define PWR1_SLEEP_BIT 6
#define PWR1_CYCLE_BIT 5
#define PWR1_TEMP_DIS_BIT 3

enum PWR1_CLK_SEL: uint8_t{
    MPU6050_CLOCK_INTERNAL_8MHZ,
    MPU6050_CLOCK_PLL_XGYRO,
    MPU6050_CLOCK_PLL_YGYRO,
    MPU6050_CLOCK_PLL_ZGYRO,
    MPU6050_CLOCK_EXTERNAL_32KHZ,
    MPU6050_CLOCK_EXTERNAL_19MHZ,
    MPU6050_RESERVED_NOT_USE,
    MPU6050_CLOCK_KEEP_RESET

};

/* Register PWR_MGMT_2 0x6C

Description:
    This register allows the user to configure the frequency of wake-ups
    in Accelerometer Only Low Power Mode.
    This register also allows the user to put individual axes of the accelerometer
    and gyroscope into standby mode.

+--------------------+---------+---------+---------+---------+---------+---------+
|  Bit7  |   Bit6    |  Bit5   |   Bit4  |   Bit3  |   Bit2  |  Bit1   |   Bit0  |
+--------------------+---------+---------+---------+---------+---------+---------+
| LP_WAKE_CTRL[1:0]  | STBY_XA | STBY_YA | STBY_ZA | STBY_XG | STBY_YG | STBY_ZG |
+--------------------+---------+---------+---------+---------+---------+---------+

+--------------+-------------------+
| LP_WAKE_CTRL | Wake-up Frequency |
+--------------+-------------------+
|            0 | 1.25 Hz           |
|            1 | 5 Hz              |
|            2 | 20 Hz             |
|            3 | 40 Hz             |
+--------------+-------------------+

Parameters:

LP_WAKE_CTRL:
    2-bit unsigned value.
    Specifies the frequency of wake-ups during Accelerometer Only Low Power Mode.
STBY_XA:
    When set to 1, this bit puts the X axis accelerometer into standby mode.
STBY_YA:
    When set to 1, this bit puts the Y axis accelerometer into standby mode.
STBY_ZA:
    When set to 1, this bit puts the Z axis accelerometer into standby mode.
STBY_XG:
    When set to 1, this bit puts the X axis gyroscope into standby mode.
STBY_YG:
    When set to 1, this bit puts the Y axis gyroscope into standby mode.
STBY_ZG:
    When set to 1, this bit puts the Z axis gyroscope into standby mode.

*/

#define PWR2_LP_WAKE_CTRL_BIT 6
#define PWR2_STBY_XA_BIT 5
#define PWR2_STBY_YA_BIT 4
#define PWR2_STBY_ZA_BIT 3
#define PWR2_STBY_XG_BIT 2
#define PWR2_STBY_YG_BIT 1
#define PWR2_STBY_ZG_BIT 0

enum LP_WAKE_CTRL: uint8_t{
    MPU6050_WAKE_FREQ_1P25,
    MPU6050_WAKE_FREQ_5,
    MPU6050_WAKE_FREQ_20,
    MPU6050_WAKE_FREQ_40
};


// MPU6050 Registers

enum MPU_REG :uint8_t{
    MPU6050_GYRO_CONFIG  = 0x1B, MPU6050_ACCEL_CONFIG = 0x1C,
    MPU6050_ACCEL_XOUT_H = 0x3B, MPU6050_ACCEL_XOUT_L = 0x3C,
    MPU6050_ACCEL_YOUT_H = 0x3D, MPU6050_ACCEL_YOUT_L = 0x3E,
    MPU6050_ACCEL_ZOUT_H = 0x3F, MPU6050_ACCEL_ZOUT_L = 0x40,
    MPU6050_TEMP_OUT_H   = 0x41, MPU6050_TEMP_OUT_L   = 0x42,
    MPU6050_GYRO_XOUT_H  = 0x43, MPU6050_GYRO_XOUT_L  = 0x44,
    MPU6050_GYRO_YOUT_H  = 0x45, MPU6050_GYRO_YOUT_L  = 0x46,
    MPU6050_GYRO_ZOUT_H  = 0x47, MPU6050_GYRO_ZOUT_L  = 0x48,
    MPU6050_PWR_MGMT_1   = 0x6B, MPU6050_PWR_MGMT_2   = 0x6C,
};


enum TEMP_UNITS : uint8_t{
    CELSIUS_DEGREES,
    FAHRENHEIT_DEGREES,
    KELVIN_DEGREES
};

struct mpu6050_f
{
    mpu6050_f() {}
    float accelX;
    float accelY;
    float accelZ;
    float temp;
    float gyroX;
    float gyroY;
    float gyroZ;
};
struct mpu6050_d
{
    mpu6050_d(){
        accelX  = 0;
        accelY  = 0;
        accelZ  = 0;
        temp    = 0;
        gyroX   = 0;
        gyroY   = 0;
        gyroZ   = 0;
    }
    int16_t accelX, accelY, accelZ;
    int16_t temp;
    int16_t gyroX, gyroY, gyroZ;

};

struct mpu6050_s
{
    mpu6050_s(ACCEL_RANGE accel = MPU6050_RANGE_2G, GYRO_RANGE gyro = MPU6050_GYRO_FS_250) {
        accelCfg = accel;
        gyroCfg  = gyro;
    }
    uint8_t accelCfg;
    uint8_t gyroCfg;
};

struct mpu6050_t
{
    mpu6050_t(slave_t addr = slave_t()){
        if(addr.readAddr == 0){
            this->addr.writeAddr = 0xd0;
            this->addr.readAddr = 0xd1;
        }
        else {
            this->addr = addr;
        }
    }
    slave_t addr;
    mpu6050_d data;
    mpu6050_s settings;

};

class Mpu6050
{
public:
    Mpu6050(slave_t addr);
    Mpu6050(uint8_t writeAddr =  0xD0, uint8_t readAddr = 0xD1);

    void wakeUp();
    void sleep();


    mpu6050_d getRawData();
    mpu6050_f getDataFixed(TEMP_UNITS unit);


    void setAccelRange(ACCEL_RANGE range =  MPU6050_RANGE_2G);
    ACCEL_RANGE getAccelRange();

    void setGyroRange(GYRO_RANGE range = MPU6050_GYRO_FS_250);
    GYRO_RANGE getGyroRange();

private:
    I2CMaster master;
    mpu6050_t self;

};

#endif
