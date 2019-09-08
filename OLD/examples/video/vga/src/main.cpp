#include "avr_sdk.h"
#include <avr/io.h>
#include <time.h>
enum colors{
	black = 8,
	red = 1,
	green = 2,
	blue = 4,
	yellow = red | green,
	magenta = red | blue,
	cyan = blue | green,
	white = red | green | blue,
};

#define NOP asm volatile("nop")
//#define RED 1
void vgaInit(){






	//TIMER3 hSync pin 2 0C3B
	TCCR3A |= (1 << COM4A1) | (1 << COM4A0) | (1 << COM4B1) | (0 << COM4B0) |
			(0 << COM4B1) | (0 << COM4B0) |		(1 << WGM11) | (0 << WGM10);
	TCCR3B |= (1 << WGM33) | (1 << WGM32) | (0<<CS30);
	TIMSK3 |= (0 << OCIE3A) | (1 << OCIE3B) | (0 << OCIE3C);
	ICR3 = 503; // 503
	OCR3A = 250; // 350
	OCR3B = 60; // 439
	OCR3C = 1;



	TCCR4A |= (0 << COM4A1) | (0 << COM4A0);
	TCCR4A |=	(0 << COM4B1) | (0 << COM4B0);
	TCCR4A |= (0 << COM4C1) | (0 << COM4C0);

	TCCR4A |= (0 << WGM11) | (0 << WGM10);
	TCCR4B |= (0 << WGM43) | (0 << WGM42) | (1<<CS40);

	TIMSK4 |= (0<<TOIE4) | (0 <<OCIE4A) | (0<<OCIE4B) | (0<<OCIE4C) ;
	ICR4 = 0; // 1067
	OCR4A = 0;// ICR4-5;
	OCR4B = 0;// ICR4-5;
	OCR4C = 0;// ICR4-5;

	//TCCR4A = 0;
	//TCCR4B = 0;
	//TIMSK4 = 0;
	//ICR4		 = 0;
	//OCR4A  = 0;
	//OCR4B  = 0;
	//OCR4C  = 0;

	// experiment

	//	TCCR2A = 0;// set entire TCCR2A register to 0
	//	TCCR2B = 0;// same for TCCR2B
	//	TCNT2 = 0;//initialize counter value to 0

	//	OCR2A = 250;
	//	OCR2B = 100;


	//	TCCR2A |= (1 << WGM21);
	//	TCCR2B |= (0 << CS22)  | (0 << CS21) | (0 << CS20);
	//	TIMSK2 |= (0 << TOIE2) | (0 << OCIE2A) | (0 << OCIE2B);




	//*/
	TCCR5A |= (1 << COM5A1) | (0 << COM5A0) | (1 << WGM11) | (0 << WGM10);
	TCCR5B = (1 << WGM43) | (1 << WGM42) |(0<<CS42)|(0<<CS41) | (0<<CS40);
	TIMSK5 |= (0 << OCIE5A);
	ICR5 = 221; //50Hz = 312; 60Hz = 258; 70Hz = 221; 85 Hz = 181
	OCR5A = 0;


}

//uint16_t r = 107,g = 0, b = 0, freq = ICR4, hSync = 503, vSync = 312;
/*
void handleCommand(){
	serial0->clear();
	char tmp = serial0->receive();

	switch (tmp) {
	case 'q':
		r++;
		//if(r > ICR4){
		//	r = 0;
		//}

		break;
	case 'w':
		--r;
		if(r > ICR4){
			r = 0;
		}
		break;

	case 'a':
		g++;
		if(g > ICR4){
			g = 0;
		}

		break;
	case 's':
		--g;
		if(g > ICR4){
			g= 0;
		}
		break;



	case 'z':
		b++;
		if(b > ICR4){
			b = 0;
		}

		break;
	case 'x':
		--b;
		if(b > ICR4){
			b = 0;
		}
		break;

	case 'k':
		freq++;
		break;
	case 'l':
		freq--;
		break;

	case 'i':
		hSync++;
		break;
	case 'o':
		hSync--;
		break;

	case 'm':
		vSync++;
		break;
	case ',':
		vSync--;
		break;

	default:
		break;
	}

	ICR4 = freq;
	OCR4A = ICR4/2;
	OCR4B = ICR4/2;// ICR4-5;
	OCR4C = ICR4/2;// ICR4-5;
	ICR3 = hSync;
	OCR3B = ICR3-3;
	ICR5 = vSync;
	serial0->printf("vSync : %.03f Hz\r\n",1.0/(ICR5*0.000064));
	serial0->printf("hSync : %.03f Hz\r\n",1.0/(ICR3*0.0000000625));
	serial0->printf("Pixel : %.03f Hz\r\n",1.0/(ICR4*0.0000000625));
	//serial0->printf("Duty Red %u\r\n",);

	serial0->printf("OCR4A : %d OCR4B : %d OCR4C : %u ICR4 : %u ICR3 : %u\r\n",OCR4A,OCR4B,OCR4C,ICR4,ICR3);
	//nICR4 =a;
	//nOCR4A = ICR4-(rand() % 5);
	//nOCR4B = ICR4-(rand() % 5);
	//nOCR4C = ICR4-(rand() % 5);
}

*/


#define MAX_WIDTH 120
#define MAX_HEIGHT 60

uint8_t vect[MAX_HEIGHT][MAX_WIDTH];


void setBuf(){
	//		uint8_t i = 0;
	//		while (i < MAX_WIDTH ) {
	//			vect[0][i]		= red;
	//			++i;
	//		}
	//		i = 0;
	//		while (i < MAX_WIDTH ) {
	//			vect[1][i]		= red;
	//		++i;
	//		}

	//	i = 0;
	//		while (i < MAX_WIDTH ) {
	//			vect[2][i]		= green;
	//		++i;
	//		}
	//		i = 0;
	//		while (i < MAX_WIDTH ) {
	//			vect[3][i]		= green;
	//			++i;
	//}

	for(uint8_t row = 0; row < MAX_HEIGHT; ++row ){
		for(uint8_t col = 0; col <	MAX_WIDTH;++col){
			vect[row][col]		= 0b11111111; //row %2 ? green : red;
		}
	}



}
int main(){
	//	Pin hSync(2,OUTPUT);
	//Pin vSync(46,OUTPUT);
	//Pin red(6,OUTPUT);
	//Pin green(7,OUTPUT);
	//Pin blue(8,OUTPUT);
	//red.setPWM(8000000,0);
	//green.setPWM(8000000,0);
	//blue.setPWM(8000000,0);
	//hSync.setPWM(31778,2); //31778 68700
	//vSync.setPWM(1000,50);
	//memset(vect,red,sizeof(vect));
	DDRL |= 0xFF;
	PORTL = 0;



	DDRF |= (1 << 2) | (1 << 1) | (1 << 0) ;
	PORTF = 0;
	DDRE |= 0xFF;

	setBuf();
	vgaInit();
	//vect[5][5] = red;
	//vect[MAX_HEIGHT/2][MAX_WIDTH/2] = green;

	TCCR3B |= (1<<CS30);
	TCCR5B |= (1<<CS42)|(0<<CS41) | (1<<CS40);


	UBRR1H = 0;
	UBRR1L = 0;
	// Enable receiver and transmitter //
	UCSR1B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8data, 1stop bit //
	UCSR1C = (1<<UCSZ01)|(1<<UCSZ00);
	UCSR1A = (1<<U2X0);
	//Serial *serial0 = SerialManager::getInstance(SERIAL0);
	//serial0->init(BAUD_1000000);
	//////sei();
	//uint16_t r = 2,g = 2, b = 2, freq = ICR4, hSync = 503, vSync = 312;
	sei();
	while(1){

	UDR1 = 0Xff;


	}
	return 0;
}







static  bool i = true;





ISR(TIMER2_COMPA_vect){

	//asm volatile("ldi r16,0x00\n\t" // BLACK
	//													"ldi r17,0x08\n\t" // RED
	//													"ldi r18,0x10\n\t" // GREEN
	//													"ldi r19,0x20\n\t" // BLUE
	//													"ldi r20,0x18\n\t" // YELLOW
	//													"ldi r21,0x28\n\t" // MAGENTA
	//													"ldi r22,0x30\n\t" // CYAN
	//													"ldi r23,0x38\n\t" // WHITE
	//													);


	//++inc;
}

ISR(TIMER3_COMPA_vect){
	NOP;
	asm volatile("ldi r16,0x00\n\t" // BLACK
														"ldi r17,0x08\n\t" // RED
														"ldi r18,0x10\n\t" // GREEN
														"ldi r19,0x20\n\t" // BLUE
														"ldi r20,0x18\n\t" // YELLOW
														"ldi r21,0x28\n\t" // MAGENTA
														"ldi r22,0x30\n\t" // CYAN
														"ldi r23,0x38\n\t" // WHITE



														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														);

	NOP;
}


volatile uint8_t row = 0;
ISR(TIMER3_COMPB_vect){
	/*asm volatile (
				"    ldi r20, 4       \n\t" //const for <<2bit
				".rept 30             \n\t" //output 4 pixels for each iteration
				"    ld r16, Z+       \n\t" //
				"    out %[port], r16 \n\t" //write pixel 1
				"    mul r16, r20     \n\t" //<<2
				"    out %[port], r0  \n\t" //write pixel 2
				"    mul r0, r20      \n\t" //<<4
				"    out %[port], r0  \n\t" //write pixel 3
				"    mul r0, r20      \n\t" //<<6
				"    out %[port], r0  \n\t" //write pixel 4
				".endr                \n\t" //
				"    nop              \n\t" //expand last pixel
				"    ldi r16, 0       \n\t" //
				"    out %[port], r16 \n\t" //write black for next pixels
				:
				: [port] "I" (_SFR_IO_ADDR(PORTF)),
				"z""I" (/*rline*///(uint8_t*)vect + row*120)
	//			:"r16", "r17", "r20", "r21", "memory"
	//			);
	//if (++row > MAX_HEIGHT ) row = 0;



}

ISR(TIMER3_COMPC_vect){
	//register volatile uint8_t row = 0;
	//register volatile uint8_t col = 0;
	//
	//(*(volatile uint8_t *)(0x102)) = black;
	//
	////while (col < MAX_WIDTH) {
	////	(*(volatile uint8_t *)(0x102)) = vect[row][col];
	////	++col;
	////}
	//
	//
	//(*(volatile uint8_t *)(0x102)) = black;
	//if (++row > MAX_HEIGHT ) row = 0;
	//
	//col = 0;
	asm volatile (
				"    ldi r20, 4       \n\t" //const for <<2bit
				".rept 50             \n\t" //output 4 pixels for each iteration
				"    ld r16, Z+       \n\t" //
				"    out %[port], r16 \n\t" //write pixel 1
				//	"    mul r16, r20     \n\t" //<<2
				//	"    out %[port], r0  \n\t" //write pixel 2
				//	"    mul r0, r20      \n\t" //<<4
				//	"    out %[port], r0  \n\t" //write pixel 3
				//	"    mul r0, r20      \n\t" //<<6
				//	"    out %[port], r0  \n\t" //write pixel 4
				".endr                \n\t" //
				"    nop              \n\t" //expand last pixel
				"    ldi r16, 0       \n\t" //
				"    out %[port], r16 \n\t" //write black for next pixels
				:
				: [port] "I" (_SFR_IO_ADDR(PORTF)),
				"z""I" (/*rline*/(char*)vect + 5)
				:"r16", "r17", "r20", "r21", "memory"
				);
	//if (++row > MAX_HEIGHT ) row = 0;
}




ISR(TIMER4_OVF_vect){
	asm volatile("ldi r16,0x00\n\t" // BLACK
														"ldi r17,0x08\n\t" // RED
														"ldi r18,0x10\n\t" // GREEN
														"ldi r19,0x20\n\t" // BLUE
														"ldi r20,0x18\n\t" // YELLOW
														"ldi r21,0x28\n\t" // MAGENTA
														"ldi r22,0x30\n\t" // CYAN
														"ldi r23,0x38\n\t" // WHITE



														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"

														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"

														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"

														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"

														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"

														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"

														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"

														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"

														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"

														);
}


ISR(TIMER4_COMPA_vect){
	asm volatile("ldi r16,0x00\n\t" // BLACK
														"ldi r17,0x08\n\t" // RED
														"ldi r18,0x10\n\t" // GREEN
														"ldi r19,0x20\n\t" // BLUE
														"ldi r20,0x18\n\t" // YELLOW
														"ldi r21,0x28\n\t" // MAGENTA
														"ldi r22,0x30\n\t" // CYAN
														"ldi r23,0x38\n\t" // WHITE



														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"

														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"
														"sts 0x102,r17\n\t"

														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"
														"sts 0x102,r18\n\t"

														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"
														"sts 0x102,r19\n\t"

														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"
														"sts 0x102,r20\n\t"

														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"
														"sts 0x102,r21\n\t"

														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"
														"sts 0x102,r22\n\t"

														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"
														"sts 0x102,r23\n\t"

														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"
														"sts 0x102,r16\n\t"

														);

}

ISR(TIMER4_COMPB_vect){
	PORTH ^= (1<<4);
	//PORTH ^= 0xFF;
}
ISR(TIMER4_COMPC_vect){
	PORTH ^= (1<<5);
	//PORTH ^= 0xFF;
}



ISR(TIMER5_COMPA_vect){
	asm volatile("ldi r16,0x00\n\t" // BLACK
														"ldi r17,0x08\n\t" // RED
														"ldi r18,0x10\n\t" // GREEN
														"ldi r19,0x20\n\t" // BLUE
														"ldi r20,0x18\n\t" // YELLOW
														"ldi r21,0x28\n\t" // MAGENTA
														"ldi r22,0x30\n\t" // CYAN
														"ldi r23,0x38\n\t" // WHITE
														);

	if(i){
		asm volatile("sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"

															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"
															"sts 0x102,r17\n\t"

															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"
															"sts 0x102,r18\n\t"

															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"
															"sts 0x102,r19\n\t"

															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"
															"sts 0x102,r20\n\t"

															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"
															"sts 0x102,r21\n\t"

															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"
															"sts 0x102,r22\n\t"

															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"
															"sts 0x102,r23\n\t"

															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"
															"sts 0x102,r16\n\t"

															);

	}

	i = !i;

}
/*
		if (serial0->isAvailable()){
			serial0->clear();
			char tmp = serial0->receive();

			switch (tmp) {
			case 'q':
				r++;
				//if(r > ICR4){
				//	r = 0;
				//}

				break;
			case 'w':
				--r;
				if(r > ICR4){
					r = 0;
				}
				break;

			case 'a':
				g++;
				if(g > ICR4){
					g = 0;
				}

				break;
			case 's':
				--g;
				if(g > ICR4){
					g= 0;
				}
				break;



			case 'z':
				b++;
				if(b > ICR4){
					b = 0;
				}

				break;
			case 'x':
				--b;
				if(b > ICR4){
					b = 0;
				}
				break;

			case 'k':
				freq++;
				break;
			case 'l':
				freq--;
				break;

			case 'i':
				hSync++;
				break;
			case 'o':
				hSync--;
				break;

			case 'm':
				vSync++;
				break;
			case ',':
				vSync--;
				break;

			default:
				break;
			}

			ICR4 = freq;
			OCR4A = r;
			OCR4B = g;// ICR4-5;
			OCR4C = b;// ICR4-5;
			ICR3 = hSync;
			OCR3B = ICR3-3;
			ICR5 = vSync;
			serial0->printf("vSync : %.03f Hz\r\n",1.0/(ICR5*0.000064));
			serial0->printf("hSync : %.03f Hz\r\n",1.0/(ICR3*0.0000000625));
			serial0->printf("Pixel : %.03f Hz\r\n",1.0/(ICR4*0.0000000625));
			//serial0->printf("Duty Red %u\r\n",);

			serial0->printf("OCR4A : %d OCR4B : %d OCR4C : %u ICR4 : %u ICR3 : %u\r\n",OCR4A,OCR4B,OCR4C,ICR4,ICR3);
			//nICR4 =a;
			//nOCR4A = ICR4-(rand() % 5);
			//nOCR4B = ICR4-(rand() % 5);
			//nOCR4C = ICR4-(rand() % 5);
		}

*/
/*
		asm volatile("ldi r16,85\n\t"
															"ldi r17,0\n\t"
															"sts 0x102,r17\n\t"
															"ldi r30, lo8(%0)\n\t"//  ; load Z = address of my_array
															"ldi r31, hi8(%0)\n\t"//  ; ...high byte also
														//	"OR	ZL,ZH\n\t"
															//"ldi r17,%0\n\t"
															"loop:\n\t"
															"sts 0x102,r17\n\t"
															"dec r16\n\t"
															"brne loop\n\t"
															"ldi r17,0\n\t"
															"sts 0x102,r17\n\t"
															: :"m"(vect[0][0])
															);
*/
