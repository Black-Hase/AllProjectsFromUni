/* 
 * CS:APP Data Lab 
 * 
 * <Michael V Hasenkamp student ID: 103141934 Identikey miha5997> 
 * Worked with Spencer Kenny
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) // done
{
    /*Demorgans law: This negs the whole statement and switches the tilda of each and the ampersand to an or. The negation of a compliment is the set itself */
    return ~(~x&~y); // what would I do if I could use ~
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) // done
{
     /*int x = 0x55; /*This is the binary 0101 0101  */ 
    /* x<<8; /* now we shift to the left by 8, I assume 8 because I assume we are working with 16 bits */
    /*return x|0x55; /*now we take the shifted x and or it with the original binary 0101 0101 which is 0000 0000 0101 0101 so its is  0000 0000 0101 0101 | 0000 0000 0101 0101 = 0101 0101 0101 0101 */
    //return 0x55555555;
    int x =0x55;
    x = x<<8;
    x= x | 0x55;
    x = x<<8;
    x= x | 0x55;
    x = x<<8;
    x= x | 0x55;
    return x;
    
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) // done
{
  /*  int word = 8; /* set the word to 8 which is a 4 bit binary where as -1 is a 5 bit and we cant start with 5 bits so start with 8 which has the the form 1000 */
 /*   word << 1; /*then shift it by one to result in a 5 bit number 10000 */
    /* 10001 */
  /*return word; */
    
    //return 0xffffffff; 
    int num = 0x0;
    return ~(num);
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) // done
{
  /*  int word = 0xAAAAAAAA;
    int store = word | x;
  return !(~store);
  */
    /* int word = 0xAA;
  word =  word << 8;
    word = word | 0xaa;
     word = word << 8;
    word = word | 0xaa;
     word = word << 8;
    word = word | 0xaa;
    int store = word | x;
    return !(~store); // shrinks it down to either just 1 or just 0+ 3210
    */
      int y =0x55;
    y = y<<8;
    y= y | 0x55;
    y = y<<8;
    y= y | 0x55;
    y = y<<8;
    y= y | 0x55;
    int store = y & x;
    int store2 = y ^ store;
    return !(store2);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) //done
{
   /* int store = 0xAAAAAAAA;
    store = store&x;
    return !(!store);
    */
    int store = 0xaa;
    store = store <<8;
    store = store | 0xaa;
    store = store <<8;
    store = store | 0xaa;
    store = store <<8;
    store = store | 0xaa;
    store = store&x;
    return !(!store);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) //done
{
   /* int mask_n = n;
    int mask_m = m;
    int hexDex = x;
    
    hexDex >> mask_m()
    */
    int nShift =(n<<3);
    int mShift = (m << 3);
    int mask = 0xff;
    mask=(mask << nShift);
    int nByte = (mask &x); // pulls out the nByte from the base
    int mask2=0xff;
    mask2 = (mask2 << mShift);
    int mByte = (mask2 & x);
    mask2 =(mask2&x);
    int combinedMask = (mask | mask2);
    combinedMask = ~combinedMask;
    int combinedMask2 =(combinedMask & x);
    nByte = (nByte >> nShift);
    nByte = (nByte & 0xff);
    nByte =(nByte << mShift);
    mByte = (mByte>> mShift);
    mByte =(mByte & 0xff);
    mByte = (mByte << nShift);
    int result = (combinedMask2 | mByte);
    result = (result | nByte);
    return result;
    
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) 
{
    int mask = 0x80; // creating the mask
    mask = mask << 24; // shifting 
    int xVar = (mask & x); // making a copy
    int yVar = (mask & y); // making a copy
    int check = !(!xVar); // change a 32 bit value into a single bit boolen value
    int check2 = !(!yVar); // same as line above
    int godChecker = !(check ^ check2 ); // so if its both zero or both 1 it will store a 0 but if one is 0 and one is 1 then it will store a 1
    int XY = x+y;
    int weirdoCheck = (mask & XY); // pulls out the most sig bit
    int weirdoChecked = !(!weirdoCheck); // boolen sig bit of either 1 or 0
    int weirdoMeetsXVar = (weirdoChecked ^ check); //exclusive or with value x
    return !(weirdoMeetsXVar & godChecker);
    
  //return 2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) 
{
  //return 2;
     int mask1 = 0x00;
     mask1 = ~mask1 + !x;
    int result = (y & mask1 | z & ~mask1);
    return result;
    
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) 
{
  //return 2;
    int number = 0x30;
    int number2 = 0x39;
    int store = x + (~(number)+1); // this switches the 1s and zeros and by adding 1 it turns it into its negative number. This is twos compliment
    int store1 = number2 + ((~x)+1);
    int mask = 0x80; // used to pull out the most sig. bit
    mask = mask << 24;
    int storeSig = mask & store; // this pulls out the most sig
    int store1Sig = mask & store1; 
    return !(storeSig | store1Sig); // are either of these 1s if yes then its true we not that true to return false that 
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) 
{
   /* int nShift =(n<<3);
    int mShift = (m << 3);
    int mask = 0xff;
    mask=(mask << nShift);
    int nByte = (mask &x);
    int mask2=0xff;
    mask2 = (mask2 << mShift);
    int mByte = (mask2 & x);
    mask2 =(mask2&x);
    int combinedMask = (mask | mask2);
    combinedMask = ~combinedMask;
    int combinedMask2 =(combinedMask & x);
    nByte = (nByte >> nShift);
    nByte = (nByte & 0xff);
    nByte =(nByte << mShift);
    mByte = (mByte>> mShift);
    mByte =(mByte & 0xff);
    mByte = (mByte << nShift);
    int result = (combinedMask2 | mByte);
    result = (result | nByte);
    return result;
    */
    int nShift = (n<<3); // multiple of 8
    int mask = 0xff;
    mask = (mask << nShift);
    mask = ~(mask); // want to replace the nth byte, so we take off everything thats not changing and we not the mask so it switches it all to ones and creates zeros in the spot we want to stick c into.  
    int addWX = (mask & x); // and that pulls everything out of x but the nth byte will be all zeros
    int cShift = (c<<nShift); // to move the c byte into the correct position
    int result = (cShift | addWX); // this sticks the c inside the correct spot.
    return result;
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) 
{
    int c = 0x55;
    int c2 = c << 8 | c;
    int c3 = c2 << 16 | c2;
    int x =(((x>>1)& c3) | ((x&c3) << 1)); // arithmatic shift b/c it is signed int
    int d = 0x33;
    int d2 = d << 8 | d;
    int d3 = d2 << 16 | d2;
    x =(((x>>2)& d3) | ((x&d3) << 2));
    int e = 0x0f;
    int e2 = e << 8 | e;
    int e3 = e2 << 16 | e2;
    x =(((x>>4)& e3) | ((x&e3) << 4));
    int f = 0x00;
    int h =0xff;
    int f2 = f << 8 | h; // we get 8 zeros at the end then or it with the 8 1s to replace the new zeros with 1
    int f3 = f2 << 16 | h; // by oring it with h you repalce the last 8 zeros with 1 because you have already created 16 zeros
    x =(((x>>8)& f3) | ((x&f3) << 8));
    int g = 0x00;
    int h2 =0xff;
    int g2 = g << 16 | h2;
    int g3 = g2 << 8 | h2; // only with 8 shift because we are already at 24 bits when we shift above
    x =(((x>>16)& g3) | ((x&g3) << 16));
    return x;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
 
}
/*
 *******************************************************************************EXTRA CREDIT***********************************************************
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}

