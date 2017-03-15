/* 
/ The method "fast_numeric_read" perform a fast (the fastest? not know :)) number reading from standard input. 
/ It is highly recommend to turn off ios_base sync with the following line:
/ std::ios_base::sync_with_stdio(0);
/ Warning: use only in one-threaded application.
*/

#define EOF_CHAR (-49)
#define NEW_LINE 10
#define MINUS_SIGN_MOD (-3)

#ifdef __linux__ 
#define getchar_custom fgetc_unlocked
#elif _WIN32
#define getchar_custom _fgetc_nolock
#endif

template<typename T>
inline T read_number(bool* end, int * lastChar) {

	register int read = getchar_custom(stdin) - 48;

	while ((read < 0 || read > 9)
		&& read != EOF_CHAR
		&& read != MINUS_SIGN_MOD) {
		read = getchar_custom(stdin) - 48;
	}

	if (read == EOF_CHAR) {
		(*end) = true;
		return -1;
	}

	int signModifier = 1;
	if (read == MINUS_SIGN_MOD) {
		signModifier = -1;
		read = getchar_custom(stdin) - 48;
	}

	T returnValue = 0;

	while (read >= 0 && read <= 9) {
		returnValue = (returnValue << 3) + (returnValue << 1) + read;
		read = getchar_custom(stdin) - 48;
	}

	(*lastChar) = read + 48;
	(*end) = false;
	return returnValue * signModifier;
}


template<typename T>
inline  T read_number(bool* end) {
	int lastChar;
	return read_number<T>(end, &lastChar);
}


template<typename T>
inline  T read_number() {
	bool end;
	return read_number<T>(&end);
}