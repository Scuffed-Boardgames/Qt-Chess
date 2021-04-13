#ifndef ERROR_H
#define ERROR_H
enum class error {
	//good
	enPassent = -1,
	none = 0,
	//bad
	illegalMove = 1,
	outOfBounds = 2,
	noSelect = 3,
	wrongColour = 4,
	defaultError = 99

};
#endif // !ERROR_H
