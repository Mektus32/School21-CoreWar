.name       "Celebration Funebre v0.99pl42"
.comment    "Jour J"
# ls - 5 cicle
# st - 5 cicle

fork %:two
one:
  ld   0, r2
  ld   0, r3
  ld   0, r4
  ld   0, r5
  ld   0, r6
  live    %0
  st r2, -100
  st r3, -200
  st r4, -300
  st r5, -400
  st r6, -500
  live    %-3
  ld   %10, r6
  ld   %1000, r7
  ld   %888, r8
  ld   %666, r9
  ld   %0, r10
  sub r2, r2, r2
  live    %-1
  #zjmp %:write
 # fork %:two
two:
  sti r2,  %100, %0
  sti r2,  %100, %0
  sti r4,  %100, %0
  sti r8,  %100, %0
  sti r9,  %100, %0
  sti r10, %100, %0
  live    %-2
  ld %50921974, r5
  ld %50921977, r6
  ld %1879113730, r1
  ld %4, r4
  xor r2, r2, r2
  #fork %:two
  zjmp %:one
# sub:
#   sub r2, r2, r2
zjmp %:one
