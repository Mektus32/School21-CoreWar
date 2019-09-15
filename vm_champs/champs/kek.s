.name		"kek1"
.comment	"Jour J"

		ld   %0,r3		
init:		ld   %393216,r4		 	#7	
		ld   %917504,r12		#7	
		ld   %1,r11			#7
		ld   %6,r10			#7
debut:		live %42			#5
		add  r4,r12,r4			#5	
		sub  r10,r11,r10		#5
		live %3

level11:	live %4

level110:	live %42
		ld   %-186, r14			#=$A-6-8
		ld   %0,r2
			
level101:	live %42
		ld   %-190, r14			#=$A-6-4
		ld   %0,r2
		
level111:	live %42	
		ld   %-182, r14			# $A -6 -12
		ld   %0,r2
		
level100:	live %42
		ld   %-194, r14			# $A -6 -0
		ld   %0,r2			#
