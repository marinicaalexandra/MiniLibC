// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	char *destaux = destination;
    do {
		*destaux = *source;
		destaux++;
		source++;
	} while (*source != '\0');
	*destaux = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	if (destination == NULL || source == NULL || len == 0) {
        return destination;
    }

	for( int i = len; i >= 0 && (*destination = *source) != '\0'; i-- )
		{
			destination++;
			source++;
		}

	for( int i = len; i >= 0 ; i-- )
		{
			*destination = '\0';
			destination++;
		}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	char *destaux = destination;
    while (*destaux != '\0') {
        destaux++;
    }
    // Copiez caractere de la sursa la destinatie
    while (*source != '\0') {
        *destaux = *source;
        destaux++;
        source++;
    }
    *destaux = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	char *destaux = destination;
    //Muta pointerul destinatie la finalul stringului
    while (*destaux != '\0') {
        destaux++;
    }

    // Cpoiaza un numar de caractere de la sursa la destinatie
	for ( int i = len; i > 0 ; i-- )
		if( *source != '\0' )
			{
				*destaux = *source;
        		destaux++;
        		source++;
			}

    *destaux = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	do {
    	str1++;
    	str2++;
	} while (*str1 != '\0' && *str1 == *str2);

	if(*str1 > *str2)
		return 1;

	if(*str1 == *str2)
		return 0;

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	do {
		str1++;
		str2++;
		len--;
	} while (len > 0 && *str1 != '\0' && *str1 == *str2);

	if (len == 0) {
        return 0;  //Primele len caractere sunt egale
    } else {
        return (*str1 - *str2);
    }

	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

    for (i = 0; *str != '\0'; i++) {
        str++;
    }

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while (*str != '\0') {
        if (*str == c) {
            return (char *)str;  // Intorc pointerul la caracterul găsit
        }
        str++;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	const char *last = NULL;

    while (*str != '\0') {
        if (*str == c) {
            last = str;
        }
        str++;
    }

    if (c == '\0') {
        return (char *)str;
    }

    return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len == 0) {
        return (char *)haystack;  // Dacă șirul căutat este gol, întoarce pointerul la începutul lui haystack
    }

    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        if (strncmp(haystack + i, needle, needle_len) == 0) {
            return (char *)(haystack + i);  // S-a găsit needle, întoarce pointerul la începutul lui haystack + i
        }
    }

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len == 0) {
        return (char *)(haystack + haystack_len);
    }

    for (size_t i = haystack_len; i >= needle_len; i--) {
        if (strncmp(haystack + i - needle_len, needle, needle_len) == 0) {
            return (char *)(haystack + i - needle_len);
        }
    }

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	char *destaux = (char *)destination;
    const char *src = (const char *)source;

    if (destaux == src) {
        return destination;
    }

    if (destaux < src) {
        for (size_t i = 0; i < num; i++) {
            destaux[i] = src[i];
        }
    } else if (destaux > src) {
        for (size_t i = num; i > 0; i--) {
            destaux[i - 1] = src[i - 1];
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */

	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++)
        if (p1[i] < p2[i])
            return (int)(p1[i] - p2[i]);

    return 0;  // ptr1 este egal cu ptr2
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	unsigned char *p = (unsigned char *)source;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }


	return source;
}
