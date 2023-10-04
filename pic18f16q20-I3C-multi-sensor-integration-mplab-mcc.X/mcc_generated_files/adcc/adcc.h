/**
 * ADCC Generated Driver API Header File
 * 
 * @file adcc.h
 * 
 * @defgroup  adcc ADCC
 * 
 * @brief This file contains the API prototypes and data types for the ADCC driver.
 *
 * @version ADCC Driver Version 1.0.2
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef ADCC_H
#define ADCC_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>


/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_Initialize API
 */
#define ADCC_Initialize ADCC_Initialize

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_DischargeSampleCapacitor API
 */
#define ADCC_DischargeSampleCapacitor ADCC_DischargeSampleCapacitor

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_StartConversion API
 */
#define ADCC_StartConversion ADCC_StartConversion

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_StopConversion API
 */
#define ADCC_StopConversion ADCC_StopConversion

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_IsConversionDone API
 */
#define ADCC_IsConversionDone ADCC_IsConversionDone

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetConversionResult API
 */
#define ADCC_GetConversionResult ADCC_GetConversionResult

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetSingleConversion API
 */
#define ADCC_GetSingleConversion ADCC_GetSingleConversion

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetConversionStageStatus API
 */
#define ADCC_GetConversionStageStatus ADCC_GetConversionStageStatus

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_EnableContinuousConversion API
 */
#define ADCC_EnableContinuousConversion ADCC_EnableContinuousConversion

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_DisableContinuousConversion API
 */
#define ADCC_DisableContinuousConversion ADCC_DisableContinuousConversion

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetStopOnInterrupt API
 */
#define ADCC_SetStopOnInterrupt ADCC_SetStopOnInterrupt

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_EnableDoubleSampling API
 */
#define ADCC_EnableDoubleSampling ADCC_EnableDoubleSampling

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_LoadAcquisitionRegister API
 */
#define ADCC_LoadAcquisitionRegister ADCC_LoadAcquisitionRegister

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetPrechargeTime API
 */
#define ADCC_SetPrechargeTime ADCC_SetPrechargeTime

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_DefineSetPoint API
 */
#define ADCC_DefineSetPoint ADCC_DefineSetPoint

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetUpperThreshold API
 */
#define ADCC_SetUpperThreshold ADCC_SetUpperThreshold

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetLowerThreshold API
 */
#define ADCC_SetLowerThreshold ADCC_SetLowerThreshold

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_HasErrorCrossedUpperThreshold API
 */
#define ADCC_HasErrorCrossedUpperThreshold ADCC_HasErrorCrossedUpperThreshold

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_HasErrorCrossedLowerThreshold API
 */
#define ADCC_HasErrorCrossedLowerThreshold ADCC_HasErrorCrossedLowerThreshold

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetRepeatCount API
 */
#define ADCC_SetRepeatCount ADCC_SetRepeatCount

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetCurrentCountofConversions API
 */
#define ADCC_GetCurrentCountofConversions ADCC_GetCurrentCountofConversions

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetAccumulatorValue API
 */
#define ADCC_GetAccumulatorValue ADCC_GetAccumulatorValue

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_ClearAccumulator API
 */
#define ADCC_ClearAccumulator ADCC_ClearAccumulator

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_HasAccumulatorOverflowed API
 */
#define ADCC_HasAccumulatorOverflowed ADCC_HasAccumulatorOverflowed

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetErrorCalculation API
 */
#define ADCC_GetErrorCalculation ADCC_GetErrorCalculation

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetPreviousResult API
 */
#define ADCC_GetPreviousResult ADCC_GetPreviousResult

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_GetFilterValue API
 */
#define ADCC_GetFilterValue ADCC_GetFilterValue

/**
 * @ingroup  adcc
 * @brief    Defines the Custom Name for the \ref ADCC_SetADTIInterruptHandler API
 */
#define ADCC_SetADTIInterruptHandler ADCC_SetADTIInterruptHandler

/**
 @ingroup adcc
 @typedef adc_result_t
 @brief Used for the result of the Analog-to-Digital (A/D) conversion.
*/
typedef uint16_t adc_result_t;

/**
 * @ingroup adcc
 * @enum adcc_channel_t
 * @brief Contains the available ADC channels.
*/
typedef enum
{
    channel_ADCG1 =  0x31,
    channel_FVR_Buffer1 =  0x3b,
    channel_Temp =  0x3c,
    channel_VDDIO3_by_10 =  0x3d,
    channel_VDDIO2_by_10 =  0x3e,
    channel_VSS =  0x3f,
    channel_ANA2 =  0x2,
    channel_ANB7 =  0xf,
    channel_ANA0 =  0x0
} adcc_channel_t;

/**
  Section: ADCC Module APIs
*/

/**
 * @ingroup adcc
 * @brief Initializes the ADC module. This routine is called before any other ADC routine.
 * @param None.
 * @return None.
*/
void ADCC_Initialize(void);

/**
 * @ingroup adcc
 * @brief Starts A/D conversion on the selected channel.
 * @pre ADCC_Initialize() function is called before calling this function to enable ADC.
 * @param channel - Analog channel number on which the A/D conversion has to be applied.
 *                  Refer to adcc_channel_t for the available list of channels.
 * @return None.
*/
void ADCC_StartConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Checks if ongoing A/D conversion is complete.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - A/D conversion is complete.
 * @retval False - A/D conversion is ongoing.
*/
bool ADCC_IsConversionDone(void);

/**
 * @ingroup adcc
 * @brief Retrieves the result of the latest A/D conversion.
 * @pre ADCC_StartConversion() is called before calling this function and completion status is checked using the ADCC_IsConversionDone() routine.
 * @param None.
 * @return The result of A/D conversion. Refer to the adc_result_t.
*/
adc_result_t ADCC_GetConversionResult(void);

/**
 * @ingroup adcc
 * @brief Retrieves the result of a single A/D conversion on any given channel.
 * @pre Enable ADC using the ADCC_Initialize() function. Also ADCC_DisableContinuousConversion() function is called before calling this function. 
 * @param channel - Analog channel number on which the A/D conversion will be applied.
 *                  Refer to adcc_channel_t for available channels
 * @return The result of a single A/D conversion. Refer to the adc_result_t.
*/
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Stops the ongoing A/D conversion.
 * @pre ADCC_StartConversion() function is called before calling this function.
 * @param None.
 * @return None.
*/
 inline void ADCC_StopConversion(void);

/**
 * @ingroup adcc
 * @brief Enables Stop On Interrupt bit.
 * @pre ADCC_EnableContinuousConversion() function is called before calling this function.
 * @param None.
 * @return None.
*/
inline void ADCC_SetStopOnInterrupt(void);

/**
 * @ingroup adcc
 * @brief Discharges the input sample capacitor by setting the channel to AVss.
 * @param None.
 * @return None.
*/
inline void ADCC_DischargeSampleCapacitor(void);

/**
 * @ingroup adcc
 * @brief Loads ADC Acquisition Time Control register with the specified value.
 * @param acquisitionValue - Value to be loaded in the acquisition time control register
 * @return None.
*/
void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue);

/**
 * @ingroup adcc
 * @brief Loads ADC Precharge Time Control register with the specified value.
 * @param prechargeTime - Value to be loaded in the precharge time control register
 * @return None.
*/
void ADCC_SetPrechargeTime(uint16_t prechargeTime);

/**
 * @ingroup adcc
 * @brief Loads the ADC Repeat Count register with specified value.
 * @param repeatCount - Value to be loaded to repeat counter
 * @return None.
*/
void ADCC_SetRepeatCount(uint8_t repeatCount);

/**
 * @ingroup adcc
 * @brief Retrieves the current value of ADC Repeat Count register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return Current value of the ADC Repeat Count register
*/
uint8_t ADCC_GetCurrentCountofConversions(void);

/**
 * @ingroup adcc
 * @brief Clears the accumulator.
 * @param None.
 * @return None.
*/
inline void ADCC_ClearAccumulator(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC accumulator.
 * @param None.
 * @return Value of ADC accumulator
*/
uint16_t ADCC_GetAccumulatorValue(void);

/**
 * @ingroup adcc
 * @brief Determines whether ADC accumulator has overflowed.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC accumulator has overflowed.
 * @retval False - ADC accumulator has not overflowed.
*/
bool ADCC_HasAccumulatorOverflowed(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of the ADC Filter(ADFLTR) register.
 * @param None.
 * @return 16-bit value obtained from the high byte ADFLTR(ADFLTRH) and low byte ADFLTR(ADFLTRL) registers.
*/
uint16_t ADCC_GetFilterValue(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of the ADC Previous(ADPREV) register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return 16-bit value obtained from the high byte ADPREV(ADPREVH) and low byte ADPREV(ADPREVL) registers.
*/
uint16_t ADCC_GetPreviousResult(void);

/**
 * @ingroup adcc
 * @brief Sets the value of the ADC Threshold Setpoint(ADSTPT) register.
 * @param setPoint - 16-bit value for the ADC Threshold Setpoint register
 * @return None.
*/
void ADCC_DefineSetPoint(uint16_t setPoint);

/**
 * @ingroup adcc
 * @brief Sets the value of ADC Upper Threshold(ADUTH) register.
 * @param upperThreshold - 16-bit value for the ADC Upper Threshold register
 * @return None.
*/
void ADCC_SetUpperThreshold(uint16_t upperThreshold);

/**
 * @ingroup adcc
 * @brief Sets the value of ADC Lower Threshold(ADLTH) register.
 * @param lowerThreshold - 16-bit value for the ADC Lower Threshold register
 * @return None.
*/
void ADCC_SetLowerThreshold(uint16_t lowerThreshold);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC Set-point Error register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return 16-bit value obtained from the high byte ADERR(ADERRH) and low byte ADERR(ADERRL) registers.
*/
uint16_t ADCC_GetErrorCalculation(void);

/**
 * @ingroup adcc
 * @brief Enables double-sampling bit.
 * @param None.
 * @return None.
*/
inline void ADCC_EnableDoubleSampling(void);

/**
 * @ingroup adcc
 * @brief Enables continuous conversion.
 * @param None.
 * @return None.
*/
inline void ADCC_EnableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Disables continuous conversion.
 * @param None.
 * @return None.
*/
inline void ADCC_DisableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error has crossed the upper threshold.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC error has crossed the upper threshold
 * @retval False - ADC error has not crossed the upper threshold
*/
bool ADCC_HasErrorCrossedUpperThreshold(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error is less than the lower threshold.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC error has crossed the lower threshold
 * @retval False - ADC error has not crossed the lower threshold
*/
bool ADCC_HasErrorCrossedLowerThreshold(void);

/**
 * @ingroup adcc
 * @brief Retrieves the multi-stage status.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return Contents of ADC STATUS register
*/
uint8_t ADCC_GetConversionStageStatus(void);

/**
 * @ingroup adcc
 * @brief Sets the callback for the ADC Threshold Interrupt(ADTI).
 * @param InterruptHandler - Callback function to be called on the interrupt event
 * @return None.
*/
void ADCC_SetADTIInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup adcc
 * @brief Implements the ADC Threshold Interrupt(ADTI) service routine for the interrupt-driven implementations.
 * @param None.
 * @return None.
*/
void ADCC_ThresholdISR(void);

#endif//ADCC_H
