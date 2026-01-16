#include "surgery.h"

Surgery::Surgery(bool isFast, int opRoom) : isFast(isFast), opRoom(opRoom)
{}

const bool Surgery::getIsFast() const { return isFast; }

const int Surgery::getOpRoom() const { return opRoom; }