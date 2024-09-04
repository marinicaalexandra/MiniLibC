// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	int ret = syscall(2, filename, flags);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}

/*
->	Funcția open este o funcție de apel al sistemului (syscall) 
	în limbajul C care este utilizată pentru a deschide un fișier 
	sau a crea unul nou, în funcție de anumite specificații și opțiuni.
->	const char *filename: Acesta este un pointer către un șir de caractere 
	care specifică numele fișierului pe care doriți să îl deschideți sau să îl creați.
->	int flags: Acesta este un set de flag-uri (indicatori) care specifică modul în care 
	fișierul trebuie deschis. Aceste flag-uri pot indica modul de acces (cum ar fi citire 
	sau scriere) sau alte opțiuni specifice ale deschiderii fișierului.
->	Funcția open returnează un descriptor de fișier, care este un număr întreg care 
	identifică fișierul deschis. Dacă deschiderea fișierului a eșuat, funcția open returnează 
	de obicei -1 și setează variabila globală errno pentru a indica cauza eșecului.
*/
