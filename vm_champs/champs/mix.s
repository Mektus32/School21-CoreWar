.name       "Celebration Funebre v0.99pl42"
.comment    "Jour J"
# ls - 5 cicle
# st - 5 cicle
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
  live    %-1
  sti r6,  %100, %0
  sti r7,  %100, %0
  sti r8,  %100, %0
  sti r9,  %100, %0
  sti r10, %100, %0
  live    %-2
