#include <jni.h>
#include <string>
#include <TriangleDemoVAO.h>
#include <TriangleDemo.h>
#include <BgDemo.h>

TriangleDemoVAO *triangleDemo = NULL;

extern "C" JNIEXPORT jstring JNICALL
Java_com_lai_opengldemo_NativeImpl_stringFromJNI(
        JNIEnv *env,
        jclass clazz) {
    std::string hello = "Hello NativeImpl from C++";

    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT void JNICALL
Java_com_lai_opengldemo_NativeImpl_init(JNIEnv *env, jclass instance) {
    if (triangleDemo == NULL) {
        triangleDemo = new TriangleDemoVAO();
    }
    triangleDemo ->Init();
}
extern "C" JNIEXPORT void JNICALL
Java_com_lai_opengldemo_NativeImpl_OnSurfaceChanged(JNIEnv *env, jclass instance,jint width, jint height) {
    triangleDemo->OnSurfaceChanged(width,height);
}
extern "C" JNIEXPORT void JNICALL
Java_com_lai_opengldemo_NativeImpl_draw(JNIEnv *env, jclass instance,jint width, jint height) {
    triangleDemo->draw(width,height);
}



