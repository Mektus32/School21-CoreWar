.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

		ld   %0,r3
label:		zjmp %:avantdebut
		zjmp %0				# de l'instruction suivante
code:		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		live %42			# 5
		sti  r15,%0,r14			# 6

		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		sti  r15,%0,r14			# 6
		zjmp %-200

avantdebut:	sti   r1,%:code,%1  # 		#7	
		sti   r1,%:code,%15 # 		#7	
		sti   r1,%:code,%29 # 		#7	
		sti   r1,%:code,%43 # 		#7	
		sti   r1,%:code,%57 # 		#7	
		sti   r1,%:code,%71 # 		#7	
init:		ld   %393216,r4		 	#7	
		ld   %917504,r12		#7	
		ld   %1,r11			#7
		ld   %6,r10			#7
debut:		live %42			#5
		add  r4,r12,r4			#5	
		sub  r10,r11,r10		#5
		zjmp %:init			#3
		fork %:debut			



Introducing contestants...
* Player 1, weighing 156 bytes, "Celebration Funebre v0.99pl42" ("Jour J") !
0x0000 : 02 90 00 00 00 00 03 09 00 3a 09 00 00 01 ff ff ff ff 0b 64 0f 00 00 0e 09 ff 38 01 ff ff ff ff 0b 64 0f 00 00 0e 0b 64 0f 00 ff ff ff ff 38 0b 64 0f 00 00 0e 09 ff 38 ff ff ff ff 00 0e 09 ff 
0x0040 : 38 0b 68 01 ff cc ff ff ff ff 01 ff c5 00 0f 0b 68 01 ff be ff ff ff ff 01 ff b7 00 2b 0b 68 01 ff b0 00 39 0b 68 01 ff a9 00 47 02 90 00 06 00 00 04 02 90 00 0e 00 00 0c 02 90 00 00 00 01 0b 
0x0080 : 02 90 00 00 00 06 0a 01 00 00 00 2a 04 54 04 0c 04 05 54 0a 0b 0a 09 ff d5 0c ff ee 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x00c0 : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 

