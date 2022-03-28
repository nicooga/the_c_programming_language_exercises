> Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
> in x. Explain why. Use this observation to write a faster version of bitcount.

Subtraction algorithm works the same in any base.
So I'm going to use base ten to explain this, as its mechanics are greatly familiar to me.

Whenever we subtract 1 from a number, it's a matter of decreasing the last digit by 1.

```
 123
-  1
 ---
 122
```

This may not be possible if the first digit is 0. This is where "borrowing" logic comes in.

```
 1234000
-      1
 -------
       ?
```

We can borrow 1 from the digit to the left. The digit to the left is worth 10 times more, and that's the amount we are borrowing. The current digit becomes the borrowed amount, 10, minus one.

If the digit to the left is zero too, we repeat the borrow procedure, until we find a non-zero digit.

```
+            10 10 10
-          1  1  1 
  1  2  3  4  0  0  0
-                   1
  -------------------
  1  2  3  3  9  9  9
```

Whenever we subtract 1 from a number that has a sequence of zeroes at the end, we obtain a new number that has a sequence of nines at the end.

This same phenomenom happens in base two. Whenever we subract 1 from a binary number that ends in 1 we just erase the last bit.

```
 100001
-     1
 ------
 100000
```

However, if the last digit is zero, we beed to borrow 2 from the digit to the left.

```
+   22222
-  11111
 10100000
-       1
 --------
 10011111
```

The logic is the same as with base ten. But because the base is two, we get ones (base - 1) instead of nines.

Then, `AND`ing x and x-1 does the following:

- upto the last 1-bit in x ANDs equal bits, leaving them untouched
- from the last 1-bit and forwards it ANDs ones and zeroes, which produces zeroes

For instance:

```
x   =>   10101000
x-1 => & 10100111
         --------
         10100000
```

This shows why `x & (x-1)` erases the last 1-bit.