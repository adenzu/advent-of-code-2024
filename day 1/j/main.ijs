a =. 1!:1 <'.\day 1\input.txt'      NB. read input
a =. ". > (3 * i.1000) { ;: a       NB. convert to array of numbers
a =. |: /:~"_1 |: a                 NB. sort column-wise
result =. +/ | -/"1 a               NB. sum of absolute differences

result