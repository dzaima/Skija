#include <iostream>
#include <jni.h>
#include "SkShader.h"
#include "SkGradientShader.h"
#include "interop.hh"

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Shader_nMakeLinearGradient(JNIEnv* env, jclass jclass, jfloat x0, jfloat y0, jfloat x1, jfloat y1, jintArray colorsArray, jfloatArray posArray, jint tileModeInt) {
    int* colors = env->GetIntArrayElements(colorsArray, nullptr);
    float* pos = posArray == nullptr ? nullptr : env->GetFloatArrayElements(posArray, nullptr);
    SkTileMode tileMode = static_cast<SkTileMode>(tileModeInt);
    SkPoint pts[2] { SkPoint::Make(x0, y0), SkPoint::Make(x1, y1) };
    SkShader* ptr = SkGradientShader::MakeLinear(pts, reinterpret_cast<SkColor*>(colors), pos, env->GetArrayLength(colorsArray), tileMode).release();
    env->ReleaseIntArrayElements(colorsArray, colors, 0);
    if (posArray != nullptr)
        env->ReleaseFloatArrayElements(posArray, pos, 0);
    return reinterpret_cast<jlong>(ptr);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Shader_nMakeRadialGradient(JNIEnv* env, jclass jclass, jfloat x, jfloat y, jfloat r, jintArray colorsArray, jfloatArray posArray, jint tileModeInt) {
    int* colors = env->GetIntArrayElements(colorsArray, nullptr);
    float* pos = posArray == nullptr ? nullptr : env->GetFloatArrayElements(posArray, nullptr);
    SkTileMode tileMode = static_cast<SkTileMode>(tileModeInt);
    SkShader* ptr = SkGradientShader::MakeRadial(SkPoint::Make(x, y), r, reinterpret_cast<SkColor*>(colors), pos, env->GetArrayLength(colorsArray), tileMode).release();
    env->ReleaseIntArrayElements(colorsArray, colors, 0);
    if (posArray != nullptr)
        env->ReleaseFloatArrayElements(posArray, pos, 0);
    return reinterpret_cast<jlong>(ptr);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Shader_nMakeTwoPointConicalGradient(JNIEnv* env, jclass jclass, jfloat x0, jfloat y0, jfloat r0, jfloat x1, jfloat y1, jfloat r1, jintArray colorsArray, jfloatArray posArray, jint tileModeInt) {
    int* colors = env->GetIntArrayElements(colorsArray, nullptr);
    float* pos = posArray == nullptr ? nullptr : env->GetFloatArrayElements(posArray, nullptr);
    SkTileMode tileMode = static_cast<SkTileMode>(tileModeInt);
    SkShader* ptr = SkGradientShader::MakeTwoPointConical(SkPoint::Make(x0, y0), r0, SkPoint::Make(x1, y1), r1, reinterpret_cast<SkColor*>(colors), pos, env->GetArrayLength(colorsArray), tileMode).release();
    env->ReleaseIntArrayElements(colorsArray, colors, 0);
    if (posArray != nullptr)
        env->ReleaseFloatArrayElements(posArray, pos, 0);
    return reinterpret_cast<jlong>(ptr);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Shader_nMakeSweepGradient(JNIEnv* env, jclass jclass, jfloat x, jfloat y, jfloat start, jfloat end, jfloat y1, jfloat r1, jintArray colorsArray, jfloatArray posArray, jint tileModeInt) {
    int* colors = env->GetIntArrayElements(colorsArray, nullptr);
    float* pos = posArray == nullptr ? nullptr : env->GetFloatArrayElements(posArray, nullptr);
    SkTileMode tileMode = static_cast<SkTileMode>(tileModeInt);
    SkShader* ptr = SkGradientShader::MakeSweep(x, y, reinterpret_cast<SkColor*>(colors), pos, env->GetArrayLength(colorsArray), tileMode, start, end, 0, nullptr).release();
    env->ReleaseIntArrayElements(colorsArray, colors, 0);
    if (posArray != nullptr)
        env->ReleaseFloatArrayElements(posArray, pos, 0);
    return reinterpret_cast<jlong>(ptr);
}