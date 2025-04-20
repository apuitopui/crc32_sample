/* ***************************************************************************
 * crc.c
 * ***************************************************************************
 * @brief: CRC calculation file
 * 
 * @details: This file contains the function prototype for CRC calculation.
 * 
 * @author: apuitopui
 * 
 *************************************************************************** */
#include "crc.h"

/* ********************************************************
 * Variables
 ******************************************************** */
uint32_t Crc32P4_Lookup_Table[CRC32_TABLE_SIZE] = {
    0x00000000, 0x30850ff5, 0x610a1fea, 0x518f101f, 0xc2143fd4, 0xf2913021, 0xa31e203e, 0x939b2fcb, 
    0x159615f7, 0x25131a02, 0x749c0a1d, 0x441905e8, 0xd7822a23, 0xe70725d6, 0xb68835c9, 0x860d3a3c, 
    0x2b2c2bee, 0x1ba9241b, 0x4a263404, 0x7aa33bf1, 0xe938143a, 0xd9bd1bcf, 0x88320bd0, 0xb8b70425, 
    0x3eba3e19, 0xe3f31ec, 0x5fb021f3, 0x6f352e06, 0xfcae01cd, 0xcc2b0e38, 0x9da41e27, 0xad2111d2, 
    0x565857dc, 0x66dd5829, 0x37524836, 0x7d747c3, 0x944c6808, 0xa4c967fd, 0xf54677e2, 0xc5c37817, 
    0x43ce422b, 0x734b4dde, 0x22c45dc1, 0x12415234, 0x81da7dff, 0xb15f720a, 0xe0d06215, 0xd0556de0, 
    0x7d747c32, 0x4df173c7, 0x1c7e63d8, 0x2cfb6c2d, 0xbf6043e6, 0x8fe54c13, 0xde6a5c0c, 0xeeef53f9, 
    0x68e269c5, 0x58676630, 0x9e8762f, 0x396d79da, 0xaaf65611, 0x9a7359e4, 0xcbfc49fb, 0xfb79460e, 
    0xacb0afb8, 0x9c35a04d, 0xcdbab052, 0xfd3fbfa7, 0x6ea4906c, 0x5e219f99, 0xfae8f86, 0x3f2b8073, 
    0xb926ba4f, 0x89a3b5ba, 0xd82ca5a5, 0xe8a9aa50, 0x7b32859b, 0x4bb78a6e, 0x1a389a71, 0x2abd9584, 
    0x879c8456, 0xb7198ba3, 0xe6969bbc, 0xd6139449, 0x4588bb82, 0x750db477, 0x2482a468, 0x1407ab9d, 
    0x920a91a1, 0xa28f9e54, 0xf3008e4b, 0xc38581be, 0x501eae75, 0x609ba180, 0x3114b19f, 0x191be6a, 
    0xfae8f864, 0xca6df791, 0x9be2e78e, 0xab67e87b, 0x38fcc7b0, 0x879c845, 0x59f6d85a, 0x6973d7af, 
    0xef7eed93, 0xdffbe266, 0x8e74f279, 0xbef1fd8c, 0x2d6ad247, 0x1defddb2, 0x4c60cdad, 0x7ce5c258, 
    0xd1c4d38a, 0xe141dc7f, 0xb0cecc60, 0x804bc395, 0x13d0ec5e, 0x2355e3ab, 0x72daf3b4, 0x425ffc41, 
    0xc452c67d, 0xf4d7c988, 0xa558d997, 0x95ddd662, 0x646f9a9, 0x36c3f65c, 0x674ce643, 0x57c9e9b6, 
    0xc8df352f, 0xf85a3ada, 0xa9d52ac5, 0x99502530, 0xacb0afb, 0x3a4e050e, 0x6bc11511, 0x5b441ae4, 
    0xdd4920d8, 0xedcc2f2d, 0xbc433f32, 0x8cc630c7, 0x1f5d1f0c, 0x2fd810f9, 0x7e5700e6, 0x4ed20f13, 
    0xe3f31ec1, 0xd3761134, 0x82f9012b, 0xb27c0ede, 0x21e72115, 0x11622ee0, 0x40ed3eff, 0x7068310a, 
    0xf6650b36, 0xc6e004c3, 0x976f14dc, 0xa7ea1b29, 0x347134e2, 0x4f43b17, 0x557b2b08, 0x65fe24fd, 
    0x9e8762f3, 0xae026d06, 0xff8d7d19, 0xcf0872ec, 0x5c935d27, 0x6c1652d2, 0x3d9942cd, 0xd1c4d38, 
    0x8b117704, 0xbb9478f1, 0xea1b68ee, 0xda9e671b, 0x490548d0, 0x79804725, 0x280f573a, 0x188a58cf, 
    0xb5ab491d, 0x852e46e8, 0xd4a156f7, 0xe4245902, 0x77bf76c9, 0x473a793c, 0x16b56923, 0x263066d6, 
    0xa03d5cea, 0x90b8531f, 0xc1374300, 0xf1b24cf5, 0x6229633e, 0x52ac6ccb, 0x3237cd4, 0x33a67321, 
    0x646f9a97, 0x54ea9562, 0x565857d, 0x35e08a88, 0xa67ba543, 0x96feaab6, 0xc771baa9, 0xf7f4b55c, 
    0x71f98f60, 0x417c8095, 0x10f3908a, 0x20769f7f, 0xb3edb0b4, 0x8368bf41, 0xd2e7af5e, 0xe262a0ab, 
    0x4f43b179, 0x7fc6be8c, 0x2e49ae93, 0x1ecca166, 0x8d578ead, 0xbdd28158, 0xec5d9147, 0xdcd89eb2, 
    0x5ad5a48e, 0x6a50ab7b, 0x3bdfbb64, 0xb5ab491, 0x98c19b5a, 0xa84494af, 0xf9cb84b0, 0xc94e8b45, 
    0x3237cd4b, 0x2b2c2be, 0x533dd2a1, 0x63b8dd54, 0xf023f29f, 0xc0a6fd6a, 0x9129ed75, 0xa1ace280, 
    0x27a1d8bc, 0x1724d749, 0x46abc756, 0x762ec8a3, 0xe5b5e768, 0xd530e89d, 0x84bff882, 0xb43af777, 
    0x191be6a5, 0x299ee950, 0x7811f94f, 0x4894f6ba, 0xdb0fd971, 0xeb8ad684, 0xba05c69b, 0x8a80c96e, 
    0xc8df352, 0x3c08fca7, 0x6d87ecb8, 0x5d02e34d, 0xce99cc86, 0xfe1cc373, 0xaf93d36c, 0x9f16dc99 
}; 

uint32_t Crc32P4_Lookup_SliceBy4_Table[4][CRC32P4_TABLE_SIZE] = {0};


/* ********************************************************
 * Functions
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
uint32_t Crc_CalculateCRC32P4_Bitwise(
    const uint8_t* Crc_DataPtr,
    uint32_t Crc_Length,
    uint32_t Crc_StartValue32,
    uint32_t Crc_Polynomial)
{
    uint32_t Crc_Value = Crc_StartValue32;
    for (uint32_t i = 0; i < Crc_Length; i++) {
        Crc_Value ^= (uint32_t)Crc_DataPtr[i];

        for (uint8_t j = 0; j < 8; j++) {

            Crc_Value = (Crc_Value >> 1) ^ ((Crc_Value & 1) ? Crc_Polynomial : 0);

            // branch implementation
            // if (Crc_Value & 1) {
            //     Crc_Value = (Crc_Value >> 1) ^ Crc_Polynomial;
            // } else {
            //     Crc_Value >>= 1;
            // }
        }
    }

    return Crc_Value;
}


/* 
 * @brief:  CRC32P4 table generation function
 * @param:  Crc_Table - Pointer to the table to be generated.
 * @return: None
*/
void Crc_GenerateCRC32P4_Table(void)
{
    for (uint32_t i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        uint32_t Crc_Value = i;
        for (uint8_t j = 0; j < 8; j++) {
            Crc_Value = (Crc_Value >> 1) ^ ((Crc_Value & 1) ? CRC32P4_POLYNOMIAL_REFLECT : 0);
        }
        Crc32P4_Lookup_Table[i] = Crc_Value;
    }
}

/* 
 * @brief:  CRC32P4 table generation function using slice by 4
 * @param:  Crc_Table - Pointer to the table to be generated.
 * @return: None
*/
void Crc_GenerateCRC32P4_SliceBy4_Table(void)
{
    for (uint32_t i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        uint32_t Crc_Value = i;
        for (uint8_t j = 0; j < 8; j++) {
            Crc_Value = (Crc_Value >> 1) ^ ((Crc_Value & 1) ? CRC32P4_POLYNOMIAL_REFLECT : 0);
        }
        Crc32P4_Lookup_SliceBy4_Table[0][i] = Crc_Value;
    }
    for (int t = 1; t < 4; t++) {
        for (int i = 0; i < 256; i++) {
            Crc32P4_Lookup_SliceBy4_Table[t][i] = (Crc32P4_Lookup_SliceBy4_Table[t - 1][i] >> 8) ^ Crc32P4_Lookup_SliceBy4_Table[0][Crc32P4_Lookup_SliceBy4_Table[t - 1][i] & 0xFF];
        }
    }
}

/* 
 * @brief:  CRC32P4 calculation function using lookup table
 *
 * @param:  Crc_DataPtr - Pointer to start address of data block to be calculated.
 * @param:  Crc_Length - Length of data block to be calculated in bytes.
 * @param:  Crc_StartValue32 - Start value when the algorithm starts.
 *
 * @return: Calculated CRC value
*/
uint32_t Crc_CalculateCRC32P4_Table(
    const uint8_t* Crc_DataPtr,
    uint32_t Crc_Length,
    uint32_t Crc_StartValue32)
{
    uint32_t Crc_Value = Crc_StartValue32;
    for (uint32_t i = 0; i < Crc_Length; i++) {
        Crc_Value = (Crc_Value >> 8) ^ Crc32P4_Lookup_Table[(Crc_Value & 0xFF) ^ Crc_DataPtr[i]];
    }
    return Crc_Value;
}

/* 
 * @brief:  CRC32P4 calculation function using lookup table and slice by 4
 *
 * @param:  Crc_DataPtr - Pointer to start address of data block to be calculated.
 * @param:  Crc_Length - Length of data block to be calculated in bytes.
 * @param:  Crc_StartValue32 - Start value when the algorithm starts.
 *
 * @return: Calculated CRC value
*/
uint32_t Crc_CalculateCRC32P4_SliceBy4_Table(
    const uint8_t* Crc_DataPtr,
    uint32_t Crc_Length,
    uint32_t Crc_StartValue32)
{
    uint32_t Crc_Value = Crc_StartValue32;

    while(Crc_Length >= 4) {
        uint32_t val = *(uint32_t*)Crc_DataPtr ^ Crc_Value;
        Crc_Value = Crc32P4_Lookup_SliceBy4_Table[3][val & 0xFF] ^ 
            Crc32P4_Lookup_SliceBy4_Table[2][(val >> 8) & 0xFF] ^ 
            Crc32P4_Lookup_SliceBy4_Table[1][(val >> 16) & 0xFF] ^ 
            Crc32P4_Lookup_SliceBy4_Table[0][(val >> 24) & 0xFF];
        Crc_DataPtr += 4;
        Crc_Length -= 4;
    }
}


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
uint32_t Crc_CalculateCRC32P4 (
    const uint8_t* Crc_DataPtr,
    uint32_t Crc_Length,
    uint32_t Crc_StartValue32,
    bool Crc_IsFirstCall)
{
    uint32_t Crc_Value;
    if(Crc_IsFirstCall == true) {
        Crc_Value = CRC32P4_INITIAL_VALUE;
    } else {
        Crc_Value = Crc_StartValue32 ^ CRC32P4_XOR_VALUE;
    }

    //Crc_GenerateCRC32P4_Table(Crc32P4_Table); // Generate CRC32P4 table

    Crc_Value = Crc_CalculateCRC32P4_SliceBy4_Table(Crc_DataPtr, Crc_Length, Crc_Value);

    return Crc_Value ^ CRC32P4_XOR_VALUE;
}