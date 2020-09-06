#include "decompiler.h"

static enum
{
    OPCODE_GROUP_0 = 0x00,
    OPCODE_GROUP_4 = 0x04,
    OPCODE_GROUP_5 = 0x05,
    OPCODE_GROUP_6 = 0x06,
    OPCODE_GROUP_7 = 0x07,
    OPCODE_GROUP_8 = 0x08,
    OPCODE_GROUP_9 = 0x09,
    OPCODE_GROUP_B = 0x0b,
    OPCODE_GROUP_C = 0x0c,
    OPCODE_GROUP_D = 0x0d,
    OPCODE_GROUP_E = 0x0e
};

instruction_t dmp_decompile_instruction(uint16_t ins)
{
    uint8_t root = (ins >> 12) & 0x000f;
    instruction_t rst;
    switch (ins)
    {
    case 0x003c:
        rst.mnemonic = ORI_TO_CCR;
        break;
    case 0x007c:
        rst.mnemonic = ORI_TO_SR;
        break;
    case 0x023c: 
        break;
    default:
        break;
    }
    switch (root)
    {
    case OPCODE_GROUP_0:
        switch (ins)
        {
        case 0x003c:
            rst.mnemonic = ORI_TO_CCR;
            break;
        case 0x007c:
            rst.mnemonic = ORI_TO_SR;
            break;
            
        default:
            root = (ins & 0x0f00) >> 8;
            break;
        }
        break;
    case OPCODE_GROUP_4:
        break;
    case OPCODE_GROUP_5:
        break;
    case OPCODE_GROUP_6:
        break;
    case OPCODE_GROUP_7:
        break;
    case OPCODE_GROUP_8:
        break;
    case OPCODE_GROUP_9:
        break;
    case OPCODE_GROUP_B:
        break;
    case OPCODE_GROUP_C:
        break;
    case OPCODE_GROUP_D:
        break;
    case OPCODE_GROUP_E:
        break;
    
    default:
        break;
    }
}