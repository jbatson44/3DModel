#include "OBJModel.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
using namespace std;

void formatFace(string& face);

void OBJModel::readfile(const char* filename)
{
    string s;
    //cout << "bro";
    
    ifstream fin(filename);
    if (!fin)
        return;
    string line;
    int count = 0;
    while (getline(fin, line))
    {
        //cout << count << endl;
        stringstream ss(line);
        string element;
        ss >> element;
        if (element == "v")
        {
            vertex v;
            ss >> v.x >> v.y >> v.z;
            this->vertices.push_back(v);
           // cout << "vertex : " << v.x << " " << v.y << " " << v.z << "\n";
        }
        else if (element == "vn")
        {
            //cout << "vertex normal\n";
        }
        else if (element == "f")
        {
            face f;
            string one;
            string two;
            string three;
            ss >> one >> two >> three;
           // cout << one << " " << two << " " << three << endl;
            
            //string s = "scott>=tiger";
            //string delimiter = ">=";
            //string token = s.substr(0, s.find(delimiter));
            formatFace(one);
            formatFace(two);
            formatFace(three);
            stringstream s1(one);
            stringstream s2(two);
            stringstream s3(three);
            /*cout << one << endl;
            cout << two << endl;
            cout << three << endl;*/
            
            s1 >> f.v1;
            s2 >> f.v2;
            s3 >> f.v3;
            
            //f.v1 = one[0] - '0';
            //f.v2 = two[0] - '0';
            //f.v3 = three[0] - '0';
            faces.push_back(f);
           // cout << "face: " << f.v1 << " " << f.v2 << " " << f.v3 << "\n";
        }
        count++;
    }
    /*while (fin >> s)
    {
        cout << "zzzzzzzz";
        switch (*s.c_str())
        {
        case 'v':
        {
            vertex v;
            fin >> v.x >> v.y >> v.z;
            this->vertices.push_back(v);
        }
        break;
        case 'f':
        {
            face f;
            fin >> f.v1 >> f.v2 >> f.v3;
            faces.push_back(f);
        }
        break;
        }
    }*/
    //cout << "ending";
}

void OBJModel::draw()
{
    cout << "drawing model\n";
    //cout << faces.size() << endl;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < faces.size(); i++)
    {
        
        vertex v1 = vertices[faces[i].v1 - 1];
        vertex v2 = vertices[faces[i].v2 - 1];
        vertex v3 = vertices[faces[i].v3 - 1];
        //cout << "(" << v1.x << "," << v1.y << "," << v1.z << ")\n";
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(v1.x, v1.y, v1.z);
        glVertex3f(v2.x, v2.y, v2.z);
        glVertex3f(v3.x, v3.y, v3.z);
    }
    glEnd();
}

void formatFace(string& face)
{
    for (int i = 0; i < face.size(); i++)
    {
        if (face[i] == '/')
        {
            face[i] = ' ';
        }

    }
}