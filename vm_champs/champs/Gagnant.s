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
		zjmp %-200			# 3
		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		live %42			# 5
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
		live %3
