//
// Created by Lai on 2020/11/7.
//

#include "../util/logUtil.h"
#include "../util/GLUtil.h"
#include "BgDemo.h"
#include <GLES3/gl3.h>


void BgDemo::draw(int screenW, int screenH) {
    //LOGCATE("TriangleSample::Draw");

    if(m_ProgramObj == 0)
        return;

    glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 0.5, 1.0, 1.0);
}

void BgDemo::Init() {
    if (m_ProgramObj != 0) return;

    if(m_ProgramObj != 0)
        return;
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec4 vPosition;  \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vPosition;              \n"
            "gl_PointSize = 50.0; \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
            "}                                            \n";

    LOGCATE("init BgDemo");

    m_ProgramObj =  GLUtil::CreateProgram(vShaderStr, fShaderStr, m_VertexShader, m_FragmentShader);
}


void BgDemo::OnSurfaceChanged(int width, int height) {
    LOGCATE("MyGLRenderContext::OnSurfaceChanged [w, h] = [%d, %d]", width, height);
    glViewport(0, 0, width, height);
}


