#ifndef STRUCTS_H
#define STRUCTS_H
enum LineTypeSymbols { UNSTROKED = 1, STROKED };
enum ModePlatform { INERT, BODY, EARTH, TRACKING };
struct Voltage
{
    float x = 1.0f;
    float y = 1.0f;
};

#endif // STRUCTS_H
