#ifndef STRUCTS_H
#define STRUCTS_H

enum LineTypeSymbols { UNSTROKED = 1, STROKED };
enum ModePlatform { INERT, BODY, EARTH, TRACKING };
enum Result {S_OK, S_FAIL, S_FAIL_OFFSET};

struct Voltage
{
    float x = 1.0f;
    float y = 1.0f;
};

#endif // STRUCTS_H
