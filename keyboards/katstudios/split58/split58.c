#include "split58.h"
#include QMK_KEYBOARD_H


/*

// UART transport code modified from
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/whale/sk/v3/v3.c
// thanks whale, you did what qmk couldn't

#if defined(__AVR__)
#    include <avr/io.h>
#    include <avr/interrupt.h>
#endif

#define ROWS_PER_HAND (MATRIX_ROWS / 2)
#define SLAVE_MATRIX_SYNC_ADDR (0x01)

typedef struct {
    char*  buffer;
    size_t count;
    bool*  flag;
} transmit_status;

transmit_status irx = {}, itx = {};

// Buffer for master/slave matrix scan transmit.
// Master: receive buffer.
// Slave: transmit buffer.
matrix_row_t sync_matrix[ROWS_PER_HAND];
bool         matrix_synced = false;

void USART_init(uint16_t baud) {
    cli();

    UBRR1H = (unsigned char)(baud >>8);
    UBRR1L = (unsigned char)(baud);
    //UBRR1 = baud;
    // Enable U2X1 for double speed.
    UCSR1A = (1 << U2X1);
    // Enable RX/TX, 9N1 mode
    UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1) | (1 << TXCIE1) | (1 << UCSZ12);
    UCSR1C = (1 << UCSZ10) | (1 << UCSZ11);
    sei();
}

ISR(USART1_RX_vect) {
    // read data from reg.
    uint8_t status   = UCSR1A;
    uint8_t high_bit = UCSR1B;
    uint8_t low_data = UDR1;
    if (status & ((1 << FE1) | (1 << DOR1) | (1 << UPE1))) {
        // Something error happen, ignore this package.
        irx.count = 0;
        return;
    }

    // Is it a addr? (9th bit is one/zero?)
    if (high_bit & (1 << RXB81)) {
        // data is addr. prepend for receive.
        switch (low_data) {
            case SLAVE_MATRIX_SYNC_ADDR:
                irx.buffer = (char *)sync_matrix;
                irx.count = sizeof(sync_matrix) * sizeof(matrix_row_t);
                irx.flag = &matrix_synced;
                break;

            default:
                // ignore this package.
                irx.count = 0;
                break;
        }

    } else if (irx.count > 0) {
        *irx.buffer = low_data;
        ++irx.buffer;
        if (--irx.count == 0 && irx.flag != NULL) {
            *irx.flag = true;
        }
    }
}

// TX complete
ISR(USART1_TX_vect) {
    // Is in transmit?
    if (itx.count > 0) {
        // Send data.
        UCSR1B &= ~(1 << TXB81);
        UDR1 = *itx.buffer;

        // Move to next char.
        ++itx.buffer;
        if (--itx.count == 0) {
            *itx.flag = true;
        }
    }
    // TODO: read queue/register for next message.
}

// return: queue depth.
int send_packet(uint8_t addr, char* buffer, size_t length, bool* flag) {
    // See if we can start transmit right now.
    if ((itx.count == 0) && (UCSR1A & (1 << UDRE1))) {
        // Ready to write.
        // Prepend registers.
        itx.buffer = buffer;
        itx.count  = length;
        itx.flag   = flag;

        // Write addr to kick start transmit.
        UCSR1B |= (1 << TXB81);
        UDR1 = addr;
        // TODO: put request in queue;
        // }else{
    }

    return 0;
}

void transport_master_init(void) { USART_init(12); }

void transport_slave_init(void) { USART_init(12); }

// returns false if valid data not received from slave
bool transport_master(matrix_row_t matrix[]) {
    if (matrix_synced) {
        for (uint8_t i = 0; i < ROWS_PER_HAND; ++i) {
            matrix[i] = sync_matrix[i];
        }
        matrix_synced = false;
        return true;
    }
    return false;
}

void transport_slave(matrix_row_t matrix[]) {
    for (uint8_t i = 0; i < ROWS_PER_HAND; ++i) {
        sync_matrix[i] = matrix[i];
    }
    matrix_synced = false;
    send_packet(SLAVE_MATRIX_SYNC_ADDR, (char*)sync_matrix, sizeof(sync_matrix) * sizeof(matrix_row_t), &matrix_synced);
}\
*/



#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 1,   2,  3,  4,  5,  6 },
  { 7,   8,  9, 10, 11, 12 },
  { 13, 14, 15, 16, 17, 18 },
  { 19, 20, 21, 22, 23, 24 },
  { 25, 26, 27, 28, NO_LED, 29 },

  {    30, 31, 32, 33, 34, 35 },
  {    36, 37, 38, 39, 40, 41 },
  {    42, 43, 44, 45, 46, 47 },
  {    48, 49, 50, 51, 52, 53 },
  {54, NO_LED, 55, 56, 57, 58 }
}, {
  // LED Index to Physical Position
 // {0,  5},   {17,  5},  {34,  0},  {51,  0},  {68,  2},  {85,  2},
  {0, 15},   {17, 15},  {34, 10},  {51, 10},  {68, 12},  {85, 12}, 
  {0, 25},   {17, 25},  {34, 20},  {51, 20},  {68, 22},  {85, 22}, 
  {0, 35},   {17, 35},  {34, 30},  {51, 30},  {68, 32},  {85, 32}, 
  {0, 45},   {17, 45},  {34, 40},  {51, 40},  {68, 42},  {85, 42}, 
  {0, 64},   {17, 61},  {34, 58},  {51, 55},       {77, 53},

 // {139,  2}, {156,  2}, {173,  0}, {190,  0}, {207,  5}, {224,  5},
  {139, 12}, {156, 12}, {173, 10}, {190, 10}, {207, 15}, {224, 15},
  {139, 22}, {156, 22}, {173, 20}, {190, 20}, {207, 25}, {224, 25},
  {139, 32}, {156, 32}, {173, 30}, {190, 30}, {207, 35}, {224, 35},
  {139, 42}, {156, 42}, {173, 40}, {190, 40}, {207, 45}, {224, 45},
       {147, 53},       {173, 55}, {190, 58}, {207, 61}, {224, 64}
  
}, {
  // LED Index to Flag
  1, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 4, 4,
  1, 1, 1, 1,  4,

  4, 4, 4, 4, 4, 1,
  4, 4, 4, 4, 4, 1,
  4, 4, 4, 4, 4, 1,
  4, 4, 4, 4, 4, 1,
    4,  1, 1, 1, 1

} };
#endif
