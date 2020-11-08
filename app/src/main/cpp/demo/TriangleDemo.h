//
// Created by Lai on 2020/11/7.
//

#ifndef OPENGLDEMO_TRIANGLEDEMO_H
#define OPENGLDEMO_TRIANGLEDEMO_H


#include <GLES3/gl3.h>

class TriangleDemo {
public:
    TriangleDemo(){
        m_ProgramObj = 0;
        m_VertexShader = 0;
        m_FragmentShader = 0;
    };
    void Init();
    void draw(int screenW, int screenH);
    void OnSurfaceChanged(int width, int height);

    GLuint m_ProgramObj;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
};


#endif //OPENGLDEMO_TRIANGLEDEMO_H
