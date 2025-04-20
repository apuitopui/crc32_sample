#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

#include "crc.h"

void test_crc32p4(uint8_t* data, uint32_t length)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);                         /* Start time measurement */
    uint32_t crc = Crc_CalculateCRC32P4(data, length, 0, true);     /* Calculate CRC32P4 */
    clock_gettime(CLOCK_MONOTONIC, &end);                           /* End time measurement */

    // Calculate elapsed time in nanoseconds
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    long long elapsed_ns = seconds * 1e9 + nanoseconds;

    
    printf("CRC32P4 result for ");
    for (size_t i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("is: %08X ", crc);
    printf("Time taken: %.lld ns\n", elapsed_ns);
}

void main(void)
{
    Crc_GenerateCRC32P4_SliceBy4_Table();
    printf("CRC32P4 table generated\n");
    printf("CRC32P4 table size: %d\n", CRC32P4_TABLE_SIZE);
    for (int i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        printf("0x%x, ", Crc32P4_Lookup_SliceBy4_Table[0][i]);
        if((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    for (int i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        printf("0x%x, ", Crc32P4_Lookup_SliceBy4_Table[1][i]);
        if((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    for (int i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        printf("0x%x, ", Crc32P4_Lookup_SliceBy4_Table[2][i]);
        if((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    for (int i = 0; i < CRC32P4_TABLE_SIZE; i++) {
        printf("0x%x, ", Crc32P4_Lookup_SliceBy4_Table[3][i]);
        if((i + 1) % 8 == 0) {
            printf("\n");
        }
    }

    /* Test data for CRC Calculation */
    uint8_t data1[4] = {0x00, 0x00, 0x00, 0x00};
    uint8_t data2[3] = {0xF2, 0x01, 0x83};
    uint8_t data3[4] = {0x0F, 0xAA, 0x00, 0x55};
    uint8_t data4[4] = {0x00, 0xFF, 0x55, 0x11};
    uint8_t data5[9] = {0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    uint8_t data6[3] = {0x92, 0x6B, 0x55};
    uint8_t data7[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t data9[9] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

    test_crc32p4(data1, sizeof(data1)/sizeof(data1[0]));
    test_crc32p4(data2, sizeof(data2)/sizeof(data2[0]));
    test_crc32p4(data3, sizeof(data3)/sizeof(data3[0]));
    test_crc32p4(data4, sizeof(data4)/sizeof(data4[0]));
    test_crc32p4(data5, sizeof(data5)/sizeof(data5[0]));
    test_crc32p4(data6, sizeof(data6)/sizeof(data6[0]));
    test_crc32p4(data7, sizeof(data7)/sizeof(data7[0]));
    test_crc32p4(data9, sizeof(data9)/sizeof(data9[0]));
}
 