a =. 1!:1 <'.\day 2\input.txt'              NB. read input
a =. ".&.> (3 * i.1000) { ;: a              NB. convert to array of numbers
a =. 2 (-/;._3)&.> a                        NB. compute change in level
a =. (#~ -.@(0&e.@>)) a                     NB. remove reports including no change in level
a =. (#~ ([: 1&=@#@:~. *)@>) a              NB. remove reports with both increasing and decreasing levels
a =. (#~ ([: (1&<: *./@:*. 3&>:) |)@>) a    NB. remove reports with change in level greater than 3 and less than 1
result =. # a
 
result