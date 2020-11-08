package com.lai.opengldemo

import android.opengl.GLSurfaceView
import android.opengl.GLSurfaceView.RENDERMODE_CONTINUOUSLY
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        gl_surface.setEGLContextClientVersion(2)
        gl_surface.setRenderer(object :GLSurfaceView.Renderer{
            override fun onDrawFrame(gl: GL10?) {
                NativeImpl.draw(0,0);
            }

            override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
                NativeImpl.OnSurfaceChanged(width,height)
            }

            override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
                NativeImpl.init()
            }

        });
        gl_surface.renderMode = RENDERMODE_CONTINUOUSLY
    }

}
