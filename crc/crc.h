/* ***************************************************************************
 * crc.h
 * ***************************************************************************
 * @brief: CRC calculation header file
 * 
 * @details: This file contains the function prototype for CRC calculation.
 * 
 * @author: apuitopui
 * 
 *************************************************************************** */
#ifndef CRC_H
#define CRC_H

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ********************************************************
 * Defines
 ******************************************************** */
#define CRC32_INITIAL_VALUE         0xFFFFFFFFUL
#define CRC32_POLYNOMIAL            0x04C11DB7UL
#define CRC32_POLYNOMIAL_REFLECT    0xEDB88320UL
#define CRC32_XOR_VALUE             0xFFFFFFFFUL
#define CRC32_TABLE_SIZE            256

#define CRC32P4_INITIAL_VALUE       0xFFFFFFFFUL
#define CRC32P4_POLYNOMIAL          0xFAACFB13UL
#define CRC32P4_POLYNOMIAL_REFLECT  0xC8DF352FUL
#define CRC32P4_XOR_VALUE           0xFFFFFFFFUL
#define CRC32P4_TABLE_SIZE          256

/* ********************************************************
 * Extern variables
 ******************************************************** */
extern uint32_t Crc32P4_Lookup_Table[CRC32_TABLE_SIZE];
extern uint32_t Crc32P4_Lookup_SliceBy4_Table[4][CRC32P4_TABLE_SIZE];

/* ********************************************************
 * Function prototypes
 ******************************************************** */
/*
    * @brief:  CRC32 calculation function(Could be used for CRC32P4)
    *
    * @param:  Crc_DataPtr - Pointer to start address of data block to be calculated.
    * @param:  Crc_Length - Length of data block to be calculated in bytes.
    * @param:  Crc_StartValue32 - Start value when the algorithm starts.
    * @param:  Crc_Polynomial - Polynomial used for CRC calculation.
    * @param:  Crc_XORValue - XOR value used for CRC calculation.
    *
    * @return: Calculated CRC value
*/
uint32_t Crc_CalculateCRC32_Bitwise(
    const uint8_t* Crc_DataPtr,
    uint32_t Crc_Length,
    uint32_t Crc_StartValue32,
    uint32_t Crc_Polynomial
);

/* 
 * @brief:  CRC32P4 table generation function
 *
 * @param:  Crc_Table - Pointer to the table to be generated.
 *
 * @return: None
*/
void Crc_GenerateCRC32P4_Table(void);

/* 
 * @brief:  CRC32P4 table generation function using slice by 4
 * @param:  Crc_Table - Pointer to the table to be generated.
 * @return: None
*/
void Crc_GenerateCRC32P4_SliceBy4_Table(void);

/*
 * @brief:  CRC32P4 calculation function according to AUTOSAR Specification of CRC Routine
 *
 * @param:  Crc_DataPtr - Pointer to start address of data block to be calculated.
 * @param:  Crc_Length - Length of data block to be calculated in bytes.
 * @param:  Crc_StartValue32 - Start value when the algorithm starts.
 * @param:  Crc_IsFirstCall - Flag to indicate if this is the first call
 *
 * @return: Calculated CRC value
*/
uint32_t Crc_CalculateCRC32P4(
    const uint8_t* Crc_DataPtr, 
    uint32_t Crc_Length, 
    uint32_t Crc_StartValue32, 
    bool Crc_IsFirstCall
);
#endif //CRC_H