/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_meshpoint_anode_bridge_BridgeNative */

#ifndef _Included_org_meshpoint_anode_bridge_BridgeNative
#define _Included_org_meshpoint_anode_bridge_BridgeNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    callAsFunction
 * Signature: (J[Lorg/meshpoint/anode/type/IValue;)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_callAsFunction
  (JNIEnv *, jclass, jlong, jobjectArray);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    callAsConstructor
 * Signature: (J[Lorg/meshpoint/anode/type/IValue;)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_callAsConstructor
  (JNIEnv *, jclass, jlong, jobjectArray);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    callMethod
 * Signature: (JLjava/lang/String;[Lorg/meshpoint/anode/type/IValue;)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_callMethod
  (JNIEnv *, jclass, jlong, jstring, jobjectArray);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    getProperty
 * Signature: (JLjava/lang/String;)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_getProperty
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    setProperty
 * Signature: (JLjava/lang/String;Lorg/meshpoint/anode/type/IValue;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_setProperty
  (JNIEnv *, jclass, jlong, jstring, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    deleteProperty
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_deleteProperty
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    containsProperty
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_containsProperty
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    properties
 * Signature: (J)Ljava/util/Collection;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_properties
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    getIndexedProperty
 * Signature: (JI)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_getIndexedProperty
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    setIndexedProperty
 * Signature: (JILorg/meshpoint/anode/type/IValue;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_setIndexedProperty
  (JNIEnv *, jclass, jlong, jint, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    deleteIndexedProperty
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_deleteIndexedProperty
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    containsIndex
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_containsIndex
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    length
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_length
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    callAsInterface
 * Signature: (JII[Lorg/meshpoint/anode/type/IValue;)Lorg/meshpoint/anode/type/IValue;
 */
JNIEXPORT jobject JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_callAsInterface
  (JNIEnv *, jclass, jlong, jint, jint, jobjectArray);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseObjectHandle
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseObjectHandle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    wrapJSObject
 * Signature: (JLorg/meshpoint/anode/js/JSObject;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_wrapJSObject
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    wrapJSInterface
 * Signature: (JLorg/meshpoint/anode/js/JSInterface;Lorg/meshpoint/anode/idl/IDLInterface;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_wrapJSInterface
  (JNIEnv *, jclass, jlong, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    wrapJavaInterface
 * Signature: (Lorg/meshpoint/anode/java/Base;Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_wrapJavaInterface
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindInboundInterface
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindInboundInterface
  (JNIEnv *, jclass, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindOutboundInterface
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindOutboundInterface
  (JNIEnv *, jclass, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindInboundAttribute
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface/Attribute;Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindInboundAttribute
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindOutboundAttribute
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface/Attribute;Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindOutboundAttribute
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindInboundOperation
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface/Operation;Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindInboundOperation
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    bindOutboundOperation
 * Signature: (Lorg/meshpoint/anode/idl/IDLInterface/Operation;Lorg/meshpoint/anode/idl/IDLInterface;)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_bindOutboundOperation
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseOutboundInterface
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseOutboundInterface
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseInboundInterface
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseInboundInterface
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseOutboundAttribute
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseOutboundAttribute
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseInboundAttribute
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseInboundAttribute
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseOutboundOperation
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseOutboundOperation
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    releaseInboundOperation
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_releaseInboundOperation
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    requestEntry
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_requestEntry
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_meshpoint_anode_bridge_BridgeNative
 * Method:    setContext
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_org_meshpoint_anode_bridge_BridgeNative_setContext
  (JNIEnv *, jclass, jobject);

#ifdef __cplusplus
}
#endif
#endif
