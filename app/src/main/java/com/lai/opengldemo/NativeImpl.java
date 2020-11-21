package com.lai.opengldemo;

/**
 * @author Lai
 * @time 2020/11/7 17:41
 * @describe describe
 */
public class NativeImpl {
    static {
        System.loadLibrary("native-lib");
    }
    public static native String stringFromJNI();


    public static native void  init();


    public static native void OnSurfaceChanged(int width,int height);
    public static native void draw(int width,int height);

}
