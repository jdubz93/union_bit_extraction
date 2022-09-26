#include <stdio.h>
#include <stdint.h>


union Packet
{
    uint32_t packetValue;
    struct {
        /* data */
        uint32_t crc:2; // 2 bits
        uint32_t status:1; // 1 bit
        uint32_t payload:12; // 12 bits
        uint32_t bat:3; // 3 bits
        uint32_t sensor:3; // 3 bits 
        uint32_t longAddr:8; // 8 bits long
        uint32_t shortAddr:2; // 2 bits short
        uint32_t addrMode:1; // 1 bit char
    }packetFields;
};


void print_binary(unsigned int number);

int main(void)
{
    union Packet pkt;
    printf("Enter a 32 bit packet value:\n0x");
    uint32_t packet_input;
    scanf("%X", &pkt.packetValue);

// now I can get rid of all this, since the union above will automatically assign the values based on bit position,
// and both member variables access the same memory, so specifying the bit positions is all thats needed.

    // packet.crc = (uint32_t)(packet_input & 0x3); // first 2 bits
    // packet.status = (uint32_t)((packet_input >> 2) & 0x1); // 3rd bit
    // packet.payload = (uint32_t)((packet_input >> 3) & 0xFFF); // next 12 bits
    // packet.bat = (uint32_t)((packet_input >> 15) & 0x7); // next 3 bits
    // packet.sensor = (uint32_t)((packet_input >> 18) & 0x7); // next 3 bits
    // packet.longAddr = (uint32_t)((packet_input >> 21) & 0xFF); // next 8 bits
    // packet.shortAddr = (uint32_t)((packet_input >> 29) & 0x3); // next 2 bits
    // packet.addrMode = (uint32_t)((packet_input >> 31) & 0x1); // last bit
    
    printf("\nCRC = %#X\n", pkt.packetFields.crc);
    printf("binary val = ");
    print_binary(pkt.packetFields.crc);
    printf("\n");

    printf("\nStatus = %#X\n", pkt.packetFields.status);
    printf("binary val = ");
    print_binary(pkt.packetFields.status);
    printf("\n");

    printf("\nPayload = %#X\n", pkt.packetFields.payload);
    printf("binary val = ");
    print_binary(pkt.packetFields.payload);
    printf("\n");

    printf("\nBAT = %#X\n", pkt.packetFields.bat);
    printf("binary val = ");
    print_binary(pkt.packetFields.bat);
    printf("\n");

    printf("\nSensor = %#X\n", pkt.packetFields.sensor);
    printf("binary val = ");
    print_binary(pkt.packetFields.sensor);
    printf("\n");

    printf("\nlongAddr = %#X\n", pkt.packetFields.longAddr);
    printf("binary val = ");
    print_binary(pkt.packetFields.longAddr);
    printf("\n");

    printf("\nshortAddr = %#X\n", pkt.packetFields.shortAddr);
    printf("binary val = ");
    print_binary(pkt.packetFields.shortAddr);
    printf("\n");

    printf("\naddrMode = %#X\n", pkt.packetFields.addrMode);
    printf("binary val = ");
    print_binary(pkt.packetFields.addrMode);
    printf("\n");

    uint32_t totalSize = sizeof(pkt.packetValue); // 4 bytes
    printf("Size of struct packet = %d bytes\n", totalSize);

    return 0;
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}