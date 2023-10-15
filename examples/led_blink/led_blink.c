#include "stm32f429xx.h"
/*
 * File: led_blink.c
 * Author: Abbas Raza
 * Description: This program blinks LED 3 of an STM32F429I-DISC1 discovery board.
 *              The delay between each blink is set to BLINK_DELAY seconds (roughly).
 * 
 * Steps to blink LED:
 * 1. Enable the clock for GPIO port
 * 2. Configure the GPIO pin as output
 * 3. Toggle the GPIO pin to turn the LED on and off
 * 4. Add a delay between each toggle to control the blinking speed
 */

#define BLINK_DELAY 2000000

// Function to create a delay
void simple_delay(uint32_t delay)
{
    for (; delay > 0; delay--);
}

int main(void)
{
    /* Enable GPIOG clock*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN; // Enable clock for GPIOG

    /* Make Pin 13 output (MODER: bits 27:26) */
    GPIOG->MODER &= ~(GPIO_MODER_MODE13_Msk); // Clear bits 27:26 to set as output
    GPIOG->MODER |= GPIO_MODER_MODE13_0;      // Set MODER bits 27:26 to 01

    /* Set or clear pins (ODR: bit 13) */
    GPIOG->ODR |= GPIO_ODR_OD13_Msk; // Set Pin 13

    // the code should exit
    while (1)
    {
        simple_delay(BLINK_DELAY);
        GPIOG->ODR ^= GPIO_ODR_OD13_Msk; // Toggle Pin 13
    }

    return 0;
}