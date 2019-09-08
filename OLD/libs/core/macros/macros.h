#ifndef MACROS_H
#define MACROS_H
#include <common_typedef.h>
///@file



#define SIZE_OF_ARRAY(x) sizeof(x)/sizeof(x[0])
template<size_t N, class T>
constexpr size_t sizeOfArray(T(&)[N]) { return N; }
#define ELEMENT_IN_ARRAY(x)  (*(&x + 1) - x)


#define MYUBRR(x) (F_CPU/16/(float)x-1)

//#define BAUD 9600
//#define MAX_SERIAL_BUFFER   256
//#define MAX_SPI_BUFFER      256


/**
		*@return Absolute value
		*/
#define ABS(N) ((N<0)?(-N):(N))
constexpr unsigned int toABS(int x){
	return ((x<0)?(-x):(x));
}


/**
		* @return LSB of 16 bit value
		*/
#define LO(x) (x & 0xFF)

/**
		* @return MSB of 16 bit value
		*/
#define HI(x) ((x >> 8) & 0xFF)

#define LO8(x) (x & 0xFF)
#define HI8(x) ((x >> 8) & 0xFF)

#define LO16(x) (x & 0xFFFF)
#define HI16(x) ((x >> 16) & 0xFFFF)

//-------- Casting types --------//
#define toU8(x) (static_cast<u8t> (x))
#define toU16(x) (static_cast<u16t>(x))
#define toU32(x) (static_cast<u32t>(x))
#define toU64(x) (static_cast<u64>(x))
#define toChar(x) (static_cast<char>(x))
#define toShort(x) (static_cast<short>(x))
#define toInt(x) (static_cast<int>(x))
#define toFloat(x) (static_cast<float>(x))
#define toDouble(x) (static_cast<double>(x))

#define toU8Ptr(x) (reinterpret_cast<u8t*> (x))
#define toU16Ptr(x) (reinterpret_cast<u16t*>(x))
#define toU32Ptr(x) (reinterpret_cast<u32t*>(x))
#define toU64Ptr(x) (reinterpret_cast<u64*>(x))
#define toCharPtr(x) (reinterpret_cast<char*>(x))
#define toShortPtr(x) (reinterpret_cast<short*>(x))
#define toIntPtr(x) (reinterpret_cast<int*>(x))
#define toFloatPtr(x) (reinterpret_cast<float*>(x))
#define toDoublePtr(x) (reinterpret_cast<double*>(x))


//-------- Bit Manipulation --------//
/**
		* @brief Checks if a bit in a var is set to 1
		* @param[in] var The variable to test
		* @param[in] bit The bit you want to test in var
		* @return If the bit is on, it return the corresponding bit value into var. If the bit if off it retuns 0
		*/
#define is_bit_on(var, bit) ((var)&(1<<(bit)))

/**
		* @brief Reads bit value in a var
		* @param[in] var The variable to read
		* @param[in] bit The bit you want to read
		* @return If bit is on 1, else 0
		*/
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

/**
		*@brief Sets a bit into a var
		* @param[in] value The input variable
		* @param[in] bit The bit you want to set
		*/
#define bitSet(value, bit) ((value) |= (1 << (bit)))

/**
		*@brief Clears a bit into a variable
		* @param[in] value The input variable
		* @param[in] bit The bit you want to clear
		*/
#define bitClear(value, bit) ((value) &= ~(1 << bit) )

/**
		*@brief Writes a bit value into a variable
		* @param[in] value The input variable
		* @param[in] bit The bit you want to write
		* @param[in] bitvalue The bit value you want to write
		*/
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

constexpr u16t toWord(u8t msb, u8t lsb){
	return (msb << 8) | lsb;
}
//constexpr u32t toDoubleWord(u8t msb_h, u8t msb_l, u8t lsb_h, u8t lsb_l){
//    return (msb_h << 24) | (msb_l << 16) | (lsb_h << 8) | lsb_l;
//}
#define regBitToValue(x) (1 << toU8(x))
//#define bitValue(x) (1 << x)
constexpr u8t bitValue(u8t x){
	return (1 << x);
}
constexpr u8t setBitValue(bool val, u8t reg){
	return val ? (1 << reg) : 0;
}

#define valueFromMask(var, mask) (var & mask)

#define loop_while_bit_is_clear(reg, bit) 	(while( !(reg & (1 << bit) )))
#define loop_while_bit_is_set(reg, bit) 	(while( (reg & (1 << bit) )))

//#define CALCULATE_PWM_TICKS(freq) (1.0/freq)/(1.0/F_CPU)
//#define CALCULATE_DUTY_16BIT(freq, duty) (CALCULATE_PWM_TICKS(freq)-(CALCULATE_PWM_TICKS(freq)*((float)duty/100)))
//#define CALCULATE_DUTY_8BIT(duty) ((-2.55*duty) + 255)

constexpr u16t calcPwmTicks(size_t freq){
	return F_CPU/freq;
}
constexpr u16t calcDuty16bit(u16t ticks, u8t duty){
	return toU32(ticks) - ( (toU32(ticks) * toU32(duty))/100);
}
constexpr u8t calcDuty8bit(u8t duty){
	return  (25500-(255*duty))/100;
}





//---- SPI MACROS ----//

#endif
