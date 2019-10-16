.name                "Celebration Funebre v0.99pl42"
.comment        "Jour J"

# ls - 5 cicle
# st - 5 cicle
        ld   0, r2
        ld   0, r3
        ld   0, r4
        ld   0, r5
        ld   0, r6

   #     st r2, r6
    #    st r3, r7
     #   st r4, r8
      #  st r5, r9
       # st r6, r10

        ld   %111, r6
        ld   %222, r7
        ld   %333, r8
        ld   %555, r9
        ld   %555, r10

        sti r6,  %-100, %0
        sti r7,  %-100, %0
      sti r8,  %-100, %0
        sti r9,  %-100, %0
    sti r10, %-100, %0
