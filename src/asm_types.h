#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

typedef enum mnemonic_t
{
    ORI_TO_CCR,
    ORI_TO_SR,
    ORI,

    ANDI_TO_CCR,
    ANDI_TO_SR,
    ANDI,

    SUBI,
    ADDI,

    EORI_TO_CCR,
    EORI_TO_SR,
    EORI,

    CMPI,
    BTST,
    BCHG,
    BCLR,
    BSET,
    BTST,

    MOVEP,
    MOVEA,
    MOVE,
    MOVE_FROM_SR,
    MOVE_TO_CCR,

    NEGX,
    CLR,
    NEG,
    NOT,
    EXT,
    NBCD,
    SWAP,
    PEA,
    ILLEGAL,
    TAS,
    TST,
    TRAP,
    LINK,
    UNLK,
    MOVE_USP,
    RESET,
    NOP,
    STOP,

    RTE,
    RTS,
    TRAPV,
    RTR,
    JSR,
    JMP,
    MOVEM,
    LEA,
    CHK,
    ADDW,
    SUBQ,
    SCC,
    DBCC,
    BRA,
    BSR,
    BCC,
    MOVEQ,
    
    DIVU,
    DIVS,
    
    SBCD,
    OR,
    
    SUB,
    SUBX,
    SUBA,

    EOR,

    CMPM,
    CMP,
    CMPA,

    MULU,
    MULS,

    ABCD,
    EXG,
    AND,

    ADD,
    ADDX,
    ADDA,

    ASD,
    LSD,
    ROXD,
    ROD,
    ASD,
    LSD,
    ROXD,
} mnemonic_t;

typedef union asm_val_t 
{
    unsigned short  nybble;
    uint8_t         byte;
    uint16_t        word;
    uint32_t        long_word;
} asm_val_t;

typedef enum asm_size_t
{
    byte_s,
    word_s,
    long_word_s
} asm_size_t;

typedef struct instruction_t
{
    mnemonic_t      mnemonic;
    asm_val_t       source;
    asm_size_t      destination;
    asm_size_t      size;
} instruction_t;