#ifndef HMC5883_H
#define HMC5883_H
#include <math.h>
#include <i2cmaster.h>
#include <macros.h>
///@file

// Register List
/*
+------+-----------------------------+--------+
| Addr | Name                        | Access |
+------+-----------------------------+--------+
| 0x0  | Config Register A           | R/W    |
| 0x1  | Config Register B           | R/W    |
| 0x2  | Mode Register               | R/W    |
| 0x3  | Data Output X MSB Reg       | R      |
| 0x4  | Data Output X LSB Register  | R      |
| 0x5  | Data Output Z MSB Register  | R      |
| 0x6  | Data Output Z LSB Register  | R      |
| 0x7  | Data Output Y MSB Register  | R      |
| 0x8  | Data Output Y LSB Register  | R      |
| 0x9  | Status Register             | R      |
| 0xA  | Identification Register A   | R      |
| 0xB  | Identification Register B   | R      |
| 0xC  | Identification Register C   | R      |
+------+-----------------------------+--------+
*/
enum REGISTER: uint8_t{
    REG_A,
    REG_B,
    REG_MODE,
    OUT_X_MSB,
    OUT_X_LSB,
    OUT_Z_MSB,
    OUT_Z_LSB,
    OUT_Y_MSB,
    OUT_Y_LSB,
};


// Configuration Register A
/*
The configuration register is used to configure the device for setting the data
output rate and measurement configuration.

CRA0 through CRA7 indicate bit locations, with CRA denoting the bits that are in the
configuration register.

CRA7 denotes the first bit of the data stream. The number in parenthesis indicates the
default value of that bit.CRA default is 0x10.

+------+--------+--------+--------+--------+--------+--------+--------+
| CRA7 |  CRA6  |  CRA5  |  CRA4  |  CRA3  |  CRA2  |  CRA1  |  CRA0  |
+------+--------+--------+--------+--------+--------+--------+--------+
| (0)  | MA1(0) | MA0(0) | DO2(1) | DO2(1) | DO2(1) | MS1(0) | MS0(0) |
+------+--------+--------+--------+--------+--------+--------+--------+

+--------------+------------+------------------------------------------------------+
|   Location   |    Name    |                   Description                        |
+--------------+------------+------------------------------------------------------+
| CRA7         | CRA7       | Bit CRA7 is reserved for future function.            |
|              |            | Set to 0 when configuring CRA.                       |
+--------------+------------+------------------------------------------------------+
| CRA6 to CRA5 | MA1 to MA0 | Select number of samples averaged (1 to 8) per       |
|              |            | measurement output.                                  |
|              |            | 00 = 1(Default); 01 = 2; 10 = 4; 11 = 8              |
+--------------+------------+------------------------------------------------------+
| CRA4 to CRA2 | DO2 to DO0 | Data Output Rate Bits.                               |
|              |            | These bits set the rate at which data                |
|              |            | is written to all three data output registers.       |
+--------------+------------+------------------------------------------------------+
| CRA1 to CRA0 | MS1 to MS0 | Measurement Configuration Bits.                      |
|              |            | These bits define themeasurement flow of the device, |
|              |            | specifically whether or not to incorporate           |
|              |            | an applied bias into the measurement.                |
|              |            |                                                      |
|              |            |                                                      |
+--------------+------------+------------------------------------------------------+

+-----+-----+-----+------------------+
| DO2 | DO1 | DO0 | Output Rate (Hz) |
+-----+-----+-----+------------------+
| 0   | 0   | 0   | 0.75             |
| 0   | 0   | 1   | 1.5              |
| 0   | 1   | 0   | 3                |
| 0   | 1   | 1   | 7.5              |
| 1   | 0   | 0   | 15               |
| 1   | 0   | 1   | 30               |
| 1   | 1   | 0   | 75               |
+-----+-----+-----+------------------+

+-----+-----+------------------------------------------------------------+
| MS1 | MS0 | Measurament Mode                                           |
+-----+-----+------------------------------------------------------------+
| 0   | 0   | Normal measurement configuration (Default).                |
|     |     | In normal measurement configuration the device             |
|     |     | follows normal measurement flow.                           |
|     |     | The positive and negative pins of the                      |
|     |     | resistive load are left floating and high impedance.       |
+-----+-----+------------------------------------------------------------+
| 0   | 1   | Positive bias configuration for X, Y, and Z axes.          |
|     |     | In this configuration, a positive current is forced across |
|     |     | the resistive load for all three axes.                     |
+-----+-----+------------------------------------------------------------+
| 1   | 1   | Negative bias configuration for X, Y and Z axes.           |
|     |     | In this configuration, a negative current is forced        |
|     |     | across the resistive load for all three axes.              |
+-----+-----+------------------------------------------------------------+
*/


enum SAMPLE_MEASURE : uint8_t{
    AVG_1,
    AVG_2,
    AVG_4,
    AVG_8,
};

enum OUTPUT_RATE : uint8_t{
    RATE_0_75Hz,
    RATE_1_5Hz,
    RATE_3Hz,
    RATE_7_5Hz,
    RATE_15Hz,
    RATE_30Hz,
    RATE_75Hz,
};

enum MEASURE_MODE:uint8_t{
    DEF_BIAS,
    POS_BIAS,
    NEG_BIAS,
};


// Configuration Register B
/*
The configuration register B for setting the device gain.

CRB0 through CRB7 indicate bit locations, with CRB denoting the bits that are in the
configuration register.

CRB7 denotes the first bit of the data stream. The number in parenthesis
indicates the default value of that bit. CRB default is 0x20.

+--------+--------+--------+------+------+------+------+------+
| CRB7   | CRB6   | CRB5   | CRB4 | CRB3 | CRB2 | CRB1 | CRB0 |
+--------+--------+--------+------+------+------+------+------+
| GN2(0) | GN1(0) | GN0(1) | (0)  | (0)  | (0)  | (0)  | (0)  |
+--------+--------+--------+------+------+------+------+------+

+--------------+------------+------------------------------------------------------+
| Location     | Name       | Description                                          |
+--------------+------------+------------------------------------------------------+
| CRB7 to CRB5 | GN2 to GN0 | Gain Configuration Bits.                             |
|              |            | These bits configure the gain for                    |
|              |            | the device. The gain configuration is common for all |
|              |            | channels.                                            |
+--------------+------------+------------------------------------------------------+
| CRB4 to CRB0 | 0          | These bits must be cleared for correct operation.    |
+--------------+------------+------------------------------------------------------+

+-----+-----+-----+-------------+-------------+-------------+----------------+
| GN2 | GN1 | GN0 | Field Range |     Gain    | Resolution  | Output Range   |
|     |     |     |             | (LSb/Gauss) |  (mG/LSb)   |                |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 0   | 0   | 0   | ±0.88 Ga    |    1370     |     0.73    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 0   | 0   | 1   | ±1.30 Ga    |    1090     |     0.92    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 0   | 1   | 0   | ±1.9 Ga     |     820     |     1.22    | 0xF800–0x07FFF |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 0   | 1   | 1   | ±2.5 Ga     |     660     |     1.52    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 1   | 0   | 0   | ±4.0 Ga     |     440     |     2.27    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 1   | 0   | 1   | ±4.7 Ga     |     390     |     2.56    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 1   | 1   | 0   | ±5.6 Ga     |     330     |     3.03    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+
| 1   | 1   | 1   | ±8.1 Ga     |     230     |     4.35    | 0xF800–0x07FF  |
|     |     |     |             |             |             | (-2048–2047 )  |
+-----+-----+-----+-------------+-------------+-------------+----------------+



*/

enum GAIN:uint8_t{
    RANGE_0_88Ga,
    RANGE_1_30Ga,
    RANGE_1_90Ga,
    RANGE_2_50Ga,
    RANGE_4_00Ga,
    RANGE_4_70Ga,
    RANGE_5_60Ga,
    RANGE_8_10Ga,
};


// Mode Register

/*
The mode register is an 8-bit register from which data can be read or to which data can
be written. This register is used to select the operating mode of the device.

MR0 through MR7 indicate bit locations, with MR denoting the bits that are in the
mode register.

MR7 denotes the first bit of the data stream. The number in parenthesis indicates the
default value of that bit. Mode register default is 0x01.

+-------+-----+-----+-----+-----+-----+--------+--------+
| MR7   | MR6 | MR5 | MR4 | MR3 | MR2 | MR1    | MR0    |
+-------+-----+-----+-----+-----+-----+--------+--------+
| HS(0) | (0) | (0) | (0) | (0) | (0) | MD1(0) | MD0(1) |
+-------+-----+-----+-----+-----+-----+--------+--------+

+------------+------------+-----------------------------------------------------------+
| Location   | Name       | Description                                               |
+------------+------------+-----------------------------------------------------------+
| MR7 to MR2 | HS         | Set this pin to enable High Speed I2C, 3400kHz.           |
+------------+------------+-----------------------------------------------------------+
| MR1 to MR0 | MD1 to MD0 | Mode Select Bits. These bits select the operation mode of |
|            |            | this device.                                              |
+------------+------------+-----------------------------------------------------------+


+-----+-----+-------------------------------------------------------------------------+
| MD1 | MD0 | Operating Mode                                                          |
+-----+-----+-------------------------------------------------------------------------+
| 0   | 0   | Continuous-Measurement Mode. In continuous-measurement mode,            |
|     |     | the device continuously performs measurements and places the            |
|     |     | result in the data register. RDY goes high when new data is placed      |
|     |     | in all three registers. After a power-on or a write to the mode or      |
|     |     | configuration register, the first measurement set is available from all |
|     |     | three data output registers after a period of 2/fDO and subsequent      |
|     |     | measurements are available at a frequency of fDO, where fDO is the      |
|     |     | frequency of data output.                                               |
+-----+-----+-------------------------------------------------------------------------+
| 0   | 1   | Single-Measurement Mode (Default). When single-measurement              |
|     |     | mode is selected, device performs a single measurement, sets RDY        |
|     |     | high and returned to idle mode. Mode register returns to idle mode      |
|     |     | bit values. The measurement remains in the data output register and     |
|     |     | RDY remains high until the data output register is read or another      |
|     |     | measurement is performed.                                               |
+-----+-----+-------------------------------------------------------------------------+
| 1   | 0   | Idle Mode. Device is placed in idle mode.                               |
+-----+-----+-------------------------------------------------------------------------+
| 1   | 1   | Idle Mode. Device is placed in idle mode.                               |
+-----+-----+-------------------------------------------------------------------------+
*/

enum OP_MODE{
    CONTINUOUS_MODE,
    SINGLE_MODE,
    IDLE_MODE
};



struct compass_t
{
    int16_t raw_x;
    int16_t raw_y;
    int16_t raw_z;
    float headingDegrees;
};

class Hmc5883
{





public:
    Hmc5883(uint8_t writeAddr = 0x3c, uint8_t readAddr = 0x3d);
    void init();
    compass_t getData();

    void setSample(SAMPLE_MEASURE sample);
    SAMPLE_MEASURE getSample();

    void setOutRate();
    OUTPUT_RATE getOutRate();

    void setGain();
    GAIN getGain();

    void setOpMode();
    OP_MODE getOpMode();

    void setMeasureMode();
    MEASURE_MODE getMeasureMode();


private:
    //-------- METHODS --------//
    void getHeading();

    //-------- VARIABLES --------//
   // hmc5883_t ;
    I2CMaster master;
    compass_t compass;

    struct hmc5883_t
    {
        hmc5883_t(slave_t addr = 0, SAMPLE_MEASURE sample = AVG_1,
                  OUTPUT_RATE outRate = RATE_15Hz, GAIN gain = RANGE_1_30Ga,
                  OP_MODE opMode = CONTINUOUS_MODE,
                  MEASURE_MODE measureMode = DEF_BIAS){
            _addr        = addr       ;
            _sample      = sample     ;
            _outRate     = outRate    ;
            _gain        = gain       ;
            _opMode      = opMode     ;
            _measureMode = measureMode;
        }
        slave_t         _addr;
        SAMPLE_MEASURE  _sample;
        OUTPUT_RATE     _outRate;
        GAIN            _gain;
        OP_MODE         _opMode;
        MEASURE_MODE    _measureMode;
    }self;
};

#endif
