//
// Created by Lai on 2020/11/21.
//

#ifndef OPENGLDEMO_BGDEMO_H
#define OPENGLDEMO_BGDEMO_H
#include <GLES3/gl3.h>


class BgDemo {
public:
    BgDemo(){
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


#endif //OPENGLDEMO_BGDEMO_H
