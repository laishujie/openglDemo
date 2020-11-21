//
// Created by Lai on 2020/11/15.
//

#include "TriangleDemoVBO.h"

#include "../util/logUtil.h"
#include "../util/GLUtil.h"
#include <GLES3/gl3.h>


void TriangleDemoVBO::draw(int screenW, int screenH) {
    //LOGCATE("TriangleSample::Draw");

    GLfloat triangleVertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
    };;
    GLfloat lineVertices[]= {
            -1.0f, 0.0f, 0.0f,
            1.0, -0, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
    };

    if(m_ProgramObj == 0)
        return;

    glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Use the program object
    glUseProgram (m_ProgramObj);

    // Load the vertex data


    //绑定对象 GL_ARRAY_BUFFER：可以用来保存glVertexAttribPointer()设置的顶点数组数据
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    //为当前VBO塞点数据 GL_STATIC_DRAW 表示数据不会或几乎不会改变。
    glBufferData(GL_ARRAY_BUFFER, sizeof(lineVertices), lineVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_LINES, 0, 4);


    //绑定对象 GL_ARRAY_BUFFER：可以用来保存glVertexAttribPointer()设置的顶点数组数据
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
    //为当前VBO塞点数据 GL_STATIC_DRAW 表示数据不会或几乎不会改变。
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glEnableVertexAttribArray(0);

    glUseProgram (GL_NONE);
}

void TriangleDemoVBO::Init() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

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
            "   fragColor = vec4 ( 0.0, 0.0, 0.0, 1);  \n"
            "}                                            \n";

    LOGCATE("init TriangleDemoVBO");

    m_ProgramObj = GLUtil::CreateProgram(vShaderStr, fShaderStr, m_VertexShader, m_FragmentShader);
    //创建对象
    glGenBuffers(1, &triangleVBO);
    glGenBuffers(1, &lineVBO);

}


void TriangleDemoVBO::OnSurfaceChanged(int width, int height) {
    LOGCATE("MyGLRenderContext::OnSurfaceChanged [w, h] = [%d, %d]", width, height);
    glViewport(0, 0, width, height);
}
