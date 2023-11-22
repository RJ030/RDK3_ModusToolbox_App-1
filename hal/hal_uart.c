/*
 * hal_uart.c
 *
 *  Created on: 14 Nov 2023
 *      Author: jorda
 */


#include "hal_uart.h"

#include "cyhal_uart.h"
#include "cycfg_pins.h"

// UART context variables
cyhal_uart_t uart_obj;

// Initialize the ARDUINO UART configuration structure
const cyhal_uart_cfg_t uart_config =
{
    .data_bits = 8,
    .stop_bits = 1,
    .parity = CYHAL_UART_PARITY_NONE,
    .rx_buffer = NULL,
    .rx_buffer_size = 0
};

int hal_uart_init()
{
	cy_rslt_t result = cyhal_uart_init(&uart_obj, ARDU_TX, ARDU_RX, NC, NC, NULL, &uart_config);
	if (result != CY_RSLT_SUCCESS) return -1;

	uint32_t baudrate = 115200;
	result = cyhal_uart_set_baud(&uart_obj, baudrate, &baudrate);
	if (result != CY_RSLT_SUCCESS) return -2;

	return 0;
}

uint32_t hal_uart_readable(void)
{
	return cyhal_uart_readable(&uart_obj);
}

int hal_uart_read(uint8_t* buffer, uint16_t size)
{
	size_t toread = (size_t)size;
	cy_rslt_t result = cyhal_uart_read (&uart_obj, buffer, &toread);
	if (result != CY_RSLT_SUCCESS) return -1;
	return (int)toread;
}

int hal_uart_write(uint8_t* buffer, uint16_t size)
{
	size_t towrite = (size_t)size;
	cy_rslt_t result = cyhal_uart_write(&uart_obj, buffer, &towrite);
	if (result != CY_RSLT_SUCCESS) return -1;
	return (int)towrite;
}
