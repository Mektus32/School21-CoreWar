.name       "Batman"
.comment    "This city needs me"
live:
    live %0
    ld %-1, r2
    zjmp %:loop
    live %0
    live %0
    live %0
    live %0
    live %0
    live %0
    live %0
loop:
    sti r2, %:live, %0
