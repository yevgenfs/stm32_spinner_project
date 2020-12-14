/*
 * uart.c
 *
 *  Created on: 9 груд. 2020 р.
 *      Author: yevhen.surkov
 */
#include "uart.h"

uart_err_t uart_init(obj_uart_t* objP_this)
{
    if (objP_this == NULL)
    {
        return e_uart_err_init_fail;
    }

    objP_this->uart_handler->Instance           = &objP_this->uart_type;
    objP_this->uart_handler->Init.BaudRate      = objP_this->baud_rate;
    objP_this->uart_handler->Init.WordLength    = UART_WORDLENGTH_8B;
    objP_this->uart_handler->Init.StopBits      = UART_STOPBITS_1;
    objP_this->uart_handler->Init.Parity        = UART_PARITY_NONE;
    objP_this->uart_handler->Init.Mode          = UART_MODE_TX_RX;
    objP_this->uart_handler->Init.HwFlowCtl     = UART_HWCONTROL_NONE;
    objP_this->uart_handler->Init.OverSampling  = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(objP_this->uart_handler) != HAL_OK)
    {
      Error_Handler();
      return e_uart_err_init_fail;
    }

    return e_uart_err_ok;
}

uart_err_t uart_deinit(obj_uart_t* objP_this)
{
    if (objP_this == NULL)
    {
        return e_uart_err_deinit_fail;
    }

    return e_uart_err_ok;
}

uart_err_t uart_send(obj_uart_t* objP_this, uint8_t* str)
{
    if (objP_this == NULL && str == NULL)
    {
        return e_uart_err_send_fail;
    }

    return (HAL_UART_Transmit_IT(objP_this->uart_handler, str, strlen(str)) == HAL_OK) ?
            e_uart_err_ok : e_uart_err_send_fail;
}