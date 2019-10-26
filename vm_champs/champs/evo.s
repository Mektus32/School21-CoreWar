.name       "Celebration Funebre v0.99pl42"
.comment    "Jour J"
# ls - 5 cicle
# st - 5 cicle

#sub r2, r2, r2

start:
        # st r1, 11
        # ld 6, r10
        # live %0
        # st r10, 6
         live %0
        # ld %507, r3
        fork %:start

