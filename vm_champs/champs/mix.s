.name       "Celebration Funebre v0.99pl42"
.comment    "Jour J"
# ls - 5 cicle
# st - 5 cicle
                ld   %0,r3              
label:          zjmp %:avantdebut
                zjmp %0                         # pour eviter ecrasement
                                                # de l'instruction suivante
code:           #live %42                        # 5
                sti  r15,%0,r14                 # 6
                zjmp %-200                      # 3
                #live %42                        # 5
                sti  r15,%0,r14                 # 6
                zjmp %-200                      # 3
                #live %42                        # 5
                sti  r15,%0,r14                 # 6
                zjmp %-200                      # 3
                #live %42                        # 5
                sti  r15,%0,r14                 # 6
                zjmp %-200                      # 3
                sti  r15,%0,r14                 # 6
                zjmp %-200                      # 3
                sti  r15,%0,r14                 # 6
                zjmp %-200
        
avantdebut:     sti   r1,%:code,%1  #           #7      
                sti   r1,%:code,%15 #           #7      
                sti   r1,%:code,%29 #           #7      
                sti   r1,%:code,%43 #           #7      
                sti   r1,%:code,%57 #           #7      
                sti   r1,%:code,%71 #           #7      
init:           ld   %393216,r4                 #7      
                ld   %917504,r12                #7      
                ld   %1,r11                     #7
                ld   %6,r10                     #7
debut:          #live %42                        #5
                sti  r4,%:label , %1            #7
                add  r4,r12,r4                  #5      
                sub  r10,r11,r10                #5
                zjmp %:init                     #3
                fork %:debut                    
                #live %3
level0:         fork %:level10
level11:        live %4
                fork %:level111

level110:       #live %42
                ldi  %8, %:code, r15            #set des octets 9-12
                ld   %-186, r14                 #=$A-6-8
                ld   %0,r2
                zjmp  %:label
                        
level10:        live %42
                fork %:level100
level101:       #live %42
                ldi  %4, %:code, r15            #set des octets 5-8
                ld   %-190, r14                 #=$A-6-4
                ld   %0,r2
                zjmp %:label
                
level111:       #live %42        
                ldi  %12, %:code, r15           #set des octets 13-16
                ld   %-182, r14                 # $A -6 -12
                ld   %0,r2
                zjmp %:label
                
level100:       #live %42
                ldi  %0, %:code, r15            #set des octets 1-4
                ld   %-194, r14                 # $A -6 -0
                ld   %0,r2                      #
                zjmp %:label                    #

# start:
#     ld   %777, r3
#     ldi  %:one, %8968, r15
#     ldi  r3, %:one, r14
# two:
#   ld %50921974, r5
#   ld %50921977, r6
#   ld %1879113730, r1
#   ld %4, r4
#   xor r2, r2, r2
#   sub r2, r2, r2
# one:
#   ld   %666, r2
#     ld   %666, r2

#    st r15, -500
#    sti r15,%0,r14
#    sti r14,%:two,r14
#   ld   777, r3
#   ld   -8888, r4
#   ld   0, r5
#   ld   0, r6
#   live    %1000
#   st r2, -100
#   st r3, -200
#   st r4, -300
#   st r5, r4
#   st r6, -500
#   live    %-3
#   ld   %10, r6
#   ld   %1000, r7
#   ld   %888, r8
#   ld   %666, r9
#   ld   %0, r10
#   sub r2, r2, r2
#   live    %-1
#   sti r2,  %100, %0
#   sti r5,  %100, %1800
#   sti r4,  %100, %60000
#   sti r8,  %100, %-54560
#   sti r9,  %100, r2
#   sti r10, %100, r9
#   sti r1, %100, r5
#   sti r14, %100, %2100
#   live    %-2

