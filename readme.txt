
Igra:
	- Game Loop
	- Sva Logika

Ploca:
	- Alokacija ploce za igru

Igrac:
	- Pozicija
	- Kretnje - Lijevo, Desno
	- Pucanje
	- Score

Enemy:
	- Pozicija
	- Kretnje - (Korak Dolje)

Igra Space Invaders sadrži biblioteku "windows.h" s kojom je moguce registrirati
pritisnutu tipku na tipkovnici nakon koje dolazi do reakcije na ekranu. Naš
igrač("W") se može kretati lijevo (tipka "<-" na tipkovnici) i desno (tipka "->"
na tipkovnici) do širine ploče za igru. Tipkom "Space" se ispaljuje metak koji
uklanja neprijatelje("Y") s ploče. Nakon što metak pogodi neprijatelja ili rub ploče
tada se svi neprijatelji pomaknu jedan red prema našem igraču. Ukoliko neprijatelj
uspije doći do reda igrača tada je igra gotova. Ukoliko igrač uspješno ukloni
svih 10 neprijatelja, na ekranu se ispuje poruka o pobjedi.
