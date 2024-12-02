a =. 1!:1 <'.\day 1\input.txt'          NB. read input
a =. ". > (3 * i.1000) { ;: a           NB. convert to array of numbers
a1 =. {. |: a                           NB. first row
a2 =. {: |: a                           NB. second row
result =. +/ a1 * a1 (+/@:=)"0 _ a2     NB. sum of found matches

result