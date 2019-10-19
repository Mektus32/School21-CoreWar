.name "Jumper !"
.comment "en fait C forker !"

	sti r1,%:livex,%1
livex:	live %66
	fork %:live0
	sti r1,%:boucle,%1
	sti r1,%:boucle,%9
	sti r1,%:boucle,%17
	sti r1,%:boucle,%25
live0:	live %66
boucle:	live %66
	live %66
	fork %:boucle
	live %66
	live %66
