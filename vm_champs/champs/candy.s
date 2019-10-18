
.name "Candy"
.comment ""
        st                r1, r12
        ld      %0 , r14
        zjmp    %:base
base:
        xor                r12, r14, r15
        sti                r15, %0, %1
