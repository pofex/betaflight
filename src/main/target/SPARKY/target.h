/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "SPKY" // SParKY

#define CONFIG_FASTLOOP_PREFERRED_ACC ACC_NONE

#define LED0                    PB4  // Blue (Rev 1 & 2) - PB4
#define LED1                    PB5  // Green (Rev 1) / Red (Rev 2) - PB5

#define BEEPER                  PA1
#define BEEPER_INVERTED

// MPU6050 interrupts
#define USE_EXTI
#define MPU_INT_EXTI            PA15
#define EXTI15_10_CALLBACK_HANDLER_COUNT 1 // MPU data ready
#define USE_MPU_DATA_READY_SIGNAL

// MPU 9150 INT connected to PA15, pulled up to VCC by 10K Resistor, contains MPU6050 and AK8975 in single component.
#define GYRO
#define USE_GYRO_MPU6050
#define GYRO_MPU6050_ALIGN      CW270_DEG

#define ACC
#define USE_ACC_MPU6050
#define ACC_MPU6050_ALIGN       CW270_DEG

#define BARO
#define USE_BARO_MS5611
#define USE_BARO_BMP280

#define MAG
#define USE_MAG_AK8975

#define MAG_AK8975_ALIGN        CW180_DEG_FLIP

#define USE_VCP
#define USE_UART1 // Conn 1 - TX (PB6) RX PB7 (AF7)
#define USE_UART2 // Input - RX (PA3)
#define USE_UART3 // Servo out - 10/RX (PB11) 11/TX (PB10)
#define SERIAL_PORT_COUNT       4

#define UART1_TX_PIN            PB6
#define UART1_RX_PIN            PB7

#define UART2_TX_PIN            PA2 // PA2 - Clashes with PWM6 input.
#define UART2_RX_PIN            PA3

#define UART3_TX_PIN            PB10 // PB10 (AF7)
#define UART3_RX_PIN            PB11 // PB11 (AF7)

// Note: PA5 and PA0 are N/C on the sparky - potentially use for ADC or LED STRIP?

#define USE_I2C
#define I2C_DEVICE (I2CDEV_2) // SDA (PA10/AF4), SCL (PA9/AF4)

#define USE_ADC
#define ADC_INSTANCE            ADC2
#define VBAT_ADC_PIN            PA4
#define CURRENT_METER_ADC_PIN   PA7

#define DEFAULT_RX_FEATURE      FEATURE_RX_PPM

#define LED_STRIP
#if 1
// LED strip configuration using PWM motor output pin 5.
#define USE_LED_STRIP_ON_DMA1_CHANNEL3
#define WS2811_PIN                      PA6 // TIM16_CH1
#define WS2811_TIMER                    TIM16
#define WS2811_DMA_CHANNEL              DMA1_Channel3
#define WS2811_IRQ                      DMA1_Channel3_IRQn
#define WS2811_DMA_TC_FLAG              DMA1_FLAG_TC3
#define WS2811_DMA_HANDLER_IDENTIFER    DMA1_CH3_HANDLER
#endif

#if 0
// Alternate LED strip pin
// FIXME DMA IRQ Transfer Complete is never called because the  TIM17_DMA_RMP needs to be set in SYSCFG_CFGR1
#define LED_STRIP_TIMER TIM17

#define USE_LED_STRIP_ON_DMA1_CHANNEL7
#define WS2811_GPIO                     GPIOA
#define WS2811_GPIO_AHB_PERIPHERAL      RCC_AHBPeriph_GPIOA
#define WS2811_GPIO_AF                  GPIO_AF_1
#define WS2811_PIN                      GPIO_Pin_7 // TIM17_CH1
#define WS2811_PIN_SOURCE               GPIO_PinSource7
#define WS2811_TIMER                    TIM17
#define WS2811_TIMER_APB2_PERIPHERAL    RCC_APB2Periph_TIM17
#define WS2811_DMA_CHANNEL              DMA1_Channel7
#define WS2811_IRQ                      DMA1_Channel7_IRQn
#endif

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define SPEKTRUM_BIND
// USART2, PA3
#define BIND_PIN                PA3

//#define SONAR
//#define SONAR_ECHO_PIN          PB1
//#define SONAR_TRIGGER_PIN       PA2

// available IO pins (from schematics)
//#define TARGET_IO_PORTA (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15))
//#define TARGET_IO_PORTB (BIT(0)|BIT(1)|BIT(10)|BIT(11)|BIT(14)|BIT(15)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9))
// !!TODO - check following lines are correct
#define TARGET_IO_PORTA         (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15))
#define TARGET_IO_PORTB         (BIT(0)|BIT(1)|BIT(6)|BIT(10)|BIT(11)|BIT(14)|BIT(15)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(12)|BIT(13))
#define TARGET_IO_PORTF         (BIT(0)|BIT(1)|BIT(4))

#define USABLE_TIMER_CHANNEL_COUNT 11
#define USED_TIMERS             (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(15) | TIM_N(17))

