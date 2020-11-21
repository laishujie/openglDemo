//
// Created by Lai on 2020/11/20.
//

#ifndef OPENGLDEMO_TRIANGLEDEMOVAO_H
#define OPENGLDEMO_TRIANGLEDEMOVAO_H

#include <GLES3/gl3.h>

class TriangleDemoVAO {

public:
    TriangleDemoVAO() {
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
    unsigned int triangleVBO;
    unsigned int lineVBO;
    unsigned  int triangleVAO;
    unsigned  int lineVAO;

};


#endif //OPENGLDEMO_TRIANGLEDEMOVAO_H
