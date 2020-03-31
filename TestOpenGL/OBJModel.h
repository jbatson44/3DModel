#pragma once
#include <vector>
class OBJModel
{
    struct vertex {
        double x;
        double y;
        double z;
    };
    struct face {
        unsigned int v1, v2, v3;
    };
    std::vector<vertex> vertices;
    std::vector<face> faces;

public:
    void readfile(const char* filename);
    void draw();
};

